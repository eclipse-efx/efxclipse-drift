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

#include "InternalGLContext.h"

#include <GL/glew.h>

#include <iostream>
using namespace std;

using namespace driftfx::internal::gl;

long InternalGLContext::instanceCount = 0;
bool InternalGLContext::initialized = false;

void* InternalGLContext::resolve(const GLubyte* name) {
	return NULL;
}

void InternalGLContext::Initialize() {
	glewInit();
}

void InternalGLContext::Cleanup() {

}

InternalGLContext::InternalGLContext() {
	instanceCount++;
}
InternalGLContext::~InternalGLContext() {
	instanceCount--;
}

GLenum InternalGLContext::glGetError() {
	return ::glGetError();
}
void InternalGLContext::glGenTextures(GLsizei n, GLuint* textures) {
	::glGenTextures(n, textures);
}
void InternalGLContext::glDeleteTextures(GLsizei n, GLuint* textures) {
	::glDeleteTextures(n, textures);
}
void InternalGLContext::glBindTexture(GLenum target, GLuint texture) {
	::glBindTexture(target, texture);
}

