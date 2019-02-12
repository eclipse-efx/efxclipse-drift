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

#include <utils/Logger.h>

#include "include/java8/D3DContext.h"
#include "D3DPrismBridge.h"
#include "D3DSharedTexture.h"
#include "D3DNativeSurface.h"

#include "NativeSurfaceRegistry.h"
#include "gl/wgl/WGLGLContext.h"
#include "win32/Error.h"

#include <iostream>
using namespace std;

using namespace driftfx::gl;

using namespace driftfx::internal;
using namespace driftfx::internal::gl::wgl;
using namespace driftfx::internal::prism;
using namespace driftfx::internal::prism::d3d;

void D3DPrismBridge::Initialize(jlong pContext) {
	PrismBridge::bridge = new D3DPrismBridge(pContext);
}

void D3DPrismBridge::Destroy() {
	delete dynamic_cast<D3DPrismBridge*>(PrismBridge::bridge);
}

D3DPrismBridge::D3DPrismBridge(jlong pContext) :
	PrismBridge(nullptr) {
	LogDebug("D3DPrismBridge(" << pContext << ")")
	java8::D3DContext *context = (java8::D3DContext*) pContext;
	jfxContext = new D3D9ExContext(context->pd3dObjectEx, context->pd3dDeviceEx);
	defaultContext = new WGLGLContext();

	WGLGLContext* def = dynamic_cast<WGLGLContext*>(defaultContext);
	LogDebug("def = " << def)
	WGLGLContext* test1 = new WGLGLContext(def);
	LogDebug("test1 = " << test1)
//	WGLContext* test2 = new WGLContext(test1);
//	LogDebug("test2 = " << test2)
}

int D3DPrismBridge::RecreateFXTexture(void* fxTexture, HANDLE shareHandle) {
	java8::D3DResource* d3dResource = (java8::D3DResource*) fxTexture;

	d3dResource->pSurface->Release();
	d3dResource->pTexture->Release();
	d3dResource->pResource->Release();

	d3dResource->pSurface = nullptr;
	d3dResource->pTexture = nullptr;
	d3dResource->pResource = nullptr;

	IDirect3DTexture9* pTexture = nullptr;

	HANDLE sh = (HANDLE) shareHandle;
	//sh = nullptr;

	int w = d3dResource->desc.Width;
	int h = d3dResource->desc.Height;

	WERR(;);

	LogDebug("CreateTexture( " << w << ", " << h << ", 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, " << pTexture << ", " << sh << " )")
	HRESULT res = jfxContext->Device()->CreateTexture(
			w, h,
			0, 0,
			D3DFMT_A8R8G8B8,
			D3DPOOL_DEFAULT,
			&pTexture,
			&sh);

	if (FAILED(res)) {
		LogError(HRESULT_CODE(res) << ": " << ToString(HRESULT_CODE(res)));
		return res;
	}

	d3dResource->pResource = pTexture;
	d3dResource->pResource->AddRef();
	d3dResource->pTexture = (IDirect3DTexture9*)d3dResource->pResource;
	d3dResource->pTexture->GetSurfaceLevel(0, &d3dResource->pSurface);
	if (d3dResource->pSurface != nullptr) {
		d3dResource->pSurface->GetDesc(&d3dResource->desc);
	}

	return 0;
}

D3DPrismBridge::~D3DPrismBridge() {
	LogDebug("~D3DPrismBridge()")
	delete jfxContext;
	delete defaultContext;
}

D3D9ExContext* D3DPrismBridge::GetJfxContext() {
	return jfxContext;
}

GLContext* D3DPrismBridge::CreateSharedContext() {
	LogDebug("CreateSharedContext()")
	return new WGLGLContext(dynamic_cast<WGLGLContext*>(defaultContext));
}

NativeSurface* D3DPrismBridge::CreateNativeSurface(JNINativeSurface* api) {
	return new D3DNativeSurface(api);
}

