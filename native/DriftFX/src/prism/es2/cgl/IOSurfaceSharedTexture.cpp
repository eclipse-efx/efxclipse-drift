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

#include <GL/glew.h>

#include "../../../SharedTexture.h"
#include "IOSurfaceSharedTexture.h"

#include <IOSurface/IOSurface.h>
#include <OpenGL/CGLIOSurface.h>
#include <OpenGL/OpenGL.h>

#include "../../../gl/cgl/cgl.h"
#include "../../../gl/cgl/CGLGLContext.h"

#include "../ES2PrismBridge.h"

#include <DriftFX/GL/GLDebug.h>
#include <DriftFX/math/Vec2.h>

#include <gl/GLLog.h>
#include <gl/cgl/CGLLog.h>

#include <string>
#include <sstream>

using namespace driftfx::gl;
using namespace driftfx::math;
using namespace driftfx::internal;
using namespace driftfx::internal::gl;
using namespace driftfx::internal::gl::cgl;
using namespace driftfx::internal::prism::es2;
using namespace driftfx::internal::prism::es2::cgl;

SharedTexture* SharedTexture::Create(GLContext* context, Context* fxContext, SurfaceData surfaceData, Vec2ui textureSize) {
	return new IOSurfaceSharedTexture(context, surfaceData, textureSize);
}

IOSurfaceSharedTexture::IOSurfaceSharedTexture(GLContext* context, SurfaceData surfaceData, Vec2ui textureSize) :
	SharedTexture(context, surfaceData, textureSize)
		{
	ioSurface = createIOSurface(textureSize.x, textureSize.y);

	if (!glContext->IsCurrent()) {
		std::ostringstream s;
		s << "IOSurfaceSharedTexture: context " << glContext->GetName() << " must be current";
		throw GLContextException(s.str());
	}

	glTexture = dynamic_cast<GLTexture*>(glContext->CreateTexture(textureSize.x, textureSize.y));

	CGLGLContext* cglCtx = dynamic_cast<CGLGLContext*>(glContext);

	GLCALL( glBindTexture(GL_TEXTURE_RECTANGLE, glTexture->Name()) );
	CGLCALL( CGLTexImageIOSurface2D(cglCtx->GetCGLContextObj(), GL_TEXTURE_RECTANGLE, GL_RGBA, textureSize.x, textureSize.y, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, ioSurface, 0) );
	GLCALL( glBindTexture(GL_TEXTURE_RECTANGLE, 0) );
}

IOSurfaceSharedTexture::~IOSurfaceSharedTexture() {
	releaseIOSurface(ioSurface);

	if (!glContext->IsCurrent()) {
		LogInfo("Forcing context switch to " << glContext->GetName());
		glContext->SetCurrent();
	}
	delete glTexture;
}

bool IOSurfaceSharedTexture::Connect() {
	return true;
}
bool IOSurfaceSharedTexture::Disconnect() {
	return true;
}

bool IOSurfaceSharedTexture::Lock() {
	//IOSurfaceLock(ioSurface, kIOSurfaceLockAvoidSync, NULL);
	return true;
}
bool IOSurfaceSharedTexture::Unlock() {
	//IOSurfaceUnlock(ioSurface, kIOSurfaceLockAvoidSync, NULL);
	return true;
}

FrameData* IOSurfaceSharedTexture::CreateFrameData() {

	FrameData* data = new FrameData();
	data->id = (long long) this;
	data->surfaceData = surfaceData;
	data->glTextureName = 0;
	data->ioSurfaceHandle = (long long) ioSurface;
	data->textureSize = textureSize;

	return data;

}
