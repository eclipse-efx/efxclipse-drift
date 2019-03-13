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

#include <GL/glew.h>
#include "../Common.h"
#include <iomanip>

#include <DriftFX/GL/GLTexture.h>
#include <DriftFX/Texture.h>

#include <DriftFX/GL/GLDebug.h>

#include "InternalGLContext.h"

using namespace driftfx;
using namespace driftfx::gl;

using namespace driftfx::internal::gl;

GLTexture::GLTexture(GLContext *context, int width, int height) : Texture(width, height),
	context(context),
	textureName(0) {

	context->SetCurrent();

	logGLErr(InternalGLContext::glGenTextures(1, &textureName););

	// TODO check for error & if textureName is valid
}

GLTexture::~GLTexture() {

	context->SetCurrent();

	glDeleteTextures(1, &textureName);
}

GLuint GLTexture::Name() {
	return textureName;
}
