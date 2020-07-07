/*
 * Copyright (c) 2020 BestSolution.at and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Christoph Caks <ccaks@bestsolution.at> - initial API and implementation
 */

#include <jni.h>
#include <DriftGL.h>

#include <iostream>
#include <iomanip>
#include <chrono>

#include "D3DContext.h"

#include "JNIHelper.h"

using namespace driftgl;


void * GetD3DResourceHandle(jobject fxTexture)
{
	// TODO we could handle this purely in native code via jni calls
	JNIEnv* env = JNIHelper::GetJNIEnv(true);

	jclass cls = env->FindClass("org/eclipse/fx/drift/internal/GraphicsPipelineUtil$D3D");
	cls = (jclass)env->NewGlobalRef(cls);

	jmethodID getTextureHandle = env->GetStaticMethodID(cls, "getTextureHandle", "(Lcom/sun/prism/Texture;)J");

	//LogDebug("Calling now with " << cls << " / " << getTextureName << " / " << fxTexture);
	jlong val = env->CallStaticLongMethod(cls, getTextureHandle, fxTexture);
	//LogDebug(" Got " << val);
	return (void*)val;
}


extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_D3DBatch_uploadTexture(JNIEnv *env, jclass cls, jobject _fxTexture, jlong _pPixels, jint _width, jint _height, jint _size) {
	
	auto startJVM = std::chrono::steady_clock::now();
	JavaVM* vm;
    env->GetJavaVM(&vm);
    JNIHelper::Initialize(vm);

    //std::cout << "D3DBatch#updloadTexture..." << std::endl;

        void* resourceHandle = GetD3DResourceHandle(_fxTexture);

		
		auto endJVM = std::chrono::steady_clock::now();
		std::cout << "[Drift] uploadTexture JVM: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endJVM - startJVM).count() << "ns"<< std::endl;

		java8::D3DResource* d3dResource = (java8::D3DResource*) resourceHandle;

		IDirect3DTexture9* texture = d3dResource->pTexture;

        auto pPixels = (byte*) _pPixels;
        auto width = (int) _width;
        auto height = (int) _height;
		auto size = (int) _size;

        //std::cout << "First Pixel: " << std::hex << (int)pPixels[0] << ", " << (int)pPixels[1] << ", " << (int)pPixels[2] << ", " << (int)pPixels[3] << std::dec << std::endl;
		
		D3DLOCKED_RECT tmp;

		auto startDX = std::chrono::steady_clock::now();
		texture->LockRect(0, &tmp, NULL, D3DLOCK_DISCARD);

		byte* rowBits = (byte*)tmp.pBits;
		int sourcePitch = width * 4 * sizeof(byte);
		for (unsigned int h = 0; h < height; h++) {

			int offset = h * sourcePitch;
			memcpy(rowBits, (pPixels + offset), sourcePitch);
			rowBits += tmp.Pitch;
		}

		texture->UnlockRect(0);
		auto endDX = std::chrono::steady_clock::now();
		std::cout << "[Drift] uploadTexture DX: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endDX - startDX).count() << "ns"<< std::endl;


		//texture->LockRect(0, &tmp, NULL, D3DLOCK_READONLY);

		//texture->UnlockRect(0);



}