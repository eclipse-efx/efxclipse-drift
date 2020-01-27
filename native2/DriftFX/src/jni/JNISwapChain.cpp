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

#include "JNISwapChain.h"
#include "jniutil.h"

using namespace driftfx::internal::jni;


jclass SwapChainImage::cls = nullptr;
jmethodID SwapChainImage::constructor = nullptr;


void SwapChainImage::Initialize(JNIEnv* env) {
	cls = ResolveClass(env, "org/eclipse/fx/drift/internal/SwapChainImage");
	cls = (jclass)env->NewGlobalRef(cls);
	constructor = ResolveMethod(env, cls, "<init>", "(JJI)V");
}

void SwapChainImage::Dispose(JNIEnv* env) {
	env->DeleteGlobalRef(cls);
	cls = nullptr;
	constructor = nullptr;
}

jobject SwapChainImage::New(JNIEnv* env, jlong pSwapChainImage, jlong pShareData, jint number) {
	return env->NewObject(cls, constructor, pSwapChainImage, pShareData, number);
}


jclass SwapChain::cls = nullptr;
jmethodID SwapChain::constructor = nullptr;
jmethodID SwapChain::present = nullptr;

void SwapChain::Initialize(JNIEnv* env) {
	cls = ResolveClass(env, "org/eclipse/fx/drift/internal/SwapChain");
	cls = (jclass) env->NewGlobalRef(cls);
	constructor = ResolveMethod(env, cls, "<init>", "(JIIIII)V");
	present = ResolveMethod(env, cls, "present", "(Lorg/eclipse/fx/drift/internal/SwapChainImage;)V");
}
void SwapChain::Dispose(JNIEnv* env) {
	env->DeleteGlobalRef(cls);
	cls = nullptr;
	constructor = nullptr;
}
jobject SwapChain::New(JNIEnv* env, jlong pSwapChain, jint width, jint height, jint transferMode, jint presentationMode, jint presentationHint) {
	return env->NewObject(cls, constructor, pSwapChain, width, height, transferMode, presentationMode, presentationHint);
}

void SwapChain::Present(JNIEnv* env, jobject swapChain, jobject frame) {
	env->CallVoidMethod(swapChain, present, frame);
}
jclass SwapChain::Class() {
	return cls;
}
