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

using namespace driftfx::gl;

using namespace driftfx::internal;
using namespace driftfx::internal::gl;
using namespace driftfx::internal::gl::cgl;
using namespace driftfx::internal::prism::es2;
using namespace driftfx::internal::prism::es2::cgl;

SharedTexture* SharedTexture::Create(GLContext* context, Context* fxContext, unsigned int width, unsigned int height) {
	return new IOSurfaceSharedTexture(context, dynamic_cast<GLContext*>(fxContext), width, height);
}

IOSurfaceSharedTexture::IOSurfaceSharedTexture(GLContext* context, GLContext* fxContext, unsigned int width, unsigned int height) :
	SharedTexture(context, width, height),
	fxContext(fxContext)
		{
	ioSurface = createIOSurface(width, height);

	fxContext->SetCurrent();

	fxTexture = dynamic_cast<GLTexture*>(fxContext->CreateTexture(width, height));

	// SIZE IT!
//	GLERR( glBindTexture(GL_TEXTURE_2D, fxTexture->Name()); );
//  GLERR( glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, NULL); );
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, NULL);
//	GLERR( glBindTexture(GL_TEXTURE_2D, 0); );

	glContext->SetCurrent();
	glTexture = dynamic_cast<GLTexture*>(glContext->CreateTexture(width, height));

	CGLGLContext* cglCtx = dynamic_cast<CGLGLContext*>(glContext);
	void* ctxHandle = cglCtx->GetHandle();
	CGLContextObj ctx = (CGLContextObj) ctxHandle;


	GLERR( glBindTexture(GL_TEXTURE_RECTANGLE, glTexture->Name()); );
	checkErr( CGLTexImageIOSurface2D(ctx, GL_TEXTURE_RECTANGLE, GL_RGBA, width, height, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, ioSurface, 0), "CGLTexImageIOSurface2D");
	GLERR( glBindTexture(GL_TEXTURE_RECTANGLE, 0); );


	//context->SetCurrent();
}

IOSurfaceSharedTexture::~IOSurfaceSharedTexture() {

	releaseIOSurface(ioSurface);

	delete fxTexture;

	delete glTexture;
}

bool IOSurfaceSharedTexture::Connect() {
	int width = GetWidth();
	int height = GetHeight();





	return true;
}
bool IOSurfaceSharedTexture::Disconnect() {
	int width = GetWidth();
	int height = GetHeight();


	// is it impossible to disconnect the ioSurface from the texture =?

	// we can delete the texture
//	delete glTexture;
//
//	glFlush();
//	fxContext->SetCurrent();
//
//	GLuint fb;
//	GLERR(glGenFramebuffers(1, &fb););
//
//	GLERR(glBindFramebuffer(GL_FRAMEBUFFER, fb););
//	LogDebug("bound GL_FRAMEBUFFER to " << fb << ", fxTexture->Name() is " << fxTexture->Name());
//	GLERR(glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, fxTexture->Name(), 0););
//
//	GLERR(glClearColor(1, 0, 0, 1););
//	GLERR(glClear(GL_COLOR_BUFFER_BIT););
//	GLERR(glFlush(););
//
//	GLERR(glBindFramebuffer(GL_FRAMEBUFFER, 0););
//	GLERR(glDeleteFramebuffers(1, &fb););


//	GLuint err = glGetError();
//
//
//	LogDebug("Error: " << err);

//	// receive texture in shared fx context
//
//	GLuint tmpTex;
//
//	glGenTextures(1, &tmpTex);
//
//	CGLGLContext* fx = dynamic_cast<CGLGLContext*>(fxContext);
//	CGLContextObj ctx = (CGLContextObj) fx->GetHandle();
//
//	glBindTexture(GL_TEXTURE_RECTANGLE, tmpTex);
//	CGLError err = CGLTexImageIOSurface2D(ctx, GL_TEXTURE_RECTANGLE, GL_RGBA, width, height, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, ioSurface, 0);
//	checkErr(err, "bind io surface");
//	glBindTexture(GL_TEXTURE_RECTANGLE, 0);
//
//
//	// COPY OVER
//	ES2PrismBridge* bridge = dynamic_cast<ES2PrismBridge*>(PrismBridge::Get());
//	bridge->CopyTexture(tmpTex, fxTexture->Name(), width, height);
//
//	glDeleteTextures(1, &tmpTex);

//	glContext->SetCurrent();
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
	data->width = GetWidth();
	data->height = GetHeight();
	data->glTextureName = fxTexture->Name();
	data->ioSurfaceHandle = (long long) ioSurface;

	return data;

}
