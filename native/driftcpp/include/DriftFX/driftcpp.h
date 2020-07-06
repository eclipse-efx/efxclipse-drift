
#ifndef _DRIFTCPP_H_
#define _DRIFTCPP_H_

#include <string>
#include <jni.h>

#include "Export.h"


#ifndef GLuint
typedef unsigned int GLuint;
#endif

namespace driftfx {

	struct Vec2i {
		int x;
		int y;
	};

	class TransferType {
	public:
		virtual ::std::string getId() = 0;
		virtual bool isAvailable() = 0;
	};

	class RenderTarget {
	};

	struct SwapchainConfig {
		Vec2i size;
		int imageCount;
		TransferType* transferType;
	};

	class Swapchain {
	public:
		virtual SwapchainConfig getConfig() = 0;
		virtual RenderTarget* acquire() = 0;
		virtual RenderTarget* tryAcquire() = 0;

		virtual void present(RenderTarget* image) = 0;

		virtual ~Swapchain() = 0;
	};



	class Renderer {
	public:
		virtual Swapchain* createSwapchain(SwapchainConfig config) = 0;
		virtual Vec2i getSize() = 0;
		virtual ~Renderer() = 0;
	};

	class GLRenderer {
	public:
		DRIFTCPP_EXPORT static GLuint getGLTextureId(RenderTarget* renderTarget);

	};


	// api entry point
	DRIFTCPP_EXPORT Renderer* initializeRenderer(JNIEnv* env, jobject javaRenderer);


	class StandardTransferTypes {
	public:
		DRIFTCPP_EXPORT static TransferType* MainMemory;
		DRIFTCPP_EXPORT static TransferType* IOSurface;
		DRIFTCPP_EXPORT static TransferType* NVDXInterop;
	};
	 
	

}

#endif // _DRIFTCPP_H_