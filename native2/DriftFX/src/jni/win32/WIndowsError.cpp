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
#include <windows.h>

extern "C" JNIEXPORT jint JNICALL Java_org_eclipse_fx_drift_internal_jni_win32_WindowsError_getLastError(JNIEnv *env, jclass cls,
	jlong _pAddress) {
		return (jint) GetLastError();
	}
