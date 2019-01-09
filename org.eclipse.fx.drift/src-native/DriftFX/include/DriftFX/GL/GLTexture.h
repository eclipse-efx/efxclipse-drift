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

#ifndef DRIFTFX_GL_GLTEXTURE_H_
#define DRIFTFX_GL_GLTEXTURE_H_

#include <GL/glew.h>

#include <DriftFX/Texture.h>
#include <DriftFX/GL/GLContext.h>

namespace driftfx {
namespace gl {

class GLTexture : public Texture {

public:
	GLTexture(GLContext *context, int width, int height);
	virtual ~GLTexture();

	GLuint Name();

protected:
	GLContext *context;
	GLuint textureName;

};

}
}


#endif /* DRIFTFX_GL_GLTEXTURE_H_ */
