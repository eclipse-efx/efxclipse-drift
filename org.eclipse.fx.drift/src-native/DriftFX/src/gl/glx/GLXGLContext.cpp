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
#include "GLXGLContext.h"

#include <utils/Logger.h>

#include <GL/glew.h>
#include <GL/glxew.h>

#include <iostream>
using namespace std;

using namespace driftfx::gl;

using namespace driftfx::internal::gl::glx;

typedef GLXContext (*glXCreateContextAttribsARBProc)(Display*, GLXFBConfig, GLXContext, Bool, const int*);
typedef Bool (*glXMakeContextCurrentARBProc)(Display*, GLXDrawable, GLXDrawable, GLXContext);


GLXGLContext::GLXGLContext(GLXContext sharedContext) {
	LogDebug("sharedContext = " << sharedContext);

	display = XOpenDisplay( NULL );
	LogDebug("Opened display = " << display);

	GLenum err = glxewInit(display);
	LogDebug("glxewInit returned " << err);

	static int visualAttribs[] = { None };
	int fbConfigsCount = 0;
	LogDebug("calling glXChooseFbConfig " << glXChooseFBConfig);
	GLXFBConfig* fbConfigs = glXChooseFBConfig( display, DefaultScreen(display), visualAttribs, &fbConfigsCount );

	LogDebug("Created fbConfigs = " << fbConfigs);

	int context_attribs[] = {
			GLX_CONTEXT_MAJOR_VERSION_ARB, 4,
			GLX_CONTEXT_MINOR_VERSION_ARB, 1,
			GLX_CONTEXT_FLAGS_ARB, GLX_CONTEXT_DEBUG_BIT_ARB,
			GLX_CONTEXT_PROFILE_MASK_ARB, GLX_CONTEXT_CORE_PROFILE_BIT_ARB,
			None
	};
	glXCreateContextAttribsARBProc glXCreateContextAttribsARB = (glXCreateContextAttribsARBProc) glXGetProcAddressARB( (const GLubyte *) "glXCreateContextAttribsARB" );
	glXMakeContextCurrentARBProc glXMakeContextCurrentARB   = (glXMakeContextCurrentARBProc)   glXGetProcAddressARB( (const GLubyte *) "glXMakeContextCurrent"      );

	glxContext = glXCreateContextAttribsARB( display, fbConfigs[0], sharedContext, True, context_attribs);
	LogDebug("Created context = " << glxContext);

	int pbufferAttribs[] = {
		GLX_PBUFFER_WIDTH,  32,
		GLX_PBUFFER_HEIGHT, 32,
		None
	};
	pBuffer = glXCreatePbuffer( display, fbConfigs[0], pbufferAttribs );
	LogDebug("Created pBuffer = " << pBuffer);

	// clean up:
	XFree( fbConfigs );
	XSync( display, False );

//	LogDebug("Initializing glew..");
//
//	glXMakeContextCurrent(display, pBuffer, pBuffer, glxContext);
//	glewExperimental=true;
//	glewInit();

	LogDebug("done.");
}

void GLXGLContext::UnsetCurrent() {
	glXMakeCurrent(display, None, NULL);
	//glXMakeContextCurrent(display, 0, 0, 0);
}

GLXGLContext::GLXGLContext(GLXGLContext* shared) :
		GLXGLContext(shared == nullptr ? 0 : shared->GetHandle()){

	GLXContext ctx;
}

GLXGLContext::GLXGLContext() :
		GLXGLContext((GLXContext) 0) {
}

GLXGLContext::~GLXGLContext() {
	glXMakeCurrent( display, 0, 0 );
	glXDestroyPbuffer(display, pBuffer);
	glXDestroyContext(display, glxContext);
	XCloseDisplay(display);
}

GLContext* GLXGLContext::CreateSharedContext() {
	return new GLXGLContext(this);
}

void GLXGLContext::SetCurrent() {
	glXMakeContextCurrent(display, pBuffer, pBuffer, glxContext);
}
bool GLXGLContext::IsCurrent() {
	return glXGetCurrentContext() == glxContext;
}

GLXContext GLXGLContext::GetHandle() {
	return glxContext;
}
