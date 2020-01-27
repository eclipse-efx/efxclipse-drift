
#include <prism/PrismBridge.h>
#include <SharedTexture.h>
#include <MainMemorySharedTexture.h>
#include <functional>

#include <utils/Logger.h>

#include "ES2PrismBridge.h"

#include <jni.h>

namespace driftfx {
namespace internal {
namespace prism {
namespace es2 {

using namespace std::placeholders;


class MainMemoryTransferMode : TransferModeImpl {
public:
	SharedTexture* CreateSharedTexture(GLContext* glContext, Context* fxContext, math::Vec2ui size) {
    	return new MainMemorySharedTexture(glContext, size);
	}
	ShareData* CreateShareData(SharedTexture* texture) {
		ShareData* data = texture->CreateShareData();
		data->transferMode = Id();
		return data;
	}
	int OnTextureCreated(prism::PrismBridge* bridge, ShareData* shareData, jobject fxTexture) {
		//LogDebug("OnTextureCreated(" << bridge << ", " << frame << ", " << fxTexture << ")");

		MainMemoryShareData* memData = (MainMemoryShareData*)shareData;
		ES2PrismBridge* es2Bridge = dynamic_cast<ES2PrismBridge*>(bridge);

		// context is important
		es2Bridge->GetFXSharedGLContext()->SetCurrent();

		GLuint targetTex = es2Bridge->GetGLTextureName(fxTexture);

		es2Bridge->UploadTexture(targetTex, memData->size.x, memData->size.y, memData->pointer, memData->length);

		return 0;
    }
	virtual bool isFallback() {
		return true;
	}
protected:
	MainMemoryTransferMode() : TransferModeImpl("MainMemory") {}
	static TransferModeId registered;
};

TransferModeId MainMemoryTransferMode::registered = TransferModeManager::Instance()->RegisterTransferMode(new MainMemoryTransferMode());

}
}
}
}
