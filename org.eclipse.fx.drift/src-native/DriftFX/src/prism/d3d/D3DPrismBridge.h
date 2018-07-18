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

#ifndef PRISM_D3D_D3DPRISMBRIDGE_H_
#define PRISM_D3D_D3DPRISMBRIDGE_H_

#include <jni.h>

#include "gl/wgl/WGLGLContext.h"
#include "prism/PrismBridge.h"
#include "win32/D3D9ExContext.h"
#include "SharedTexture.h"

#include "NativeSurface.h"

namespace driftfx {
namespace internal {
namespace prism {
namespace d3d {
using namespace win32;

class D3DPrismBridge : public PrismBridge {

public:
	virtual GLContext* CreateSharedContext();

	virtual D3D9ExContext* GetJfxContext();

	virtual NativeSurface* CreateNativeSurface(JNINativeSurface* api);

	virtual int RecreateFXTexture(void* fxTexture, HANDLE shareHandle);

	static void Initialize(jlong pContext);
	static void Destroy();

protected:
	D3DPrismBridge(jlong pContext);
	virtual ~D3DPrismBridge();

	D3D9ExContext *jfxContext;

};


}
}
}
}


#endif /* PRISM_D3D_D3DPRISMBRIDGE_H_ */
