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

#ifndef _CGLGLCONTEXT_H_
#define _CGLGLCONTEXT_H_

#include "../../Common.h"

#include <DriftFX/GL/GLContext.h>

#include <OpenGL/CGLTypes.h>

#include "../InternalGLContext.h"

namespace driftfx {
namespace internal {
namespace gl {
namespace cgl {

class CGLGLContext : public InternalGLContext {

public:
	CGLGLContext();
	CGLGLContext(CGLContextObj contextObj, bool managed);
	virtual ~CGLGLContext();

	virtual void SetCurrent();
	virtual void UnsetCurrent();
	virtual bool IsCurrent();

	virtual GLContext* CreateSharedContext();

	virtual void* GetHandle();


private:
	CGLContextObj contextObj;
	bool managed;

};

}
}
}
}

#endif
