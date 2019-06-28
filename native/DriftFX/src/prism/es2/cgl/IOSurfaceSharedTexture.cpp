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

#include <jni.h>

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

#include <utils/Logger.h>

#include <gl/GLLog.h>
#include <gl/cgl/CGLLog.h>

#include <string>
#include <sstream>
#include <iostream>

#include <MainMemorySharedTexture.h>

using namespace driftfx::gl;
using namespace driftfx::math;
using namespace driftfx::internal;
using namespace driftfx::internal::gl;
using namespace driftfx::internal::gl::cgl;
using namespace driftfx::internal::prism::es2;
using namespace driftfx::internal::prism::es2::cgl;


int IOSurfaceSharedTexture::OnTextureCreated(PrismBridge* bridge, Frame* frame, jobject fxTexture) {

	std::cout << "Bridge: " << bridge << std::endl;

	ES2PrismBridge* es2Bridge = dynamic_cast<ES2PrismBridge*>(bridge);

	GLContext* fxShared = es2Bridge->GetFXSharedGLContext();

	std::cout << "Context: " << fxShared << std::endl;

	if (!fxShared->IsCurrent()) {
		fxShared->SetCurrent();
	}



	GLuint textureName = es2Bridge->GetGLTextureName(fxTexture);

	std::cout << "textureName: " << textureName << std::endl;


	CGLGLContext* fx = dynamic_cast<CGLGLContext*>(fxShared);
	std::cout << "fx: " << fx << std::endl;

	unsigned int width = frame->GetSize().x;
	unsigned int height = frame->GetSize().y;

	SharedTexture* sharedTex = frame->GetSharedTexture();
	std::cout << "sharedTex: " << sharedTex << std::endl;

	IOSurfaceSharedTexture* sharedTexture = dynamic_cast<IOSurfaceSharedTexture*>(sharedTex);
	//void* ioSurfaceHandle = sharedTexture->GetIOSurfaceHandle();
	// TODO we should use the io surface by id (IOSurfaceGetID instead of the pointer)
	//IOSurfaceRef ioSurface = (IOSurfaceRef) (void*) ioSurfaceHandle;

	// CONNECT ioSurface to temporary texture
	std::cout << " sharedTexture: " << sharedTexture << std::endl;

	IOSurfaceID surfaceID = sharedTexture->GetIOSurfaceID();

	std::cout << " surfaceID: " << surfaceID << std::endl;

	IOSurfaceRef ioSurface = IOSurfaceLookup(surfaceID);

	std::cout << " ioSurface: " << ioSurface << std::endl;
	if (ioSurface != nullptr) {

		GLuint tmpTex;

		GLCALL( glGenTextures(1, &tmpTex) );

		GLCALL( glBindTexture(GL_TEXTURE_RECTANGLE, tmpTex) );
		CGLCALL( CGLTexImageIOSurface2D(fx->GetCGLContextObj(), GL_TEXTURE_RECTANGLE, GL_RGBA, width, height, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, ioSurface, 0) );
		GLCALL( glBindTexture(GL_TEXTURE_RECTANGLE, 0) );

		// COPY OVER
		// Note: we need to copy the texture here, because iosurface works with GL_TEXTURE_RECTANGLE, while javafx can only work with GL_TEXTURE_2D
		ES2PrismBridge::CopyTexture(tmpTex, textureName, width, height);

		GLCALL( glDeleteTextures(1, &tmpTex) );

		return 0;

	}

	return -1;
}

SharedTextureFactoryId IOSurfaceSharedTexture::registered =
		SharedTextureFactory::RegisterSharedTextureType("IOSurface",
				[](GLContext* context, Context* fxContext, Frame* frame) { return new IOSurfaceSharedTexture(context, frame); });


SharedTextureFactoryId IOSurfaceSharedTexture::registerPrism = PrismBridge::Register(IOSurfaceSharedTexture::registered,
		[](PrismBridge* bridge, Frame* frame, jobject fxTexture) {
			return IOSurfaceSharedTexture::OnTextureCreated(bridge, frame, fxTexture);
		});




IOSurfaceSharedTexture::IOSurfaceSharedTexture(GLContext* context, Frame* frame) :
	SharedTexture(context, frame)
		{
	auto textureSize = frame->GetSize();
	ioSurface = createIOSurface(textureSize.x, textureSize.y);
	ioSurfaceID = IOSurfaceGetID(ioSurface);

	if (!glContext->IsCurrent()) {
		std::ostringstream s;
		s << "IOSurfaceSharedTexture: context " << glContext->GetName() << " must be current";
		throw GLContextException(s.str());
	}


}

IOSurfaceSharedTexture::~IOSurfaceSharedTexture() {
	LogDebug("Destroying IOSurface " << ioSurfaceID);
	releaseIOSurface(ioSurface);

//	if (!glContext->IsCurrent()) {
//		LogInfo("Forcing context switch to " << glContext->GetName());
//		glContext->SetCurrent();
//	}

}

bool IOSurfaceSharedTexture::BeforeRender() {

	auto textureSize = frame->GetSize();
	glTexture = dynamic_cast<GLTexture*>(glContext->CreateTexture(textureSize.x, textureSize.y));

	CGLGLContext* cglCtx = dynamic_cast<CGLGLContext*>(glContext);

	GLCALL( glBindTexture(GL_TEXTURE_RECTANGLE, glTexture->Name()) );
	CGLCALL( CGLTexImageIOSurface2D(cglCtx->GetCGLContextObj(), GL_TEXTURE_RECTANGLE, GL_RGBA, textureSize.x, textureSize.y, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, ioSurface, 0) );
	GLCALL( glBindTexture(GL_TEXTURE_RECTANGLE, 0) );
	//IOSurfaceLock(ioSurface, kIOSurfaceLockAvoidSync, NULL);
	return true;
}
bool IOSurfaceSharedTexture::AfterRender() {
	SignalFrameReady();
	WaitForFrameReady();
	//IOSurfaceUnlock(ioSurface, kIOSurfaceLockAvoidSync, NULL);
	delete glTexture;
	return true;
}

FrameData* IOSurfaceSharedTexture::CreateFrameData() {

	FrameData* data = new FrameData();
	data->id = (long long) this;
	data->surfaceData = frame->GetSurfaceData();
	data->glTextureName = 0;
	data->ioSurfaceHandle = (long long) ioSurface;
	data->textureSize = frame->GetSize();

	return data;

}

void* IOSurfaceSharedTexture::GetIOSurfaceHandle() {
	return (void*) ioSurface;
}

IOSurfaceID IOSurfaceSharedTexture::GetIOSurfaceID() {
	return ioSurfaceID;
}
