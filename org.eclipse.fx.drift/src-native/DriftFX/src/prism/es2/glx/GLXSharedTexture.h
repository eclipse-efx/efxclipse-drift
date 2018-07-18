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
#ifndef PRISM_ES2_GLX_GLXSHAREDTEXTURE_H_
#define PRISM_ES2_GLX_GLXSHAREDTEXTURE_H_

#include <DriftFX/GL/GLContext.h>

#include "SharedTexture.h"

namespace driftfx {
using namespace gl;
namespace internal {
namespace prism {
namespace es2 {
namespace glx {


class GLXSharedTexture : public SharedTexture {

private:
	GLContext* fxContext;

	GLsync frameDone;

public:

	GLXSharedTexture(GLContext* context, GLContext* fxContext, int width, int height);
	virtual ~GLXSharedTexture();

	virtual bool Connect();
	virtual bool Disconnect();

	virtual bool Lock();
	virtual bool Unlock();

	virtual FrameData* CreateFrameData();

};

}
}
}
}
}

#endif /* PRISM_ES2_GLX_GLXSHAREDTEXTURE_H_ */
