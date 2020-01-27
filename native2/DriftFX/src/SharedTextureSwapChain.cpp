/*
 * Copyright (c) 2019 BestSolution.at and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Christoph Caks <ccaks@bestsolution.at> - initial API and implementation
 */
#include "SharedTextureSwapChain.h"
#include "TransferModeManager.h"

#include "jni/JNISwapChain.h"


#include "prism/PrismBridge.h"

#include <vector>
#include <algorithm>

#include "utils/JNIHelper.h"
#include "utils/Logger.h"

using namespace driftfx;
using namespace internal;


SwapChainImage::SwapChainImage(unsigned int number, SharedTextureSwapChain* swapChain, SharedTexture* texture, ShareData* shareData) :
	texture(texture),
	shareData(shareData),
	number(number) {

	JNIEnv* env = JNIHelper::GetJNIEnv(true);

	//auto surfaceData = swapChain->GetSurfaceData();

	//long surfaceId = -1;
	//long frameId = -1;

	//jobject jSurfaceData = jni::SurfaceData::New(env,
	//	(jfloat)surfaceData.size.x, (jfloat)surfaceData.size.y,
	//	(jfloat)surfaceData.screenScale.x, (jfloat)surfaceData.screenScale.y,
	//	(jfloat)surfaceData.userScale.x, (jfloat)surfaceData.userScale.y, (jint)surfaceData.transferMode);

	std::cout << "Created C SwapChainImage, shareData = " << shareData << std::endl;
	std::cout << " => " << shareData->transferMode << std::endl;

	jobject jImg = jni::SwapChainImage::New(env, (jlong) this, (jlong)shareData, (jint) number);
	jObject = env->NewGlobalRef(jImg);
}

SwapChainImage::~SwapChainImage() {
	texture = nullptr;
}

ShareData* SwapChainImage::GetShareData() {
	return shareData;
}

unsigned int SwapChainImage::GetWidth() {
	return texture->GetSize().x;
}

unsigned int SwapChainImage::GetHeight() {
	return texture->GetSize().y;
}

unsigned int SwapChainImage::GetGLTexture() {
	return texture->GetTexture()->Name();
}

SharedTexture* SwapChainImage::GetSharedTexture() {
	return texture;
}

jobject SwapChainImage::GetJavaObject() {
	return jObject;
}

unsigned int SwapChainImage::Number() {
	return number;
}

SharedTextureSwapChain::SharedTextureSwapChain(NativeSurface* surface, math::Vec2ui size, unsigned int imageCount, TransferModeImpl* transferMode, PresentationHint hint, PresentationMode mode) :
	surface(surface),
	size(size),
	transferMode(transferMode),
	imageCount(imageCount),
	presentationHint(hint),
	presentationMode(mode) {

	surfaceData = surface->GetSurfaceData();

	JNIEnv* env = JNIHelper::GetJNIEnv(true);

	LogInfo("Creating SwapChain");
	for (unsigned int i = 0; i < imageCount; i++) {
		// create shared texture
		SharedTexture* tex = transferMode->CreateSharedTexture(surface->GetContext(), surface->GetFxContext(), size);
		ShareData* shareData = transferMode->CreateShareData(tex);
		SwapChainImage* image = new SwapChainImage(i, this, tex, shareData);

		LogInfo(" * " << image);
		images.push_back(image);
		freeImages.push(image);
	}

	javaSwapChain = env->NewGlobalRef(jni::SwapChain::New(env, (jlong)this, (jint) size.x, (jint) size.y, (jint)transferMode->Id(), (jint)presentationMode, (jint)presentationHint));
}

SharedTextureSwapChain::~SharedTextureSwapChain() {
	JNIEnv* env = JNIHelper::GetJNIEnv(true);
	env->DeleteGlobalRef(javaSwapChain);
}

RenderTarget* SharedTextureSwapChain::Acquire() {
	std::unique_lock<std::mutex> lock(imageMutex);
	std::deque<SwapChainImage*>::iterator it;
	//std::string freeImgs = "[";
	//for (it = freeImages.begin(); it != freeImages.end(); it++) {
	//	auto img = *it;
	//	freeImgs += std::to_string(img->Number()) + " ";
	//}
	//freeImgs += "]";
	LogDebug("Acquire (free: " << freeImages.size() << " / " << images.size() << ") ");
	imageReleased.wait(lock, [this]() { return !freeImages.empty(); });
	SwapChainImage* image = freeImages.front();
	LogDebug("acquired " << image->Number());
	freeImages.pop();
	image->GetSharedTexture()->BeforeRender();
	return image;
}

