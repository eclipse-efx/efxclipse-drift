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

#ifndef DRIFTFX_INTERNAL_SHAREDTEXTURE_H_
#define DRIFTFX_INTERNAL_SHAREDTEXTURE_H_

#include <DriftFX/DriftFXSurface.h>
#include <DriftFX/Context.h>
#include <DriftFX/Texture.h>

#include <DriftFX/GL/GLContext.h>
#include <DriftFX/GL/GLTexture.h>

#include <DriftFX/RenderTarget.h>

#include <DriftFX/math/Vec2.h>

#include "NativeSurface.h"
#include "SurfaceData.h"

namespace driftfx {
using namespace gl;
namespace internal {

struct FrameData {

	SurfaceData surfaceData;
	math::Vec2ui textureSize;

	long long id;
	long long d3dSharedHandle;
	long long ioSurfaceHandle;
	int glTextureName;
	
	int presentationHint;
};

class SharedTexture : public RenderTarget {

public:
	virtual ~SharedTexture();

	virtual GLTexture* GetTexture();



	virtual bool Connect() = 0;
	virtual bool Disconnect() = 0;

	virtual bool Lock() = 0;
	virtual bool Unlock() = 0;

	virtual FrameData* CreateFrameData() = 0;


	static SharedTexture* Create(GLContext* context, Context* fxContext, SurfaceData surfaceData, math::Vec2ui textureSize);

	// RenderTarget
	virtual unsigned int GetGLTexture();
	virtual unsigned int GetWidth();
	virtual unsigned int GetHeight();

protected:
	SharedTexture(GLContext* glContext, SurfaceData surfaceData, math::Vec2ui textureSize);

	GLContext* glContext;
	GLTexture* glTexture;

	math::Vec2ui textureSize;
	SurfaceData surfaceData;
};

}
}

#endif /* DRIFTFX_INTERNAL_SHAREDTEXTURE_H_ */
