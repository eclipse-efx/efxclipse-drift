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


#include <DriftFX/RenderTarget.h>
#include "GLRenderTarget.h"

#include <gl/glew.h>

#include <iostream>

using namespace driftfx;
using namespace driftfx::internal;

GLRenderTarget::GLRenderTarget(DriftFXSurface* surface, unsigned int width, unsigned int height) :
	surface(surface),
	width(width),
	height(height),
	glTexture(0)

{
	glGenTextures(1, &glTexture);
	glBindTexture(GL_TEXTURE_2D, glTexture);
	
	//unsigned int *pixels = (unsigned int*)malloc(width * height * sizeof(unsigned int));
	//for (int idx = 0; idx < width * height; idx++) {
	//	pixels[idx] = 0xFF0000FF;
	//}
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
	
}
GLRenderTarget::~GLRenderTarget() {
	glDeleteTextures(1, &glTexture);
}

unsigned int GLRenderTarget::GetGLTexture() {
	return glTexture;
}

unsigned int GLRenderTarget::GetWidth() {
	return width;
}

unsigned int GLRenderTarget::GetHeight() {
	return height;
}

DriftFXSurface* GLRenderTarget::GetSurface() {
	return surface;
}
