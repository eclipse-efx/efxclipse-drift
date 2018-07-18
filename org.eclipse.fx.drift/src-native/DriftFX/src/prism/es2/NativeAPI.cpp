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

#include <utils/Logger.h>

#include <jni.h>

#include <iostream>
using namespace std;

#include "ES2PrismBridge.h"

#include <GL/glew.h>

using namespace driftfx::internal::prism;
using namespace driftfx::internal::prism::es2;

// TODO Rename
extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_NativeAPI_nDestroyD3DPipeline(JNIEnv *env, jclass cls) {
	LogDebug("nDestroyPrismBridge()")
	PrismBridge::Destroy();
}

//thread_local GLContext* dummy = nullptr;

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_NativeAPI_nES2CopyTexture(JNIEnv *env, jclass cls, jint sourceTexture, jint destTexture, jint width, jint height) {
	ES2PrismBridge* bridge = dynamic_cast<ES2PrismBridge*>(PrismBridge::Get());
	bridge->GetDefaultContext()->SetCurrent();
	bridge->CopyTexture(sourceTexture, destTexture, width, height);
	//bridge->GetDefaultContext()->UnsetCurrent();
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_NativeAPI_nES2DeleteTexture(JNIEnv* env, jclass cls, jint textureId) {
	GLuint tex = textureId;
	glDeleteTextures(1, &tex);
}


