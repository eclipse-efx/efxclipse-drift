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
#include <windows.h>
#include <d3d9.h>
#include <iostream>
#include <iomanip>

#include "D3DContext.h"


extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_jni_win32_Prism_nGetPrismIDirect3DDevice9Ex(JNIEnv *env, jclass cls,
	jlong _prismD3DContext) {
        prism::java8::D3DContext* prismD3DContext = (prism::java8::D3DContext*) _prismD3DContext;
        return (jlong) prismD3DContext->pd3dDeviceEx;
	}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_jni_win32_Prism_nReplacePrismD3DTexture(JNIEnv *env, jclass cls,
	jlong _prismResource, jlong _texture) {
        prism::java8::D3DResource* prismResource = (prism::java8::D3DResource*) _prismResource;
        IDirect3DTexture9* texture = (IDirect3DTexture9*) _texture;

        prismResource->pTexture->Release();
        prismResource->pResource->Release();
        prismResource->pSurface->Release();

        prismResource->pResource = texture;
        prismResource->pResource->AddRef();
        prismResource->pTexture = (IDirect3DTexture9*)prismResource->pResource;
        prismResource->pTexture->GetSurfaceLevel(0, &prismResource->pSurface);
        if (prismResource->pSurface != nullptr) {
            prismResource->pSurface->GetDesc(&prismResource->desc);
        }


	}
