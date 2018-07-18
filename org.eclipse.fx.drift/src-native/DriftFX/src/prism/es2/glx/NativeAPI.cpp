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

#include "GLXES2PrismBridge.h"

using namespace driftfx::internal::prism::es2::glx;

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_NativeAPI_nInitializeES2Pipeline(JNIEnv *env, jclass cls, jlong pContext) {
	LogDebug("nInitializeES2Pipeline(" << pContext << ")")
	GLXES2PrismBridge::Initialize(pContext);
}

