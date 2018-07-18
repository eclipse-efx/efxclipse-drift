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

#include <jni.h>

#include <utils/Logger.h>
#include <utils/JNIHelper.h>

#include "JNINativeSurface.h"

using namespace driftfx::internal;

jclass JNINativeSurface::jNativeSurfaceClass = nullptr;
jclass JNINativeSurface::jFrameDataClass = nullptr;

jmethodID JNINativeSurface::jNativeSurface_AcquireMethod = nullptr;
jmethodID JNINativeSurface::jNativeSurface_PresentMethod = nullptr;
jmethodID JNINativeSurface::jNativeSurface_Present2Method = nullptr;
jmethodID JNINativeSurface::jNativeSurface_Present3Method = nullptr;

jfieldID JNINativeSurface::jFrameData_d3dShareHandleField = nullptr;
jfieldID JNINativeSurface::jFrameData_widthField = nullptr;
jfieldID JNINativeSurface::jFrameData_heightField = nullptr;

jmethodID JNINativeSurface::jFrameData_constructor = nullptr;


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


void JNINativeSurface::Initialize() {
	LogDebug("Initialize")

	JNIEnv *env = JNIHelper::GetJNIEnv(true);
	jNativeSurfaceClass = ResolveClass(env, "org/eclipse/fx/drift/internal/JNINativeSurface");
	//jNativeSurface_AcquireMethod = ResolveMethod(env, jNativeSurfaceClass, "acquire", "()J");
	//jNativeSurface_PresentMethod = ResolveMethod(env, jNativeSurfaceClass, "present", "(J)V");

	jFrameDataClass = ResolveClass(env, "org/eclipse/fx/drift/internal/JNINativeSurface$FrameData");
	jNativeSurface_Present2Method = ResolveMethod(env, jNativeSurfaceClass, "present", "(Lorg/eclipse/fx/drift/internal/JNINativeSurface$FrameData;)V");
	jNativeSurface_Present3Method = ResolveMethod(env, jNativeSurfaceClass, "present", "(JJIII)V");

	jFrameData_d3dShareHandleField = ResolveField(env, jFrameDataClass, "d3dShareHandle", "J");
	jFrameData_widthField = ResolveField(env, jFrameDataClass, "width", "I");
	jFrameData_heightField = ResolveField(env, jFrameDataClass, "height", "I");

	jFrameData_constructor = ResolveMethod(env, jFrameDataClass, "<init>", "()V");


	LogDebug("initialization complete")
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

	env->CallVoidMethod(jNativeSurfaceInstance, jNativeSurface_Present3Method, frameData.d3dSharedHandle, frameData.ioSurfaceHandle, frameData.glTextureName, frameData.width, frameData.height);
//	LogDebug("got jni env: " << env)
//
//	jobject instance = env->NewObject(jFrameDataClass, jFrameData_constructor);
//
//	LogDebug("created instance " << instance);
//	env->SetLongField(instance, jFrameData_d3dShareHandleField, frameData.d3dSharedHandle);
//	LogDebug("set handle")
//	env->SetIntField(instance, jFrameData_widthField, frameData.width);
//	LogDebug("set width")
//	env->SetIntField(instance, jFrameData_heightField, frameData.height);
//	LogDebug("set height")
//
//	LogDebug("now calling into the jvm..")
//	env->CallVoidMethod(jNativeSurfaceInstance, jNativeSurface_Present2Method, instance);
}

