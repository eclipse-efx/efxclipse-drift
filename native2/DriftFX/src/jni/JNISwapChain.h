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
#ifndef JNI_SWAPCHAIN_H_
#define JNI_SWAPCHAIN_H_

#include <jni.h>
#include <SharedTextureSwapChain.h>

namespace driftfx {
namespace internal {

namespace jni {

class SwapChainImage {
public:
	static void Initialize(JNIEnv* env);
	static void Dispose(JNIEnv* env);

	static jobject New(JNIEnv* env, jlong pSwapChainImage, jlong pShareData, jint number);

private:
	static jclass cls;
	static jmethodID constructor;

};

class SwapChain {
public:
	static void Initialize(JNIEnv* env);
	static void Dispose(JNIEnv* env);

	static jobject New(JNIEnv* env, jlong pSwapChain, jint width, jint height, jint transferMode, jint presentationMode, jint presentationHint);
	static void Present(JNIEnv* env, jobject swapChain, jobject frame);

	static jclass Class();
private:
	static jclass cls;
	static jmethodID constructor;
	static jmethodID present;
};

}
}
}

#endif
