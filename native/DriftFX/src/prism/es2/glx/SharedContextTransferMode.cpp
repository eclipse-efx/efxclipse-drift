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

#include <GL/glew.h>

#include "GLXSharedTexture.h"

#include <utils/Logger.h>

#include <DriftFX/GL/GLDebug.h>

#include <DriftFX/math/Vec2.h>

#include <prism/PrismBridge.h>
#include <prism/es2/ES2PrismBridge.h>

#include <gl/GLLog.h>


namespace driftfx {
namespace internal {
namespace prims {
namespace es2 {
namespace glx {
	
class SharedContextTransferMode : public TransferMode {
	public:
	SharedTexture* CreateSharedTexture(GLContext* glContext, Context* fxContext, Frame* frame) {
		GLContext* fxGlContext = dynamic_cast<GLContext*>(fxContext);
		return new GLXSharedTexture(glContext, fxGlContext, frame);
	}
	int OnTextureCreated(prism::PrismBridge* bridge, Frame* frame, jobject fxTexture) {
			ES2PrismBridge* bridge = dynamic_cast<ES2PrismBridge*>(_bridge);
			ShareData* data = _frame->GetData();
			GLXShareData* shareData = (GLXShareData*) data;
			auto size = _frame->GetSize();
			GLuint targetTex = bridge->GetGLTextureName(_fxTexture);
			ES2PrismBridge::CopyTexture(shareData->textureName, targetTex, size.x, size.y);
			return 0;
	}
	virtual bool isPlatformDefault() {
		return true;
	}
	protected:
	SharedContextTransferMode() : TransferMode("SharedContext") {}
	static TransferModeId registered;
}

TransferModeId SharedContextTransferMode::registered = TransferModeManager::Instance()->RegisterTransferMode(new SharedContextTransferMode());

}
}
}
}
}
