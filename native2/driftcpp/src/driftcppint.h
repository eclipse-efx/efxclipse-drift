#ifndef _DRIFTCPP_INT_H_
#define _DRIFTCPP_INT_H_

#include <DriftFX/driftcpp.h>
#include <jni.h>

namespace driftfx {

	class JNI {
	public:
		static void init(JNIEnv* env);
		static void dispose(JNIEnv* env);


	// Vec2i
	private:
		static jclass cVec2i;
		static jmethodID mVec2iConstructor;
		static jfieldID fVec2iX;
		static jfieldID fVec2iY;
	public:
		static Vec2i convertVec2i(JNIEnv* env, jobject vec2i);
		static jobject convertVec2i(JNIEnv* env, Vec2i vec2i);

	// SwapchainConfig
	private:
		static jclass cSwapchainConfig;
		static jmethodID mSwapchainConfigConstructor;
		static jfieldID fSwapchainConfigSize;
		static jfieldID fSwapchainConfigImageCount;
		static jfieldID fSwapchainConfigPresentationMode;
		static jfieldID fSwapchainConfigTransferType;
	public:
		static jobject convertSwapchainConfig(JNIEnv* env, SwapchainConfig swapchainConfig);
		static SwapchainConfig convertSwapchainConfig(JNIEnv* env, jobject swapchainConfig);
	// Swapchain
	private:
		static jmethodID mSwapchainAcquire;
		static jmethodID mSwapchainTryAcquire;
		static jmethodID mSwapchainPresent;
		static jmethodID mSwapchainDispose;
		static jmethodID mSwapchainGetConfig;
	public:
		static jobject callSwapchainAcquire(JNIEnv* env, jobject swapchain);
		static jobject callSwapchainTryAcquire(JNIEnv* env, jobject swapchain);
		static void callSwapchainPresent(JNIEnv* env, jobject swapchain, jobject renderTarget);
		static void callSwapchainDispose(JNIEnv* env, jobject swapchain);
		static jobject callSwapchainGetConfig(JNIEnv* env, jobject swapchain);
	// Renderer
	private:
		static jmethodID mRendererGetSize;
		static jmethodID mRendererCreateSwapchain;
	public:
		static jobject callRendererGetSize(JNIEnv* env, jobject renderer);
		static jobject callRendererCreateSwapchain(JNIEnv* env, jobject renderer, jobject swapchainConfig);

	// GLRenderer
	private:
		static jclass cGLRenderer;
		static jmethodID mGLRendererGetGLTextureId;
	public:
		static jint callGLRendererGetGLTextureId(JNIEnv* env, jobject renderTarget);
	};


	class JNIObject {
	protected:
		JNIEnv* env;
		jobject javaInstance;
	public:
		jobject getJavaInstance();
		JNIEnv* getJavaEnv();
	};


	class RendererImpl : public Renderer, public JNIObject {

	public:
		RendererImpl(JNIEnv* _env, jobject _javaInstance);

		Swapchain* createSwapchain(SwapchainConfig config);

		Vec2i getSize();

	};

	class SwapchainImpl : public Swapchain, public JNIObject {

	public:
		SwapchainImpl(JNIEnv* _env, jobject _javaInstance);

		SwapchainConfig getConfig();
		RenderTarget* acquire();
		RenderTarget* tryAcquire();
		void present(RenderTarget* image);
		
		~SwapchainImpl();

	};

	class RenderTargetImpl : public RenderTarget, public JNIObject {

	public:
		RenderTargetImpl(JNIEnv* _env, jobject _javaInstance);

	};

	class TransferTypeImpl : public TransferType, public JNIObject {

	public:
		TransferTypeImpl(JNIEnv* _env, jobject _javaInstance);
		::std::string getId();
		bool isAvailable();

	};

}

#endif // _DRIFTCPP_H_