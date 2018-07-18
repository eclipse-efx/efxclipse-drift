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

GLXContext GLXGLContext::GetHandle() {
	return glxContext;
}
