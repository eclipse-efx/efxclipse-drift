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
#ifndef PRISM_ES2_GLX_GLXSHAREDTEXTURE_H_
#define PRISM_ES2_GLX_GLXSHAREDTEXTURE_H_

#include <GL/gl.h>
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
