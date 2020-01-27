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
#ifndef SHARED_TEXTURE_SWAPCHAIN_H_
#define SHARED_TEXTURE_SWAPCHAIN_H_

#include <jni.h>

#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>

#include <DriftFX/DriftFXSurface.h>

#include "NativeSurface.h"
#include "TransferModeManager.h"

namespace driftfx {
namespace internal {

class SharedTextureSwapChain;

class SwapChainImage : public driftfx::RenderTarget {
public:
	SwapChainImage(unsigned int number, SharedTextureSwapChain* swapChain, SharedTexture* texture, ShareData* shareData);
	~SwapChainImage();

	virtual unsigned int GetWidth();
	virtual unsigned int GetHeight();
	virtual unsigned int GetGLTexture();

	virtual SharedTexture* GetSharedTexture();
	virtual ShareData* GetShareData();

	virtual jobject GetJavaObject();

	virtual unsigned int Number();
private:
	SharedTexture* texture;
	ShareData* shareData;
	jobject jObject;
	unsigned int number;

};

class SharedTextureSwapChain : public driftfx::SwapChain {

public:

	SharedTextureSwapChain(NativeSurface* surface, math::Vec2ui size, unsigned int imageCount, TransferModeImpl* transferMode, PresentationHint hint, PresentationMode mode);
	virtual ~SharedTextureSwapChain();

	virtual RenderTarget* Acquire();

	virtual bool TryAcquire(RenderTarget** renderTarget);

	virtual void Present(RenderTarget* target);


	virtual void Release(RenderTarget* image);

	virtual PresentationHint GetPresentationHint();
	virtual SurfaceData GetSurfaceData();
	virtual jobject GetJavaObject();

private:
	NativeSurface* surface;
	math::Vec2ui size;
	unsigned int imageCount;
	PresentationHint presentationHint;
	PresentationMode presentationMode;
	TransferModeImpl* transferMode;
	SurfaceData surfaceData;

	std::vector<SwapChainImage*> images;
	std::queue<SwapChainImage*> freeImages;

	std::mutex imageMutex;
	std::condition_variable imageReleased;

	jobject javaSwapChain;

};

}
}



#endif
