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

#include "CGLES2PrismBridge.h"

#include "../../../gl/cgl/CGLGLContext.h"
#include "../../../gl/cgl/cgl.h"

#include <IOSurface/IOSurface.h>
#include <OpenGL/CGLIOSurface.h>

#include <DriftFX/GL/GLDebug.h>


using namespace driftfx::internal::gl::cgl;
using namespace driftfx::internal::prism::es2::cgl;

CGLES2PrismBridge::CGLES2PrismBridge(jlong pContext) :
	ES2PrismBridge(new CGLGLContext((CGLContextObj) getCGLContextObj((void*) pContext), false))
{
	defaultContext = new CGLGLContext();

	sharedFXContext = fxGLContext->CreateSharedContext();

	defaultContext->SetCurrent();
	glewInit();

}

CGLES2PrismBridge::~CGLES2PrismBridge() {
	delete sharedFXContext;
}


void CGLES2PrismBridge::Initialize(jlong pContext) {
	PrismBridge::bridge = new CGLES2PrismBridge(pContext);
}

int CGLES2PrismBridge::ConnectTextureToIOSurface(int textureName, int width, int height, long ioSurfaceHandle) {

	// SAVE THE STATE!
	sharedFXContext->SetCurrent();

	// CONNECT ioSurface to temporary texture
	GLuint tmpTex;

	IOSurfaceRef ioSurface = (IOSurfaceRef) (void*) ioSurfaceHandle;

	GLERR( glGenTextures(1, &tmpTex); )

	CGLGLContext* fx = dynamic_cast<CGLGLContext*>(sharedFXContext);
	CGLContextObj ctx = (CGLContextObj) fx->GetHandle();

	GLERR( glBindTexture(GL_TEXTURE_RECTANGLE, tmpTex); );
	CGLError err = CGLTexImageIOSurface2D(ctx, GL_TEXTURE_RECTANGLE, GL_RGBA, width, height, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, ioSurface, 0);
	checkErr(err, "bind io surface");
	GLERR( glBindTexture(GL_TEXTURE_RECTANGLE, 0); )


	// COPY OVER
	CopyTexture(tmpTex, textureName, width, height);

	GLERR( glDeleteTextures(1, &tmpTex); )

	fxGLContext->SetCurrent();

	return 0;
}
