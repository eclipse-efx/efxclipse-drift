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
#ifndef DRIFTFX_GL_INTERNAL_INTERNALGLCONTEXT_H_
#define DRIFTFX_GL_INTERNAL_INTERNALGLCONTEXT_H_

#include <DriftFX/GL/GLContext.h>

#include <GL/glew.h>

namespace driftfx {
namespace internal {
namespace gl {


class InternalGLContext : public driftfx::gl::GLContext {

public:
	InternalGLContext();
	virtual ~InternalGLContext();

	static GLenum glGetError();
	static void glGenTextures(GLsizei n, GLuint* textures);
	static void glDeleteTextures(GLsizei n, GLuint* textures);
	static void glBindTexture(GLenum target, GLuint texture);
//	static void glGenFramebuffers(GLsizei n, GLuint* ids);
//	static void glDeleteFramebuffers(GLsizei n, GLuint* ids);
//	static void glBindFramebuffer(GLenum target, GLuint id);
//	static GLenum glCheckFramebufferStatus(GLenum target);
//	static void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
//	static void glClear();
//	static void glFlush();
//	static void glFinish();


	static void Initialize();
	static void Cleanup();
protected:
	static void* resolve(const GLubyte* name);

	static long instanceCount;
	static bool initialized;
};

}
}
}

#endif /* DRIFTFX_GL_INTERNAL_INTERNALGLCONTEXT_H_ */
