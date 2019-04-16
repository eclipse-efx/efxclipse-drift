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
#include <utils/Logger.h>

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

void InternalGLContext::GenBuffers(GLsizei n, GLuint* buffers) {
	glGenBuffers(n, buffers);
	GLenum error = ::glGetError();
	if (error != 0) {
		LogError("GL Error : " << hex << error);
	}
}
void InternalGLContext::DeleteBuffers(GLsizei n, GLuint* buffers) {
	glDeleteBuffers(n, buffers);
	GLenum error = ::glGetError();
	if (error != 0) {
		LogError("GL Error : " << hex << error);
	}
}
void* InternalGLContext::MapBuffer(GLenum target, GLenum access) {
	void* result = glMapBuffer(target, access);
	GLenum error = glGetError();
	switch (error) {
	case 0: break;
	case GL_INVALID_ENUM: LogError("GL Error: GL_INVALID_ENUM"); break;
	case GL_INVALID_OPERATION: LogError("GL Error: GL_INVALID_OPERATION"); break;

	default: LogError("GL Error : " << hex << error);
	
	}
	return result;
}
void InternalGLContext::UnmapBuffer(GLenum target) {
	glUnmapBuffer(target);
	GLenum error = ::glGetError();
	if (error != 0) {
		LogError("GL Error : " << hex << error);
	}
}
void InternalGLContext::BindBuffer(GLenum target, GLuint buffer) {
	glBindBuffer(target, buffer);
	GLenum error = ::glGetError();
	if (error != 0) {
		LogError("GL Error : " << hex << error);
	}
}

void InternalGLContext::GetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void* pixels) {
	glGetTexImage(target, level, format, type, pixels);
	GLenum error = glGetError();
	switch (error) {
	case 0: break;
	case GL_INVALID_ENUM: LogError("GL Error: GL_INVALID_ENUM"); break;
	case GL_INVALID_OPERATION: LogError("GL Error: GL_INVALID_OPERATION"); break;

	default: LogError("GL Error : " << hex << error);

	}
}

