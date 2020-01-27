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

#include <jni.h>
#include <d3d9.h>

#include <cstring>
#include <chrono>
#include <iomanip>

#include "native-prism-d3d\D3DContext.h"


#include <utils/Logger.h>

using namespace driftfx::internal::prism;

java8::D3DResource* GetD3DResourceHandle(JNIEnv* env, jobject fxTexture)
{
	jclass cls = env->FindClass("org/eclipse/fx/drift/internal/GraphicsPipelineUtil$D3D");
	cls = (jclass)env->NewGlobalRef(cls);

	jmethodID getTextureHandle = env->GetStaticMethodID(cls, "getTextureHandle", "(Lcom/sun/prism/Texture;)J");

	//LogDebug("Calling now with " << cls << " / " << getTextureName << " / " << fxTexture);
	jlong val = env->CallStaticLongMethod(cls, getTextureHandle, fxTexture);
	//LogDebug(" Got " << val);
	return (java8::D3DResource*)val;
}

IDirect3DTexture9* GetDirect3DTexture(JNIEnv* env, jobject fxTexture) {
	auto d3dResource = GetD3DResourceHandle(env, fxTexture);
	return d3dResource->pTexture;
}


extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_D3DBatch_uploadTexture(JNIEnv *env, jclass cls, jobject fxTexture, jlong _pPixels, jint _width, jint _height, jint _size) {

	// TODO split this operation in simpler calls

	auto pixels = (byte*)_pPixels;
	auto width = (int)_width;
	auto height = (int)_height;
	auto size = (int)_size;


	IDirect3DTexture9* texture = GetDirect3DTexture(env, fxTexture);

	// upload to D3D texture

	D3DLOCKED_RECT tmp;
	auto start = std::chrono::steady_clock::now();
	texture->LockRect(0, &tmp, NULL, D3DLOCK_DISCARD);
	// TODO LockRect HRESULT check


	byte* rowBits = (byte*)tmp.pBits;
	int sourcePitch = width * 4 * sizeof(byte);
	for (unsigned int h = 0; h < height; h++) {

		int offset = h * sourcePitch;
		memcpy(rowBits, (pixels + offset), sourcePitch);
		rowBits += tmp.Pitch;
	}

	texture->UnlockRect(0);
	// TODO UnlockRect HRESULT check

	auto end = std::chrono::steady_clock::now();
	LogDebug("Uploading " << std::dec << width * height << "px needed " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns");

	auto startSync = std::chrono::steady_clock::now();
	texture->LockRect(0, &tmp, NULL, D3DLOCK_READONLY);
	// TODO LockRect HRESULT check

	texture->UnlockRect(0);
	// TODO LockRect HRESULT check

	auto endSync = std::chrono::steady_clock::now();
	LogDebug("Relocking d3d tex for sync needed " << std::chrono::duration_cast<std::chrono::nanoseconds>(endSync - startSync).count() << "ns");



}
