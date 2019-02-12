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

#include "InternalGLContext.h"

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

