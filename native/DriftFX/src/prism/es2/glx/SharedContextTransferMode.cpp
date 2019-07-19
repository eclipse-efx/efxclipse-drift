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

#include <TransferModeManager.h>

#include <GL/glew.h>

#include <prism/es2/glx/GLXSharedTexture.h>

#include <utils/Logger.h>

#include <DriftFX/GL/GLDebug.h>

#include <DriftFX/math/Vec2.h>

#include <prism/PrismBridge.h>
#include <prism/es2/ES2PrismBridge.h>

#include <gl/GLLog.h>


namespace driftfx {
namespace internal {
namespace prism {
namespace es2 {
namespace glx {
	
class SharedContextTransferMode : public TransferMode {
	public:
	SharedTexture* CreateSharedTexture(GLContext* glContext, Context* fxContext, Frame* frame) {
		GLContext* fxGlContext = dynamic_cast<GLContext*>(fxContext);
		return new GLXSharedTexture(glContext, fxGlContext, frame);
	}
	int OnTextureCreated(prism::PrismBridge* bridge, Frame* frame, jobject fxTexture) {
			ES2PrismBridge* es2Bridge = dynamic_cast<ES2PrismBridge*>(bridge);
			ShareData* data = frame->GetData();
			GLXShareData* shareData = (GLXShareData*) data;
			auto size = frame->GetSize();
			GLuint targetTex = es2Bridge->GetGLTextureName(fxTexture);
			ES2PrismBridge::CopyTexture(shareData->textureName, targetTex, size.x, size.y);
			return 0;
	}
	virtual bool isPlatformDefault() {
		return true;
	}
	protected:
	SharedContextTransferMode() : TransferMode("SharedContext") {}
	static TransferModeId registered;
};

TransferModeId SharedContextTransferMode::registered = TransferModeManager::Instance()->RegisterTransferMode(new SharedContextTransferMode());

}
}
}
}
}
