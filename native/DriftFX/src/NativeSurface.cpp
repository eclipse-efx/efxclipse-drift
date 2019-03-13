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
#include "Common.h"
#include "NativeSurface.h"
#include "SharedTexture.h"

#include "prism/PrismBridge.h"

#include <utils/Logger.h>

#include <iostream>
using namespace std;

using namespace driftfx;
using namespace driftfx::gl;

using namespace driftfx::internal;
using namespace driftfx::internal::prism;

NativeSurface::NativeSurface(JNINativeSurface* api) :
	api(api),
	context(nullptr),
	lastPresented(nullptr),
	toDispose(nullptr) {
	LogDebug("NativeSurface constructor")

}

NativeSurface::~NativeSurface() {
	LogDebug("NativeSurface" << " destructor")
}

void NativeSurface::Initialize() {
	LogDebug("init GLContext");
	context = PrismBridge::Get()->GetDefaultContext()->CreateSharedContext();
}

void NativeSurface::Cleanup() {


	LogDebug("clean textures");
	if (toDispose != nullptr) {
		delete toDispose;
		toDispose = nullptr;
	}

//	// TODO send some kind of signal to tell FX we are going to dispose our textures
	FrameData* frameData = new FrameData();
	frameData->d3dSharedHandle = 0;
	frameData->ioSurfaceHandle = 0;
	frameData->width=0;
	frameData->height=0;
	api->Present(*frameData);

	delete frameData;
//
//
	// NOTE: since textures know their context and set it current upon deletion
	// we must ensure that all textures from a context are deleted before the context is deleted!

	if (lastPresented != nullptr) {
		delete lastPresented;
		lastPresented = nullptr;
	}

	LogDebug("clean GLContext");
	delete context;
	context = nullptr;

}

GLContext* NativeSurface::GetContext() {
	return context;
}

void NativeSurface::UpdateSize(int width, int height) {
	this->height = height;
	this->width = width;
}

unsigned int NativeSurface::GetWidth() {
	return width;
}

unsigned int NativeSurface::GetHeight() {
	return height;
}

RenderTarget* NativeSurface::Acquire() {
	return Acquire(GetWidth(), GetHeight());
}

RenderTarget* NativeSurface::Acquire(unsigned int width, unsigned int height) {
	LogDebug("acquire0");
	if (toDispose != nullptr) {
		delete toDispose;
		toDispose = nullptr;
	}

	PrismBridge* bridge = PrismBridge::Get();
	// in case the system was destroyed
	if (bridge == nullptr) {
		LogDebug("Could not acquire RenderTarget. Was the system destroyed?");
		return nullptr;
	}

	SharedTexture* tex = SharedTexture::Create(GetContext(), GetFxContext(), width, height);

	tex->Connect();
	tex->Lock();

	return tex;
}

void NativeSurface::Present(RenderTarget* target, PresentationHint hint) {
	if (target == nullptr) {
		LogDebug("Cannot present nullptr; doing nothing.");
		return;
	}
	SharedTexture* texture = dynamic_cast<SharedTexture*>(target);

	texture->Unlock();
	texture->Disconnect();


	FrameData* frameData = texture->CreateFrameData();
	LogDebug("PRESENT " << frameData->ioSurfaceHandle << " " << frameData->glTextureName);
	frameData->presentationHint = hint;


	api->Present(*frameData);

	delete frameData;

	toDispose = lastPresented;
	lastPresented = texture;
}

Context* NativeSurface::GetFxContext() {
	return PrismBridge::Get()->GetFxContext();
}

