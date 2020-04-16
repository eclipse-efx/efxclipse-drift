/*
 * Copyright (c) 2020 BestSolution.at and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Christoph Caks <ccaks@bestsolution.at> - initial API and implementation
 */

#include <jni.h>
#include <DriftGL.h>

#include <iostream>

using namespace driftgl;

extern "C" JNIEXPORT jboolean JNICALL Java_org_eclipse_fx_drift_internal_GL_initialize(JNIEnv *env, jclass cls) {
	return (jboolean) Initialize();
}

extern "C" JNIEXPORT jboolean JNICALL Java_org_eclipse_fx_drift_internal_GL_destroy(JNIEnv *env, jclass cls) {
	return (jboolean) Destroy();
}

extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_GL_createContext(JNIEnv *env, jclass cls, jlong sharedContext, jint majorHint, jint minorHint) {
	return (jlong) CreateContext((Context*) sharedContext, (int) majorHint, (int) minorHint);
}

extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_GL_createSharedCompatContext(JNIEnv *env, jclass cls, jlong sharedContext) {
	return (jlong) CreateSharedCompatContext((Context*) sharedContext);
}

extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_GL_wrapContext(JNIEnv *env, jclass cls, jlong nativeContextHandle) {
	return (jlong) WrapContext((jlong) nativeContextHandle);
}

extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_GL_getCurrentContext(JNIEnv *env, jclass cls) {
	return (jlong) GetCurrentContext();
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_destroyContext(JNIEnv *env, jclass cls, jlong context) {
	DestroyContext((Context*) context);
}

extern "C" JNIEXPORT jboolean JNICALL Java_org_eclipse_fx_drift_internal_GL_makeContextCurrent(JNIEnv *env, jclass cls, jlong context) {
	return (jboolean) MakeContextCurrent((Context*) context);
}

extern "C" JNIEXPORT jboolean JNICALL Java_org_eclipse_fx_drift_internal_GL_isContextCurrent(JNIEnv *env, jclass cls, jlong context) {
	return (jboolean) IsContextCurrent((Context*) context);
}

extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_GL_getNativeContextHandle(JNIEnv *env, jclass cls, jlong context) {
	return (jlong) GetNativeContextHandle((Context*) context);
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

extern "C" JNIEXPORT jboolean JNICALL Java_org_eclipse_fx_drift_internal_GL_glIsTexture(JNIEnv *env, jclass cls, jint texture) {
	GLuint tex = (GLuint) texture;
	return (jboolean) glIsTexture(tex);
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glBindTexture(JNIEnv *env, jclass cls, jint _target, jint _texture) {
	GLenum target = (GLenum) _target;
	GLuint texture = (GLuint) _texture;
	glBindTexture(target, texture);
}

extern "C" JNIEXPORT jint JNICALL Java_org_eclipse_fx_drift_internal_GL_glGetError(JNIEnv *env, jclass cls) {
	return (jint) glGetError();
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glBlitFramebuffer(JNIEnv *env, jclass cls, jint _srcX0, jint _srcY0, jint _srcX1, jint _srcY1, jint _dstX0, jint _dstY0, jint _dstX1, jint _dstY1, jint _mask, jint _filter) {
	GLint srcX0 = (GLint) _srcX0;
	GLint srcY0 = (GLint) _srcY0;
	GLint srcX1 = (GLint) _srcX1;
	GLint srcY1 = (GLint) _srcY1;
	GLint dstX0 = (GLint) _dstX0;
	GLint dstY0 = (GLint) _dstY0;
	GLint dstX1 = (GLint) _dstX1;
	GLint dstY1 = (GLint) _dstY1;
	GLbitfield mask = (GLbitfield) _mask;
	GLenum filter = (GLenum) _filter;
	glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
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

	GLint tex;
	glGetIntegerv(GL_TEXTURE_BINDING_2D, &tex);
	std::cout << "TEXTURE_2D = " << tex << std::endl;
	std::cout << "glTexImage2D " << width << " x " << height << " @ " << pixels << std::endl;
	std::cout << std::flush;

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


extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glClearColor(JNIEnv *env, jclass cls, jfloat _red, jfloat _green, jfloat _blue, jfloat _alpha) {
	GLfloat red = (GLfloat) _red;
	GLfloat green = (GLfloat) _green;
	GLfloat blue = (GLfloat) _blue;
	GLfloat alpha = (GLfloat) _alpha;
	glClearColor(red, green, blue, alpha);
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glClear(JNIEnv *env, jclass cls, jint _mask) {
	GLbitfield mask = (GLbitfield) _mask;
	glClear(mask);
}

extern "C" JNIEXPORT jint JNICALL Java_org_eclipse_fx_drift_internal_GL_glGenFramebuffer(JNIEnv *env, jclass cls) {
	GLuint fb;
	glGenFramebuffers(1, &fb);
	return (jint) fb;
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glDeleteFramebuffer(JNIEnv *env, jclass cls, jint _framebuffer) {
	GLuint framebuffer = (GLuint) _framebuffer;
	glDeleteBuffers(1, &framebuffer);
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glBindFramebuffer(JNIEnv *env, jclass cls, jint _target, jint _framebuffer) {
	GLenum target = (GLenum) _target;
	GLuint framebuffer = (GLuint) _framebuffer;
	glBindFramebuffer(target, framebuffer);
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glFramebufferTexture(JNIEnv *env, jclass cls, jint _target, jint _attachment, jint _texture, jint _level) {
	GLenum target = (GLenum) _target;
	GLenum attachment = (GLenum) _attachment;
	GLuint texture = (GLuint) _texture;
	GLuint level = (GLuint) _level;
	glFramebufferTexture(target, attachment, texture, level);
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glPixelStorei(JNIEnv *env, jclass cls, jint _pname, jint _param) {
	GLenum pname = (GLenum) _pname;
	GLint param = (GLint) _param;
	glPixelStorei(pname, param);
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glPixelStoref(JNIEnv *env, jclass cls, jint _pname, jfloat _param) {
	GLenum pname = (GLenum) _pname;
	GLfloat param = (GLfloat) _param;
	glPixelStoref(pname, param);
}

extern "C" JNIEXPORT jint JNICALL Java_org_eclipse_fx_drift_internal_GL_glGetInteger(JNIEnv *env, jclass cls, jint _pname, jfloat _param) {
	GLenum pname = (GLenum) _pname;
	GLint param;
	glGetIntegerv(pname, &param);
	return (jint) param;
}

extern "C" JNIEXPORT jfloat JNICALL Java_org_eclipse_fx_drift_internal_GL_glGetFloat(JNIEnv *env, jclass cls, jint _pname, jfloat _param) {
	GLenum pname = (GLenum) _pname;
	GLfloat param;
	glGetFloatv(pname, &param);
	return (jfloat) param;
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glFlush(JNIEnv *env, jclass cls) {
	glFlush();
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glFinish(JNIEnv *env, jclass cls) {
	glFinish();
}


extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_GL_glCreateFence(JNIEnv *env, jclass cls) {
	GLsync fence = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);
	return (jlong) fence;
}


extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glDeleteSync(JNIEnv* env, jclass cls, jlong sync) {
	GLsync fence = (GLsync) sync;
	glDeleteSync(fence);
}

extern "C" JNIEXPORT jint JNICALL Java_org_eclipse_fx_drift_internal_GL_glClientWaitSync(JNIEnv* env, jclass cls, jlong sync, long timeout) {
	GLsync fence = (GLsync) sync;
	GLuint64 tout = (GLuint64) timeout;
	GLenum result = glClientWaitSync(fence, GL_SYNC_FLUSH_COMMANDS_BIT, tout);
	return (jint) result;
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_glWaitSync(JNIEnv* env, jclass cls, jlong sync) {
	GLsync fence = (GLsync) sync;
	glWaitSync(fence, 0, GL_TIMEOUT_IGNORED);
}

