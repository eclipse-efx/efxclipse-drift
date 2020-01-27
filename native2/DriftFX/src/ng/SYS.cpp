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
#include <cstdlib>
#include <cstring>

extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_SYS_malloc(JNIEnv *env, jclass cls, jint _size) {
	size_t size = (size_t) _size;
	return (jlong) malloc(size);
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_SYS_free(JNIEnv *env, jclass cls, jlong _pPointer) {
	void* pointer = (void*) _pPointer;
	free(pointer);
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_SYS_memcpy(JNIEnv *env, jclass cls, jlong _pDst, jlong _pSrc, jint _size) {
	void* dst = (void*) _pDst;
	const void* src = (void*) _pSrc;
	size_t size = (size_t) _size;
	memcpy(dst, src, size);
}

