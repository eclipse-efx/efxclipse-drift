/*
 * Copyright (c) 2018 BestSolution and Others. All rights reserved.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0, which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * This Source Code may also be made available under the following Secondary
 * Licenses when the conditions for such availability set forth in the
 * Eclipse Public License v. 2.0 are satisfied: GNU General Public License,
 * version 2 with the GNU Classpath Exception, which is available at
 * https://www.gnu.org/software/classpath/license.html.
 *
 * SPDX-License-Identifier: EPL-2.0 OR GPL-2.0 WITH Classpath-exception-2.0
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
