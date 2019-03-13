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
#ifndef DRIFTFX_DRIFTFXSURFACE_H_
#define DRIFTFX_DRIFTFXSURFACE_H_

#include <DriftFX/Common.h>

#include <DriftFX/RenderTarget.h>

#include <DriftFX/Context.h>
#include <DriftFX/GL/GLContext.h>

namespace driftfx {

enum DRIFT_API PresentationHint {
	CENTER
};


class DRIFT_API DriftFXSurface {

public:
	/*
	 * Initializes this surface.
	 * Should be called on your render thread.
	 * This will create a GLContext. Its accessible via GetContext().
	 */
	virtual void Initialize() = 0;

	/*
	 * Cleanup this native surface.
	 * Should be called on your render thread.
	 * Releases all pending resources and destroys its contexts.
	 */
	virtual void Cleanup() = 0;

	/*
	 * Acquires a RenderTarget with the current width / height.
	 * delegates to Acquire(GetWidth(), GetHeight()).
	 */
	virtual RenderTarget* Acquire() = 0;

	/*
	 * Acquires a new RenderTarget with the given size.
	 * Should be called from your render thread.
	 *
	 */
	virtual RenderTarget* Acquire(unsigned int width, unsigned int height) = 0;

	/*
	 * Presents a previously acquired RenderTarget.
	 * Should be called from your render thread.
	 *
	 */
	virtual void Present(RenderTarget* target, PresentationHint hint) = 0;


	virtual gl::GLContext* GetContext() = 0;

	/*
	 * returns the current width of the NativeSurface in JavaFX
	 */
	virtual unsigned int GetWidth() = 0;
	/*
	 * returns the current height of the NativeSurface in JavaFX
	 */
	virtual unsigned int GetHeight() = 0;

protected:
	virtual ~DriftFXSurface() = 0;
};

}

#endif /* DRIFTFX_DRIFTFXSURFACE_H_ */
