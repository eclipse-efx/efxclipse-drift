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

#include "SharedTexture.h"

#include <DriftFX/math/Vec2.h>

#include "Common.h"

using namespace driftfx::math;
using namespace driftfx::gl;
using namespace driftfx::internal;

SharedTexture::SharedTexture(GLContext* glContext, SurfaceData surfaceData, Vec2ui textureSize) :
		surfaceData(surfaceData),
		textureSize(textureSize), 
		glContext(glContext),
		glTexture(nullptr) {
}

SharedTexture::~SharedTexture() {
}

GLTexture* SharedTexture::GetTexture() {
	return glTexture;
}

unsigned int SharedTexture::GetGLTexture() {
	return glTexture->Name();
}

unsigned int SharedTexture::GetWidth() {
	return textureSize.x;
}

unsigned int SharedTexture::GetHeight() {
	return textureSize.y;
}
