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

#include <utils/Logger.h>
#include <utils/JNIHelper.h>

#include "SharedTexture.h"
#include "JNINativeSurface.h"

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



// FrameData
jclass jni::FrameData::cls = nullptr;
jmethodID jni::FrameData::constructor = nullptr;

void jni::FrameData::Initialize(JNIEnv* env) {
	cls = ResolveClass(env, "org/eclipse/fx/drift/internal/FrameData");
	cls = (jclass) env->NewGlobalRef(jni::FrameData::cls);
	constructor = ResolveMethod(env, cls, "<init>", "(JIILorg/eclipse/fx/drift/internal/SurfaceData;JJII)V");
}
void jni::FrameData::Dispose(JNIEnv* env) {
	env->DeleteGlobalRef(cls);
	cls = nullptr;
	constructor = nullptr;
}
jobject jni::FrameData::New(JNIEnv* env, jlong frameId, jint width, jint height, jobject surfaceData, jlong d3dShareHandle, jlong ioSurfaceHandle, jint textureName, jint placementHint) {
	return env->NewObject(cls, constructor, frameId, width, height, surfaceData, d3dShareHandle, ioSurfaceHandle, textureName, placementHint);
}

// SurfaceData
jclass jni::SurfaceData::cls = nullptr;
jmethodID jni::SurfaceData::constructor = nullptr;

void jni::SurfaceData::Initialize(JNIEnv* env) {
	cls = ResolveClass(env, "org/eclipse/fx/drift/internal/SurfaceData");
	cls = (jclass) env->NewGlobalRef(cls);
	constructor = ResolveMethod(env, cls, "<init>", "(FFFFFF)V");
}
void jni::SurfaceData::Dispose(JNIEnv* env) {
	env->DeleteGlobalRef(cls);
	cls = nullptr;
	constructor = nullptr;
}
jobject jni::SurfaceData::New(JNIEnv* env, jfloat width, jfloat height, jfloat renderScaleX, jfloat renderScaleY, jfloat userScaleX, jfloat userScaleY) {
	return env->NewObject(cls, constructor, width, height, renderScaleX, renderScaleY, userScaleX, userScaleY);
}

// NativeSurface
jclass jni::NativeSurface::cls = nullptr;
jmethodID jni::NativeSurface::present = nullptr;

void jni::NativeSurface::Initialize(JNIEnv* env) {
	cls = ResolveClass(env, "org/eclipse/fx/drift/internal/JNINativeSurface");
	cls = (jclass)env->NewGlobalRef(cls);
	present = ResolveMethod(env, cls, "present", "(Lorg/eclipse/fx/drift/internal/FrameData;)V");
}

void jni::NativeSurface::Dispose(JNIEnv* env) {
	env->DeleteGlobalRef(cls);
	cls = nullptr;
	present = nullptr;
}

void jni::NativeSurface::Present(JNIEnv* env, jobject nativeSurface, jobject frameData) {
	env->CallVoidMethod(nativeSurface, present, frameData);
}

void JNINativeSurface::Initialize() {
	LogDebug("Initialize")
	JNIEnv *env = JNIHelper::GetJNIEnv(true);
	jni::FrameData::Initialize(env);
	jni::SurfaceData::Initialize(env);
	jni::NativeSurface::Initialize(env);
	LogDebug("initialization complete")
}
void JNINativeSurface::Dispose() {
	JNIEnv *env = JNIHelper::GetJNIEnv(true);
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

void JNINativeSurface::Present(FrameData frameData) {
	LogDebug("going to call present")
	JNIEnv *env = JNIHelper::GetJNIEnv(true);

	jobject surfaceData = jni::SurfaceData::New(env,
		(jfloat) frameData.surfaceData.size.x, (jfloat) frameData.surfaceData.size.y, 
		(jfloat) frameData.surfaceData.screenScale.x, (jfloat) frameData.surfaceData.screenScale.y,
		(jfloat) frameData.surfaceData.userScale.x, (jfloat) frameData.surfaceData.userScale.y);

	jobject jFrameData = jni::FrameData::New(env, frameData.id, frameData.textureSize.x, frameData.textureSize.y, surfaceData, 
		frameData.d3dSharedHandle, frameData.ioSurfaceHandle, frameData.glTextureName, frameData.presentationHint);

	jni::NativeSurface::Present(env, jNativeSurfaceInstance, jFrameData);
}