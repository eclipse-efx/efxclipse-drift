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

#include <iomanip>

#include <utils/Logger.h>
#include <utils/JNIHelper.h>

#include "SharedTexture.h"
#include "JNINativeSurface.h"

using namespace std;

using namespace driftfx::internal;

jclass ResolveClass(JNIEnv* env, const char* name) {
	jclass cls = env->FindClass(name);
	if (cls == nullptr) {
		LogError("Failed to resolve class " << name)
	}
	return cls;
}
jmethodID ResolveMethod(JNIEnv* env, jclass cls, const char* name, const char* sig) {
	jmethodID method = env->GetMethodID(cls, name, sig);
	if (method == nullptr) {
		LogError("Failed to resolve Method " << name << " ( " << sig << ")")
	}
	return method;
}
jfieldID ResolveField(JNIEnv* env, jclass cls, const char* name, const char* sig) {
	jfieldID field = env->GetFieldID(cls, name, sig);
	if (field == nullptr) {
		LogError("Failed to resolve Field " << name << " ( " << sig << " )")
	}
	return field;
}

// Frame
jclass jni::Frame::cls = nullptr;
jmethodID jni::Frame::constructor = nullptr;

void jni::Frame::Initialize(JNIEnv* env) {
	cls = ResolveClass(env, "org/eclipse/fx/drift/internal/Frame");
	cls = (jclass) env->NewGlobalRef(cls);
	constructor = ResolveMethod(env, cls, "<init>", "(JJIILorg/eclipse/fx/drift/internal/SurfaceData;I)V");
}
void jni::Frame::Dispose(JNIEnv* env) {
	env->DeleteGlobalRef(cls);
	cls = nullptr;
	constructor = nullptr;
}
jobject jni::Frame::New(JNIEnv* env, jlong surfaceId, jlong frameId, jint w, jint h, jobject surfaceData, jint presentationHint) {
	return env->NewObject(cls, constructor, surfaceId, frameId, w, h, surfaceData, presentationHint);
}

// FrameData
jclass jni::FrameData::cls = nullptr;
jmethodID jni::FrameData::constructor = nullptr;

void jni::FrameData::Initialize(JNIEnv* env) {
	cls = ResolveClass(env, "org/eclipse/fx/drift/internal/FrameData");
	cls = (jclass) env->NewGlobalRef(jni::FrameData::cls);
	constructor = ResolveMethod(env, cls, "<init>", "(JIILorg/eclipse/fx/drift/internal/SurfaceData;JJIIJJ)V");
}
void jni::FrameData::Dispose(JNIEnv* env) {
	env->DeleteGlobalRef(cls);
	cls = nullptr;
	constructor = nullptr;
}
jobject jni::FrameData::New(JNIEnv* env, jlong frameId, jint width, jint height, jobject surfaceData, jlong d3dShareHandle, jlong ioSurfaceHandle, jint textureName, jint placementHint, jlong memoryPointer, jlong memorySize) {
	return env->NewObject(cls, constructor, frameId, width, height, surfaceData, d3dShareHandle, ioSurfaceHandle, textureName, placementHint, memoryPointer, memorySize);
}

// SurfaceData
jclass jni::SurfaceData::cls = nullptr;
jmethodID jni::SurfaceData::constructor = nullptr;

void jni::SurfaceData::Initialize(JNIEnv* env) {
	cls = ResolveClass(env, "org/eclipse/fx/drift/internal/SurfaceData");
	cls = (jclass) env->NewGlobalRef(cls);
	constructor = ResolveMethod(env, cls, "<init>", "(FFFFFFI)V");
}
void jni::SurfaceData::Dispose(JNIEnv* env) {
	env->DeleteGlobalRef(cls);
	cls = nullptr;
	constructor = nullptr;
}
jobject jni::SurfaceData::New(JNIEnv* env, jfloat width, jfloat height, jfloat renderScaleX, jfloat renderScaleY, jfloat userScaleX, jfloat userScaleY, jint transferMode) {
	return env->NewObject(cls, constructor, width, height, renderScaleX, renderScaleY, userScaleX, userScaleY, transferMode);
}

// NativeSurface
jclass jni::NativeSurface::cls = nullptr;
jmethodID jni::NativeSurface::present = nullptr;
jmethodID jni::NativeSurface::present2 = nullptr;

void jni::NativeSurface::Initialize(JNIEnv* env) {
	cls = ResolveClass(env, "org/eclipse/fx/drift/internal/JNINativeSurface");
	cls = (jclass)env->NewGlobalRef(cls);
	present = ResolveMethod(env, cls, "present", "(Lorg/eclipse/fx/drift/internal/FrameData;)V");
	present2 = ResolveMethod(env, cls, "present", "(Lorg/eclipse/fx/drift/internal/Frame;)V");
}

void jni::NativeSurface::Dispose(JNIEnv* env) {
	env->DeleteGlobalRef(cls);
	cls = nullptr;
	present = nullptr;
	present2 = nullptr;
}

void jni::NativeSurface::Present(JNIEnv* env, jobject nativeSurface, jobject frameData) {
	env->CallVoidMethod(nativeSurface, present, frameData);
}
void jni::NativeSurface::Present2(JNIEnv* env, jobject nativeSurface, jobject frame) {
	env->CallVoidMethod(nativeSurface, present2, frame);
}

void JNINativeSurface::Initialize() {
	LogDebug("Initialize")
	JNIEnv *env = JNIHelper::GetJNIEnv(true);
	jni::Frame::Initialize(env);
	jni::FrameData::Initialize(env);
	jni::SurfaceData::Initialize(env);
	jni::NativeSurface::Initialize(env);
	LogDebug("initialization complete")
}
void JNINativeSurface::Dispose() {
	JNIEnv *env = JNIHelper::GetJNIEnv(true);
	jni::Frame::Dispose(env);
	jni::FrameData::Dispose(env);
	jni::SurfaceData::Dispose(env);
	jni::NativeSurface::Dispose(env);
}

JNINativeSurface::JNINativeSurface(jobject javaNativeSurface) {
	JNIEnv *env = JNIHelper::GetJNIEnv(true);
	// protect the references from garbage collection
	LogDebug("registering global ref to surface " << javaNativeSurface)
	jNativeSurfaceInstance = reinterpret_cast<jobject>( env->NewGlobalRef(javaNativeSurface) );
}

JNINativeSurface::~JNINativeSurface() {
	JNIEnv *env = JNIHelper::GetJNIEnv(true);
	env->DeleteGlobalRef(jNativeSurfaceInstance);
}

void JNINativeSurface::Present(Frame* frame) {
	JNIEnv *env = JNIHelper::GetJNIEnv(true);

	auto surfaceData = frame->GetSurfaceData();

	jobject jSurfaceData = jni::SurfaceData::New(env,
		(jfloat) surfaceData.size.x, (jfloat) surfaceData.size.y,
		(jfloat) surfaceData.screenScale.x, (jfloat) surfaceData.screenScale.y,
		(jfloat) surfaceData.userScale.x, (jfloat) surfaceData.userScale.y, (jint) surfaceData.transferMode);

	jobject jFrame = jni::Frame::New(env, frame->GetSurfaceId(), frame->GetFrameId(), frame->GetWidth(), frame->GetHeight(), jSurfaceData, frame->GetPresentationHint());

	jni::NativeSurface::Present2(env, jNativeSurfaceInstance, jFrame);
}