bool SharedTextureSwapChain::TryAcquire(RenderTarget** target) {
	std::unique_lock<std::mutex> lock(imageMutex);
	if (freeImages.empty()) {
		return false;
	}
	else {
		SwapChainImage* image = freeImages.front();
		freeImages.pop();
		*target = image;
		image->GetSharedTexture()->BeforeRender();
		return true;
	}
}

void SharedTextureSwapChain::Present(RenderTarget* target) {
	SwapChainImage* image = dynamic_cast<SwapChainImage*>(target);

	image->GetSharedTexture()->AfterRender();

	JNIEnv* env = JNIHelper::GetJNIEnv(true);
	std::cout << "Nfo: Presenting " << image << std::endl;
	
	// we cannot present null
	if (image != nullptr) {

		// gl tex dump
		//unsigned int dataSize = target->GetWidth() * target->GetHeight() * 4;
		//void* pointer = malloc(dataSize);
		//glBindTexture(GL_TEXTURE_2D, target->GetGLTexture());
		//glGetTexImage(GL_TEXTURE_2D, 0, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, pointer);
		//glBindTexture(GL_TEXTURE_2D, 0);

		//std::string name = "after-gl-" + std::to_string(target->GetGLTexture()) + ".raw";

		//auto fp = fopen(name.c_str(), "w");
		//fwrite(pointer, dataSize, 1, fp);
		//fclose(fp);

		//unsigned char* pixels = (unsigned char*) malloc(dataSize);

		//glBindTexture(GL_TEXTURE_2D, target->GetGLTexture());
		//glGetTexImage(GL_TEXTURE_2D, 0, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, pixels);
		//glBindTexture(GL_TEXTURE_2D, 0);
		//LogDebug("GL: " << std::hex << (int)pixels[0] << "|" << (int)pixels[1] << "|" << (int) pixels[2]);
		//free(pixels);

		jni::SwapChain::Present(env, javaSwapChain, image->GetJavaObject());

		//auto surfaceData = frame->GetSurfaceData();

		//jobject jSurfaceData = jni::SurfaceData::New(env,
		//	(jfloat)surfaceData.size.x, (jfloat)surfaceData.size.y,
		//	(jfloat)surfaceData.screenScale.x, (jfloat)surfaceData.screenScale.y,
		//	(jfloat)surfaceData.userScale.x, (jfloat)surfaceData.userScale.y, (jint)surfaceData.transferMode);

		//jobject jFrame = jni::Frame::New(env, frame->GetSurfaceId(), frame->GetFrameId(), frame->GetWidth(), frame->GetHeight(), jSurfaceData, frame->GetPresentationHint());

		//jni::SwapChain::Present(env, javaSwapChain, jFrame);
	}
}


void SharedTextureSwapChain::Release(RenderTarget* target) {
	SwapChainImage* image = dynamic_cast<SwapChainImage*>(target);
	LogDebug("Release " << image->Number());
	//std::cout << "Nfo: Releasing " << image << std::endl;
	std::unique_lock<std::mutex> lock(imageMutex);
	auto begin = images.begin();
	auto end = images.end();
	auto found = std::find(begin, end, image);
	auto isFound = found != end;

	if (std::find(images.begin(), images.end(), image) != images.end()) {
		freeImages.push(image);
		imageReleased.notify_one();
	}
	else {
		std::cout << "Warn: Cannot release a foreign image " << image << std::endl;
	}
	
}

PresentationHint SharedTextureSwapChain::GetPresentationHint() {
	return presentationHint;
}

SurfaceData SharedTextureSwapChain::GetSurfaceData() {
	return surface->GetSurfaceData();
}

jobject SharedTextureSwapChain::GetJavaObject() {
	return javaSwapChain;
}


extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_SwapChain_nRelease(JNIEnv* env, jclass cls, jlong pSwapChain, jlong pSwapChainImage) {
	std::cout << "native nRelease " << pSwapChainImage << std::endl;
	auto swapChain = (SharedTextureSwapChain*)pSwapChain;
	auto image = (RenderTarget*)pSwapChainImage;
	swapChain->Release(image);
}


extern "C" JNIEXPORT jint JNICALL Java_org_eclipse_fx_drift_internal_SwapChainImage_nOnTextureCreated(JNIEnv* env, jclass cls, jlong pShareData, jobject fxTexture) {
	auto shareData = (ShareData*)pShareData;
	auto bridge = prism::PrismBridge::Get();

	std::cout << "OnTextrueCreated C pShareData = " << std::hex << pShareData << std::endl;
	std::cout << " => " << shareData->transferMode << std::endl;


	return (jint) bridge->OnTextureCreated(shareData, fxTexture);

}
