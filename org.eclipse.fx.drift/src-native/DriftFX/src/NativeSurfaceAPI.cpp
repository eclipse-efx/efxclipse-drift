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
	NativeSurfaceRegistry::Get()->Destroy(surfaceId);
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_NativeAPI_nUpdateSize(JNIEnv *env, jclass cls, jlong surfaceId, jint width, jint height) {
	NativeSurface* surface = NativeSurfaceRegistry::Get()->Get(surfaceId);
	surface->UpdateSize((int) width, (int) height);
}


