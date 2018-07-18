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
#ifndef DRIFTFX_INTERNAL_GL_GLX_GLXGLCONTEXT_H_
#define DRIFTFX_INTERNAL_GL_GLX_GLXGLCONTEXT_H_

#include <DriftFX/GL/GLContext.h>

#include <X11/Xlib.h>
//#include <GL/glx.h>
#include <GL/glxew.h>

namespace driftfx {
using namespace gl;
namespace internal {
namespace gl {
namespace glx {


class GLXGLContext : public GLContext {

public:
	GLXGLContext(GLXContext* context, Drawable* drawable);

	GLXGLContext();
	GLXGLContext(GLXGLContext* shared);
	GLXGLContext(GLXContext glxContext);
	virtual ~GLXGLContext();

	virtual void SetCurrent();
	virtual void UnsetCurrent();

	virtual GLContext* CreateSharedContext();
	virtual GLXContext GetHandle();

private:
	Display* display;
	GLXContext glxContext;
	GLXPbuffer pBuffer;
};

}
}
}
}

#endif /* DRIFTFX_INTERNAL_GL_GLX_GLXGLCONTEXT_H_ */
