
#include <prism/PrismBridge.h>
#include <SharedTexture.h>
#include <MainMemorySharedTexture.h>
#include <functional>

#include <utils/Logger.h>

#include "ES2PrismBridge.h"

namespace driftfx {
namespace internal {
namespace prism {
namespace es2 {

using namespace std::placeholders;

class ES2MainMemorySharedTexture {


private:
	static int OnTextureCreated(PrismBridge* bridge, Frame* frame, jobject fxTexture) {
		LogDebug("OnTextureCreated(" << bridge << ", " << frame << ", " << fxTexture << ")");

		ES2PrismBridge* es2Bridge = dynamic_cast<ES2PrismBridge*>(bridge);

		LogDebug("Context is " << es2Bridge->GetFXSharedGLContext());

		// context is important
		es2Bridge->GetFXSharedGLContext()->SetCurrent();

		GLuint targetTex = es2Bridge->GetGLTextureName(fxTexture);
		auto t = frame->GetSharedTexture();
		if (t == nullptr) {
			return -1;
		}

		ShareData* data = frame->GetData();
		MainMemoryShareData* memData = (MainMemoryShareData*) data;

		es2Bridge->UploadTexture(targetTex, frame->GetWidth(), frame->GetHeight(), memData->pointer, memData->length);

		return 0;
	}

	static SharedTextureFactoryId registered;

};

SharedTextureFactoryId ES2MainMemorySharedTexture::registered = PrismBridge::Register(MainMemorySharedTexture::registered,
		[](PrismBridge* bridge, Frame* frame, jobject fxTexture) {
			return ES2MainMemorySharedTexture::OnTextureCreated(bridge, frame, fxTexture);
		});

		//std::bind((int(*)(PrismBridge*, Frame*, jobject))&ES2MainMemorySharedTexture::OnTextureCreated, _1, _2, _3));

}
}
}
}
