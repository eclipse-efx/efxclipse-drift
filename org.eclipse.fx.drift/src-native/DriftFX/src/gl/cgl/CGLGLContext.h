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
