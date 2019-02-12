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
#ifndef DRIFTFX_INTERNAL_NATIVESURFACE_H_
#define DRIFTFX_INTERNAL_NATIVESURFACE_H_

//class NativeSurface;

#include <DriftFX/RenderTarget.h>
#include <DriftFX/DriftFXSurface.h>
#include <DriftFX/GL/GLContext.h>

#include "JNINativeSurface.h"

namespace driftfx {
using namespace driftfx::gl;
namespace internal {

class NativeSurface : public DriftFXSurface {

public:
	virtual ~NativeSurface();

	/*
	 * Initialises this native surface.
	 * Should be called on your render thread.
	 * This will create a GLContext. Its accessible via GetContext().
	 */
	virtual void Initialize();

	/*
	 * Cleanup this native surface.
	 * Should be called on your render thread.
	 * Releases all pending resources and destroys its contexts.
	 */
	virtual void Cleanup();

	/*
	 * Acquires a RenderTarget with the current width / height.
	 * delegates to Acquire(GetWidth(), GetHeight()).
	 */
	virtual RenderTarget* Acquire();

	/*
	 * Acquires a new RenderTarget with the given size.
	 * Should be called from your render thread.
	 *
	 */
	virtual RenderTarget* Acquire(unsigned int width, unsigned int height);

	/*
	 * Presents a previously acquired RenderTarget.
	 * Should be called from your render thread.
	 *
	 */
	virtual void Present(RenderTarget* target, PresentationHint hint);


	virtual GLContext* GetContext();

	/*
	 * returns the current width of the NativeSurface in JavaFX
	 */
	unsigned int GetWidth();
	/*
	 * returns the current height of the NativeSurface in JavaFX
	 */
	unsigned int GetHeight();

	/**
	 * Internal API.
	 */
	virtual void UpdateSize(int width, int height);

	static NativeSurface* Create(JNINativeSurface* api);

	virtual Context* GetFxContext();

protected:
	NativeSurface(JNINativeSurface* api);

	JNINativeSurface *api;

	GLContext* context;

	volatile unsigned int width;
	volatile unsigned int height;

private:

	SharedTexture* lastPresented;
	SharedTexture* toDispose;
};

}
}

#endif /* DRIFTFX_INTERNAL_NATIVESURFACE_H_ */
