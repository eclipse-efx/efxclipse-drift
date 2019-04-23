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

#include <DriftFX/math/Vec2.h>

#include "prism/PrismBridge.h"

#include "NativeSurface.h"
#include "NativeSurfaceRegistry.h"
#include "JNINativeSurface.h"

#include "SharedTexture.h"


#include "Configuration.h"

#include <iostream>

#include <utils/JNIHelper.h>
#include <utils/Logger.h>

using namespace std;

using namespace driftfx::internal;
using namespace driftfx::math;

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_NativeAPI_nInitialize(JNIEnv *env, jclass cls) {
	LogDebug("nInitialize")
	JavaVM* jvm;
	env->GetJavaVM(&jvm);
	JNIHelper::Initialize(jvm);
	Configuration::Initialize();
	JNINativeSurface::Initialize();
}

extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_NativeAPI_nCreateNativeSurface(JNIEnv *env, jclass cls, jobject surfaceObj) {
	LogDebug("nCreateNativeSurface")
	JNINativeSurface *api = new JNINativeSurface(surfaceObj);
	return NativeSurfaceRegistry::Get()->Create(api);
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_NativeAPI_nDestroyNativeSurface(JNIEnv *env, jclass cls, jlong surfaceId) {
	LogDebug("nDestroyNativeSurface")
	NativeSurfaceRegistry::Get()->Destroy((long) surfaceId);
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_NativeAPI_nUpdateSurface(JNIEnv *env, jclass cls, jlong surfaceId, jdouble width, jdouble height, jdouble screenScaleX, jdouble screenScaleY, jdouble userScaleX, jdouble userScaleY) {
	NativeSurface* surface = NativeSurfaceRegistry::Get()->Get((long)surfaceId);
	surface->UpdateSurface(Vec2d((double)width, (double)height), Vec2d((double)screenScaleX, (double)screenScaleY), Vec2d((double)userScaleX, (double)userScaleY));
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_NativeAPI_nDisposeFrameData(JNIEnv* env, jclass cls, jlong surfaceId, jlong frameDataId) {
	LogDebug("dispose frame data " << surfaceId << ": " << frameDataId);
	NativeSurface* surface = NativeSurfaceRegistry::Get()->Get((long) surfaceId);
	surface->DisposeSharedTexture((long long) frameDataId);
}


