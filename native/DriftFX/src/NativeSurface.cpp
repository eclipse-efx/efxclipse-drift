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

#include <iostream>

#include <DriftFX/DriftFXSurface.h>
#include <DriftFX/math/Vec2.h>

#include "Common.h"
#include "JNINativeSurface.h"
#include "NativeSurface.h"
#include "SharedTexture.h"
#include "prism/PrismBridge.h"

#include <utils/Logger.h>

#include <cmath>


using namespace std;

using namespace driftfx;
using namespace driftfx::math;
using namespace driftfx::gl;

using namespace driftfx::internal;
using namespace driftfx::internal::prism;

NativeSurface::NativeSurface(JNINativeSurface* api) :
	api(api),
	context(nullptr),
	surfaceData(SurfaceData()) {
	LogDebug("NativeSurface constructor")

}

NativeSurface::~NativeSurface() {
	LogDebug("NativeSurface" << " destructor")
}

void NativeSurface::Initialize() {
	LogDebug("init GLContext");
	context = PrismBridge::Get()->GetDefaultContext()->CreateSharedContext();
}

void NativeSurface::DisposeSharedTexture(long long id) {
	toDisposeMutex.lock();

	SharedTexture* texture = (SharedTexture*) id;
	toDispose.push_back(texture);

	toDisposeMutex.unlock();
}

void NativeSurface::DisposeSharedTextures() {
	LogDebug("Disposing shared textures");
	toDisposeMutex.lock();
	for (std::vector<SharedTexture*>::iterator it = toDispose.begin(); it != toDispose.end(); ++it) {
		SharedTexture* tex = (*it);
		LogDebug(" - " << tex);
		delete tex;
	}
	toDispose.clear();
	toDisposeMutex.unlock();
}

void NativeSurface::Cleanup() {


//	// TODO send some kind of signal to tell FX we are going to dispose our textures
	FrameData* frameData = new FrameData();
	frameData->d3dSharedHandle = 0;
	frameData->ioSurfaceHandle = 0;
	frameData->glTextureName = 0;
	frameData->textureSize = Vec2ui();

	api->Present(*frameData);

	delete frameData;

	LogDebug("clean textures");
	DisposeSharedTextures();

//
//
	// NOTE: since textures know their context and set it current upon deletion
	// we must ensure that all textures from a context are deleted before the context is deleted!

	LogDebug("clean GLContext");
	delete context;
	context = nullptr;

}

GLContext* NativeSurface::GetContext() {
	return context;
}

void NativeSurface::UpdateSurface(Vec2d size, Vec2d screenScale, Vec2d userScale) {
	SurfaceData newSurfaceData;
	newSurfaceData.size = size;
	newSurfaceData.screenScale = screenScale;
	newSurfaceData.userScale = userScale;

	surfaceData = newSurfaceData;
}

unsigned int NativeSurface::GetWidth() {
	return GetScaledSize().x;
}

unsigned int NativeSurface::GetHeight() {
	return GetScaledSize().y;
}

RenderTarget* NativeSurface::Acquire() {
	return Acquire(GetWidth(), GetHeight());
}

RenderTarget* NativeSurface::Acquire(Vec2ui size) {
	return Acquire(size.x, size.y);
}

RenderTarget* NativeSurface::Acquire(unsigned int width, unsigned int height) {
	auto currentSurfaceData = surfaceData.load();
	LogDebug("Acquire " << dec << width << " x " << dec << height);
	LogDebug(" " << dec << currentSurfaceData.size.x << " / " << currentSurfaceData.screenScale.x << " / " << currentSurfaceData.userScale.x);
	DisposeSharedTextures();

	PrismBridge* bridge = PrismBridge::Get();
	// in case the system was destroyed
	if (bridge == nullptr) {
		LogDebug("Could not acquire RenderTarget. Was the system destroyed?");
		return nullptr;
	}

	SharedTexture* tex = SharedTexture::Create(GetContext(), GetFxContext(), currentSurfaceData, Vec2ui(width, height));

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
}

Context* NativeSurface::GetFxContext() {
	return PrismBridge::Get()->GetFxContext();
}

Vec2d NativeSurface::GetSurfaceSize() {
	return surfaceData.load().size;
}

Vec2d NativeSurface::GetScreenScale() {
	return surfaceData.load().screenScale;
}

Vec2d NativeSurface::GetUserScale() {
	return surfaceData.load().userScale;
}

Vec2ui NativeSurface::GetScaledSize() {
	SurfaceData data = surfaceData.load();
	Vec2ui r;
	r.x = (unsigned int) ceil(data.size.x * data.screenScale.x * data.userScale.x);
	r.y = (unsigned int) ceil(data.size.y * data.screenScale.y * data.userScale.y);
	return r;
}