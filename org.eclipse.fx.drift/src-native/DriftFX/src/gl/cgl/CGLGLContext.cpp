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
bool CGLGLContext::IsCurrent() {
	return CGLGetCurrentContext() == contextObj;
}

void* CGLGLContext::GetHandle() {
	return (void*) contextObj;
}
