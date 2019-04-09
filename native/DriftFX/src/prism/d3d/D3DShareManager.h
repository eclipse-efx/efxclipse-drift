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

#ifndef DRIFTFX_D3DSHAREMANAGER_H_
#define DRIFTFX_D3DSHAREMANAGER_H_

#include "../../ShareManager.h"

#include "../../win32/D3D9ExContext.h"
#include <DriftFX/GL/GLContext.h>

namespace driftfx {
namespace internal {
namespace prism {
namespace d3d {

class D3DShareManager : public ShareManager {
public:
	D3DShareManager(win32::D3D9ExContext* dx, driftfx::gl::GLContext* gl);
	virtual ~D3DShareManager();

protected:
	virtual void prepare();
	virtual void doPresent(RenderTarget* target);
	virtual void cleanup();

private:
	win32::D3D9ExContext* dxContext;
	driftfx::gl::GLContext* glContext;

	HANDLE shareDevice;
};

}
}
}
}

#endif