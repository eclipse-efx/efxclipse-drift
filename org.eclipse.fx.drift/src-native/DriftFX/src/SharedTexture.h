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

#ifndef DRIFTFX_INTERNAL_SHAREDTEXTURE_H_
#define DRIFTFX_INTERNAL_SHAREDTEXTURE_H_

#include <DriftFX/Context.h>
#include <DriftFX/Texture.h>

#include <DriftFX/GL/GLContext.h>
#include <DriftFX/GL/GLTexture.h>

#include <DriftFX/RenderTarget.h>

namespace driftfx {
using namespace gl;
namespace internal {

struct FrameData {
	long d3dSharedHandle;
	long ioSurfaceHandle;
	int glTextureName;
	int width;
	int height;
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


	static SharedTexture* Create(GLContext* context, Context* fxContext, unsigned int width, unsigned int height);

	// RenderTarget
	virtual unsigned int GetGLTexture();
	virtual unsigned int GetWidth();
	virtual unsigned int GetHeight();

protected:
	SharedTexture(GLContext* glContext, unsigned int width, unsigned int height);

	GLContext* glContext;
	GLTexture* glTexture;

	unsigned int width;
	unsigned int height;
};

}
}

#endif /* DRIFTFX_INTERNAL_SHAREDTEXTURE_H_ */
