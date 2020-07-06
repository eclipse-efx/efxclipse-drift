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
#include <CoreFoundation/CoreFoundation.h>
#include <IOSurface/IOSurface.h>
#include <OpenGL/CGLCurrent.h>
#include <OpenGL/OpenGL.h>

#include "cgl_context.h"

extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_jni_macos_MacOS_callCreateIOSurface(JNIEnv *env, jclass cls,
    jint _width, jint _height) {
        auto width = (int) _width;
        auto height = (int) _height;

	int bpe = 4;

	CFStringRef keys[3];
	keys[0] = kIOSurfaceWidth;
	keys[1] = kIOSurfaceHeight;
	keys[2] = kIOSurfaceBytesPerElement;
	CFNumberRef values[3];
	values[0] = CFNumberCreate(kCFAllocatorDefault, kCFNumberIntType, &width);
	values[1] = CFNumberCreate(kCFAllocatorDefault, kCFNumberIntType, &height);
	values[2] = CFNumberCreate(kCFAllocatorDefault, kCFNumberIntType, &bpe);

	CFDictionaryRef dict;
	dict = CFDictionaryCreate(NULL, (const void**)keys, (const void**)values, 3, &kCFCopyStringDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
	//CFShow(dict);
    auto ioSurface = IOSurfaceCreate(dict);
    CFRelease(dict);
	return (jlong) ioSurface;
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_jni_macos_MacOS_callCFRelease(JNIEnv *env, jclass cls,
    jlong _typeRef) {
        auto typeRef = (CFTypeRef) _typeRef;
        CFRelease(typeRef);
    }

extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_jni_macos_MacOS_callIOSurfaceGetID(JNIEnv *env, jclass cls,
    jlong _ioSurface) {
        auto ioSurface = (IOSurfaceRef) _ioSurface;
        return (jlong) IOSurfaceGetID(ioSurface);
    }

extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_jni_macos_MacOS_callIOSurfaceLookup(JNIEnv *env, jclass cls,
    jlong _ioSurfaceID) {
        auto ioSurfaceID = (IOSurfaceID) _ioSurfaceID;
        
        return (jlong) IOSurfaceLookup(ioSurfaceID);
    }

extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_jni_macos_MacOS_callCGLGetCurrentContext(JNIEnv *env, jclass cls) {
    return (jlong) CGLGetCurrentContext();
}

extern "C" JNIEXPORT jint JNICALL Java_org_eclipse_fx_drift_internal_jni_macos_MacOS_callCGLTexImageIOSurface2D(JNIEnv *env, jclass cls,
    jlong _ctx, jint _target, jint _internal_format, jint _width, jint _height, jint _format, jint _type, jlong _ioSurface, jint _plane) {
        auto ctx = (CGLContextObj) _ctx;
        auto target = (GLenum) _target;
        auto internal_format = (GLenum) _internal_format;
        auto width = (GLuint) _width;
        auto height = (GLuint) _height;
        auto format = (GLenum) _format;
        auto type = (GLenum) _type;
        auto ioSurface = (IOSurfaceRef) _ioSurface;
        auto plane = (GLuint) _plane;
        return (jint) CGLTexImageIOSurface2D(ctx, target, internal_format, width, height, format, type, ioSurface, plane);

}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_jni_macos_MacOS_callIOSurfaceLock(JNIEnv *env, jclass cls, jlong _ioSurface) {
    auto ioSurface = (IOSurfaceRef) _ioSurface;
    IOSurfaceLock(ioSurface, kIOSurfaceLockReadOnly, NULL);
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_jni_macos_MacOS_callIOSurfaceUnlock(JNIEnv *env, jclass cls, jlong _ioSurface) {
    auto ioSurface = (IOSurfaceRef) _ioSurface;
    IOSurfaceUnlock(ioSurface, kIOSurfaceLockReadOnly, NULL);
}

extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_jni_macos_MacOS_callGetCGLContextObjFromNSJContext(JNIEnv *env, jclass cls, jlong nsJContext) {
    return (jlong) getCGLContextObj((void*) nsJContext);
}
