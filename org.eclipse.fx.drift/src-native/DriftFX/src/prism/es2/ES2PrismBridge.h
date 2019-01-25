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

#ifndef PRISM_ES2_ES2PRISMBRIDGE_H_
#define PRISM_ES2_ES2PRISMBRIDGE_H_

#include <jni.h>

#include "../PrismBridge.h"

namespace driftfx {
using namespace driftfx::gl;
namespace internal {
namespace prism {
namespace es2 {


class ES2PrismBridge : public PrismBridge {

public:
	virtual int CopyTexture(int sourceTex, int targetTex, int width, int height);
	virtual NativeSurface* CreateNativeSurface(JNINativeSurface* api);

protected:
	ES2PrismBridge(GLContext* fxContext);
	virtual ~ES2PrismBridge();

	GLContext *fxGLContext;

};


}
}
}
}


#endif /* PRISM_ES2_ES2PRISMBRIDGE_H_ */
