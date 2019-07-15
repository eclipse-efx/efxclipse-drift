
#include <functional>
#include <iostream>
#include <iomanip>
#include <chrono>

#include <prism/PrismBridge.h>
#include <SharedTexture.h>
#include <MainMemorySharedTexture.h>

#include <utils/Logger.h>

#include "D3DPrismBridge.h"


#include <win32/Error.h>


#include <prism/d3d/include/java8/D3DContext.h>

namespace driftfx {
namespace internal {
namespace prism {
namespace d3d {


using namespace std::placeholders;

class D3DMainMemorySharedTexture {


public:
	static int OnTextureCreated(PrismBridge* bridge, Frame* frame, jobject fxTexture) {
		LogDebug("OnTextureCreated(" << bridge << ", " << frame << ", " << fxTexture << ")");

		ShareData* data = frame->GetData();
		MainMemoryShareData* mmdata = (MainMemoryShareData*)data;


		auto pixels = (byte*) mmdata->pointer;

		D3DPrismBridge* d3dBridge = dynamic_cast<D3DPrismBridge*>(bridge);

		void* resourceHandle = d3dBridge->GetD3DResourceHandle(fxTexture);
		java8::D3DResource* d3dResource = (java8::D3DResource*) resourceHandle;

		IDirect3DTexture9* texture = d3dResource->pTexture;
	
		
		// upload to D3D texture
		auto size = frame->GetSize();
		
		D3DLOCKED_RECT tmp;
		auto start = std::chrono::steady_clock::now();
		WERR(texture->LockRect(0, &tmp, NULL, D3DLOCK_DISCARD));

		byte* rowBits = (byte*)tmp.pBits;
		int sourcePitch = size.x * 4 * sizeof(byte);
		for (unsigned int h = 0; h < size.y; h++) {

			int offset = h * sourcePitch;
			memcpy(rowBits, (pixels + offset), sourcePitch);
			rowBits += tmp.Pitch;
		}

		WERR(texture->UnlockRect(0));
		auto end = std::chrono::steady_clock::now();
		LogDebug("Uploading " << std::dec << size.x * size.y << "px needed " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns");

		// it seems if we lock the texture again in readonly it gets ready...
		// if we do not do this here it sometimes won't have any content..
		auto startSync = std::chrono::steady_clock::now();
		WERR(texture->LockRect(0, &tmp, NULL, D3DLOCK_READONLY));

		//byte* data = (byte*) tmp.pBits;
		//LogDebug("1st D3D pixel: " << hex << (int)data[0] << (int)data[1] << (int)data[2] << (int)data[3]);

		WERR(texture->UnlockRect(0));
		auto endSync = std::chrono::steady_clock::now();
		LogDebug("Relocking d3d tex for sync needed " << std::chrono::duration_cast<std::chrono::nanoseconds>(endSync - startSync).count() << "ns");




		//LogDebug("Context is " << es2Bridge->GetFXSharedGLContext());

		//// context is important
		//es2Bridge->GetFXSharedGLContext()->SetCurrent();

		//GLuint targetTex = es2Bridge->GetGLTextureName(fxTexture);
		//auto t = frame->GetSharedTexture();
		//if (t == nullptr) {
		//	return -1;
		//}
		//LogDebug("Shared Texture is " << t);
		//MainMemorySharedTexture* sharedTex = dynamic_cast<MainMemorySharedTexture*>(t);
		//es2Bridge->UploadTexture(targetTex, frame->GetWidth(), frame->GetHeight(), sharedTex->GetPointer(), sharedTex->GetLength());

		return 0;
	}

	static SharedTextureFactoryId registered;

};

SharedTextureFactoryId D3DMainMemorySharedTexture::registered = PrismBridge::Register(MainMemorySharedTexture::registered,
		[](PrismBridge* bridge, Frame* frame, jobject fxTexture) {
			return D3DMainMemorySharedTexture::OnTextureCreated(bridge, frame, fxTexture);
		});

		//std::bind((int(*)(PrismBridge*, Frame*, jobject))&ES2MainMemorySharedTexture::OnTextureCreated, _1, _2, _3));

}
}
}
}
