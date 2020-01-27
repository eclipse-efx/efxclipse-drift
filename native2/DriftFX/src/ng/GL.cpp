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



extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glewInit(JNIEnv *env, jclass cls) {
	glewInit();
}

extern "C" JNIEXPORT jint JNICALL Java_org_eclipse_fx_drift_internal_GL_glGenTexture(JNIEnv *env, jclass cls) {
	GLuint tex;
	glGenTextures(1, &tex);
	return (jint) tex;
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glDeleteTexture(JNIEnv *env, jclass cls, jint texture) {
	GLuint tex = (GLuint) texture;
	glDeleteTextures(1, &tex);
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glBindTexture(JNIEnv *env, jclass cls, jint _target, jint _texture) {
	GLenum target = (GLenum) _target;
	GLuint texture = (GLuint) _texture;
	glBindTexture(target, texture);
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glTexImage2D(JNIEnv *env, jclass cls, jint _target, jint _level, jint _internalformat, jint _width, jint _height, jint _border, jint _format, jint _type, jlong _pPixels) {
	GLenum target = (GLenum) _target;
	GLint level = (GLint) _level;
	GLint internalformat = (GLint) _internalformat;
	GLsizei width = (GLsizei) _width;
	GLsizei height = (GLsizei) _height;
	GLint border = (GLint) _border;
	GLenum format = (GLenum) _format;
	GLenum type = (GLenum) _type;
	void* pixels = (void*) _pPixels;
	glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glGetTexImage(JNIEnv *env, jclass cls, jint _target, jint _level, jint _format, jint _type, jlong _pPixels) {
	GLenum target = (GLenum) _target;
	GLint level = (GLint) _level;
	GLenum format = (GLenum) _format;
	GLenum type = (GLenum) _type;
	void* pixels = (void*) _pPixels;
	glGetTexImage(target, level, format, type, pixels);
}

extern "C" JNIEXPORT jint JNICALL Java_org_eclipse_fx_drift_internal_GL_glGenBuffer(JNIEnv *env, jclass cls) {
	GLuint buffer;
	glGenBuffers(1, &buffer);
	return (jint) buffer;
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glDeleteBuffer(JNIEnv *env, jclass cls, jint _buffer) {
	GLuint buffer = (GLuint) _buffer;
	glDeleteBuffers(1, &buffer);
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glBindBuffer(JNIEnv *env, jclass cls, jint _target, jint _buffer) {
	GLenum target = (GLenum) _target;
	GLuint buffer = (GLuint) _buffer;
	glBindBuffer(target, buffer);
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glBufferData(JNIEnv *env, jclass cls, jint _target, jint _size, jlong _pData, jint _usage) {
	GLenum target = (GLenum) _target;
	GLsizei size = (GLsizei) _size;
	void* data = (void*) _pData;
	GLenum usage = (GLenum) _usage;
	glBufferData(target, size, data, usage);
}

extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_GL_glMapBuffer(JNIEnv *env, jclass cls, jint _target, jint _access) {
	GLenum target = (GLenum) _target;
	GLenum access = (GLenum) _access;
	return (jlong) glMapBuffer(target, access);
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glUnmapBuffer(JNIEnv *env, jclass cls, jint _target) {
	GLenum target = (GLenum) _target;
	glUnmapBuffer(target);
}







