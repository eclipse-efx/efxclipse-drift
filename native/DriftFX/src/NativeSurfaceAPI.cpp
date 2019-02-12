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

#include "prism/PrismBridge.h"

#include "NativeSurface.h"
#include "JNINativeSurface.h"

#include "NativeSurfaceRegistry.h"

#include "JNINativeSurface.h"
#include "NativeSurface.h"

#include "SharedTexture.h"

#include <iostream>
using namespace std;

#include <utils/JNIHelper.h>
#include <utils/Logger.h>

using namespace driftfx::internal;


extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_NativeAPI_nInitialize(JNIEnv *env, jclass cls) {
	LogDebug("nInitialize")
	JavaVM* jvm;
	env->GetJavaVM(&jvm);
	JNIHelper::Initialize(jvm);
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

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_NativeAPI_nUpdateSize(JNIEnv *env, jclass cls, jlong surfaceId, jint width, jint height) {
	NativeSurface* surface = NativeSurfaceRegistry::Get()->Get((long) surfaceId);
	surface->UpdateSize((int) width, (int) height);
}


