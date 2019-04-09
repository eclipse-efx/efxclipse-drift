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

#ifndef DRIFTFX_GL_RENDERTARGET_H_
#define DRIFTFX_GL_RENDERTARGET_H_

#include <DriftFX/RenderTarget.h>

namespace driftfx {
namespace internal {
	
	class GLRenderTarget : public RenderTarget {

	public:
		GLRenderTarget(DriftFXSurface* surface, unsigned int width, unsigned int height);

		virtual DriftFXSurface* GetSurface();
		virtual unsigned int GetWidth();
		virtual unsigned int GetHeight();
		virtual unsigned int GetGLTexture();

	protected:
		virtual ~GLRenderTarget();

	private:
		DriftFXSurface* surface;
		unsigned int width;
		unsigned int height;
		unsigned int glTexture;
	};
	
	
}
}

#endif