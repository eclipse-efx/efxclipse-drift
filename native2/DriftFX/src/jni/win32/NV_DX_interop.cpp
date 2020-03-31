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
#include <d3d9.h>
#include <iostream>
#include <iomanip>

#include <DriftGL_wgl.h>

using namespace driftgl;

extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_jni_win32_NVDXInterop_nWglDXOpenDeviceNV(JNIEnv *env, jclass cls,
	jlong _dxDevice) {
        void* dxDevice = (void*) _dxDevice;
        return (jlong) wglDXOpenDeviceNV(dxDevice);
	}


extern "C" JNIEXPORT jboolean JNICALL Java_org_eclipse_fx_drift_internal_jni_win32_NVDXInterop_nWglDXCloseDeviceNV(JNIEnv *env, jclass cls,
	jlong _hDevice) {
        HANDLE hDevice = (HANDLE) _hDevice;
        return (jboolean) wglDXCloseDeviceNV(hDevice);
	}

extern "C" JNIEXPORT HANDLE JNICALL Java_org_eclipse_fx_drift_internal_jni_win32_NVDXInterop_nWglDXRegisterObjectNV(JNIEnv *env, jclass cls,
	jlong _hDevice, jlong _dxObject, jint _name, jint _type, jint _access) {
        HANDLE hDevice = (HANDLE) _hDevice;
        void* dxObject = (void*) _dxObject;
        GLuint name = (GLuint) _name;
        GLenum type = (GLenum) _type;
        GLenum access = (GLenum) _access;
        return (HANDLE) wglDXRegisterObjectNV(hDevice, dxObject, name, type, access);
	}

extern "C" JNIEXPORT jboolean JNICALL Java_org_eclipse_fx_drift_internal_jni_win32_NVDXInterop_nWglDXUnregisterObjectNV(JNIEnv *env, jclass cls,
	jlong _hDevice, jlong _hObject) {
        HANDLE hDevice = (HANDLE) _hDevice;
        HANDLE hObject = (HANDLE) _hObject;
        return (jboolean) wglDXUnregisterObjectNV(hDevice, hObject);
	}

extern "C" JNIEXPORT jboolean JNICALL Java_org_eclipse_fx_drift_internal_jni_win32_NVDXInterop_nWglDXSetResourceShareHandleNV(JNIEnv *env, jclass cls,
	jlong _dxObject, jlong _shareHandle) {
        void* dxObject = (void*) _dxObject;
        HANDLE shareHandle = (HANDLE) _shareHandle;
        return (jboolean) wglDXSetResourceShareHandleNV(dxObject, shareHandle);
	}

extern "C" JNIEXPORT jboolean JNICALL Java_org_eclipse_fx_drift_internal_jni_win32_NVDXInterop_nWglDXLockObjectsNV(JNIEnv *env, jclass cls,
	jlong _hDevice, jlong _hObject) {
        HANDLE hDevice = (HANDLE) _hDevice;
        HANDLE hObject = (HANDLE) _hObject;
        return (jboolean) wglDXLockObjectsNV(hDevice, 1, &hObject);
	}

extern "C" JNIEXPORT jboolean JNICALL Java_org_eclipse_fx_drift_internal_jni_win32_NVDXInterop_nWglDXUnlockObjectsNV(JNIEnv *env, jclass cls,
	jlong _hDevice, jlong _hObject) {
        HANDLE hDevice = (HANDLE) _hDevice;
        HANDLE hObject = (HANDLE) _hObject;
        return (jboolean) wglDXUnlockObjectsNV(hDevice, 1, &hObject);
	}