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

#include "GLXSharedTexture.h"

#include <utils/Logger.h>

#include <DriftFX/GL/GLDebug.h>

using namespace driftfx::internal;
using namespace driftfx::internal::prism::es2::glx;

GLXSharedTexture::GLXSharedTexture(GLContext* context, GLContext* fxContext, int width, int height) :
	SharedTexture(glContext, width, height),
	fxContext(fxContext) {

	context->SetCurrent();

	glTexture = dynamic_cast<GLTexture*>(context->CreateTexture(width, height));

	GLERR(glBindTexture(GL_TEXTURE_2D, glTexture->Name()););
	GLERR(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, NULL););
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, NULL);
	GLERR(glBindTexture(GL_TEXTURE_2D, 0););

}
GLXSharedTexture::~GLXSharedTexture() {
	LogDebug("destroying tex " << glTexture->Name());
	delete glTexture;
}

bool GLXSharedTexture::Connect() {
	return true;
}

bool GLXSharedTexture::Disconnect() {
	frameDone = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);
	//glFinish();

	GLenum state = glClientWaitSync(frameDone, GL_SYNC_FLUSH_COMMANDS_BIT, 1000000000);
	switch (state) {
	case GL_ALREADY_SIGNALED: LogDebug("frameDone sync already signaled"); break;
	case GL_TIMEOUT_EXPIRED: LogError("frameDone sync timed out!"); break;
	case GL_CONDITION_SATISFIED: LogDebug("frameDone sync awaited"); break;
	case GL_WAIT_FAILED: LogError("frameDone sync failed!"); break;
	}
	return true;
}

bool GLXSharedTexture::Lock() {
	return true;
}

bool GLXSharedTexture::Unlock() {
	return true;
}

FrameData* GLXSharedTexture::CreateFrameData() {


	FrameData* data = new FrameData();
	data->width = GetWidth();
	data->height = GetHeight();
	data->glTextureName = glTexture->Name();
	return data;
}

SharedTexture* SharedTexture::Create(GLContext* context, Context* fxContext, unsigned int width, unsigned int height) {
	return new GLXSharedTexture(context, dynamic_cast<GLContext*>(fxContext), width, height);
}


