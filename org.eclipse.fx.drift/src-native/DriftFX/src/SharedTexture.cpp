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

#include "SharedTexture.h"

#include "Common.h"

using namespace driftfx::gl;
using namespace driftfx::internal;

SharedTexture::SharedTexture(GLContext* glContext, unsigned int width, unsigned int height) :
		width(width), height(height),
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
	return width;
}

unsigned int SharedTexture::GetHeight() {
	return height;
}
