/*
 * Copyright (c) 2018 BestSolution and Others. All rights reserved.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0, which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * This Source Code may also be made available under the following Secondary
 * Licenses when the conditions for such availability set forth in the
 * Eclipse Public License v. 2.0 are satisfied: GNU General Public License,
 * version 2 with the GNU Classpath Exception, which is available at
 * https://www.gnu.org/software/classpath/license.html.
 *
 * SPDX-License-Identifier: EPL-2.0 OR GPL-2.0 WITH Classpath-exception-2.0
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
