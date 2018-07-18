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

#include "CGLGLContext.h"

#include <DriftFX/GL/GLContext.h>

#include "cgl.h"

#include <cstdint>

#include <GL/glew.h>

#include <OpenGL/OpenGL.h>
#include <OpenGL/CGLContext.h>
#include <OpenGL/CGLTypes.h>
#include <OpenGL/CGLDevice.h>
#include <OpenGL/gl.h>

#include <iostream>
#include <string>


#include <utils/Logger.h>

using namespace std;

using namespace driftfx::gl;
using namespace driftfx::internal::gl::cgl;

CGLGLContext::CGLGLContext(CGLContextObj cglContext, bool managed) :
		contextObj(cglContext),
		managed(managed) {
}

GLContext* CGLGLContext::CreateSharedContext() {
	LogDebug("creating shared context!!");
	CGLPixelFormatObj pix = CGLGetPixelFormat(contextObj);
	CGLContextObj newContext;
	checkErr(CGLCreateContext( pix, contextObj, &newContext ), "CGLCreateContext");
	//checkErr(CGLDestroyPixelFormat( pix ), "CGLDestroyPixelFormat");
	return new CGLGLContext(newContext, true);
}

CGLGLContext::CGLGLContext() :
	managed(true) {

	CGLPixelFormatAttribute attributes[5] = {
		//kCGLPFAPBuffer,
		kCGLPFAAccelerated,
		kCGLPFAOpenGLProfile,
		(CGLPixelFormatAttribute) kCGLOGLPVersion_3_2_Core,
		(CGLPixelFormatAttribute) 0
	};
	GLint num;

	CGLPixelFormatObj pix;
	checkErr(CGLChoosePixelFormat( attributes, &pix, &num ), "CGLChoosePixelFormat");
	checkErr(CGLCreateContext( pix, 0, &contextObj ), "CGLCreateContext");
	checkErr(CGLDestroyPixelFormat( pix ), "CGLDestroyPixelFormat");
}

CGLGLContext::~CGLGLContext() {
	cerr << "CGLGLContext Destructor" << endl;
	checkErr(CGLDestroyContext( contextObj ), "CGLDestroyContext");
}

void CGLGLContext::SetCurrent() {
	checkErr(CGLSetCurrentContext( contextObj ), "CGLSetCurrentContext");
}
void CGLGLContext::UnsetCurrent() {
	checkErr(CGLSetCurrentContext( NULL ), "CGLSetCurrentContext");
}
void* CGLGLContext::GetHandle() {
	return (void*) contextObj;
}
