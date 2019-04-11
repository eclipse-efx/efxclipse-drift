#include "D3DShareManager.h"
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
#include <GL/wglew.h>

#include <utils/JNIHelper.h>

#include "D3DShareManager.h"

#include "../../win32/D3D9Texture.h"
#include "../../gl/wgl/WGLGLContext.h"

#include "../../NativeSurface.h"



#include "win32/Error.h"
#include <iostream>
using namespace std;

#include <utils/Logger.h>

using namespace driftfx;
using namespace driftfx::internal;
using namespace driftfx::internal::prism;
using namespace driftfx::internal::prism::d3d;

using namespace driftfx::internal::gl;
using namespace driftfx::internal::gl::wgl;
using namespace driftfx::internal::win32;

D3DShareManager::D3DShareManager(D3D9ExContext * dx, GLContext * gl) : ShareManager(),
	dxContext(dx),
	glContext(gl)
{
}

#ifndef GLERR
#define GLERR(code) code
#endif

D3DShareManager::~D3DShareManager() {
}

void CopyGLTexture(GLuint sourceTex, GLuint targetTex, int width, int height) {
	// COPY OVER
	GLuint fbos[2];

	GLERR(glGenFramebuffers(2, &fbos[0]); );

	GLERR(glBindFramebuffer(GL_READ_FRAMEBUFFER, fbos[0]); );
	GLERR(glFramebufferTexture(GL_READ_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, sourceTex, 0); );

	GLERR(glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fbos[1]); );
	GLERR(glFramebufferTexture(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, targetTex, 0); );

	GLERR(glClearColor(0, 0, 0, 0); );
	GLERR(glClear(GL_COLOR_BUFFER_BIT); );

	GLERR(glBlitFramebuffer(0, 0, width, height, 0, 0, width, height, GL_COLOR_BUFFER_BIT, GL_LINEAR); );

	// We need to wait here for the blit operation to finish to prevent copying an empty texture in FX context
	//glFinish();

	GLsync blitFence = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);
	glClientWaitSync(blitFence, 0, 0);

	GLERR(glDeleteFramebuffers(2, &fbos[0]); );
}

void D3DShareManager::doPresent(RenderTarget* target) {
	LogDebug("doPresent");
	int width = target->GetWidth();
	int height = target->GetHeight();

	
	D3D9Texture* dxTex = new D3D9Texture(dxContext, width, height);

	GLuint sourceTex = target->GetGLTexture();

	//unsigned int *pixels = (unsigned int*) malloc(width * height * sizeof(unsigned int));
	//for (int idx = 0; idx < width * height; idx++) {
	//	pixels[idx] = 0;
	//}
	//glBindTexture(GL_TEXTURE_2D, sourceTex);
	//glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, pixels);
	//glBindTexture(GL_TEXTURE_2D, 0);
	////for (int i = 0; i < 100; i++) {
	//	LogDebug("Pixel: " << std::hex << pixels[0]);
	////}
	//GLuint fbos[2];
	//glGenFramebuffers(2, fbos);

	//// setup source
	//glBindFramebuffer(GL_READ_FRAMEBUFFER, fbos[0]);
	//glFramebufferTexture(GL_READ_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, sourceTex, 0);

	//glNamedFramebufferTexture(fbos[0], GL_COLOR_ATTACHMENT0, glTex, 0);

	// prepare target tex
	GLuint targetTex;
	glGenTextures(1, &targetTex);

	LogDebug("DX_GL_interop register object ");
	wglDXSetResourceShareHandleNV(dxTex->GetTexture(), dxTex->GetShareHandle());
	HANDLE shareObject = wglDXRegisterObjectNV(shareDevice, dxTex->GetTexture(), targetTex, GL_TEXTURE_2D, WGL_ACCESS_READ_WRITE_NV);

	LogDebug("DX_GL_interop lock object ");
	if (!wglDXLockObjectsNV(shareDevice, 1, &shareObject)) {
		LogError("lock failed");
	}

	CopyGLTexture(sourceTex, targetTex, width, height);


	//glBindTexture(GL_TEXTURE_2D, blub);
	//glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, pixels);
	//glBindTexture(GL_TEXTURE_2D, 0);
	//LogDebug("Target Pixel B: " << std::hex << pixels[0]);

	//// setup target
	//glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fbos[1]);
	//glFramebufferTexture(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, sourceTex, 0);

	//GLenum r = glCheckFramebufferStatus(GL_READ_FRAMEBUFFER);
	//GLenum d = glCheckFramebufferStatus(GL_DRAW_FRAMEBUFFER);
	//LogDebug("r: " << r << ", d: " << d);
	////glNamedFramebufferTexture(fbos[1], GL_COLOR_ATTACHMENT0, blub, 0);

	//glBlitFramebuffer(0, 0, width, height, 0, 0, width, height, GL_COLOR_BUFFER_BIT, GL_LINEAR);
	////glBlitNamedFramebuffer(fbos[0], fbos[1], 0, 0, width, height, 0, 0, width, height, GL_COLOR_BUFFER_BIT, GL_LINEAR);
	//GLenum err = glGetError();
	//LogDebug("Blit err: " << err);
	//
	//glBindFramebuffer(GL_FRAMEBUFFER, fbos[1]);
	//glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, sourceTex, 0);
	//glClearColor(1, 0, 0, 1);
	//glClear(GL_COLOR_BUFFER_BIT);
	//glFlush();
	//glFinish();

	//glBindTexture(GL_TEXTURE_2D, blub);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, pixels);
	//glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, pixels);
	//LogDebug("Target Pixel A: " << std::hex << pixels[0]);
	//glBindTexture(GL_TEXTURE_2D, 0);

	LogDebug("DX_GL_interop unlock object ");
	if (!wglDXUnlockObjectsNV(shareDevice, 1, &shareObject)) {
		LogError("unlock failed");
	}

	LogDebug("DX_GL_interop unregister object ");
	if (!wglDXUnregisterObjectNV(shareDevice, shareObject)) {
		LogError("unregister failed");
	}

	//glDeleteFramebuffers(2, fbos);

	WERR(;);

	// call java with data
	// surfaceId, dxTex->GetShareHandle(), width, height

	NativeSurface* nativeSurface = dynamic_cast<NativeSurface*>(target->GetSurface());
	
	FrameData fd;
	fd.width = width;
	fd.height = height;
	fd.d3dSharedHandle = (long long) dxTex->GetShareHandle();
	fd.presentationHint = CENTER;

	LogDebug("Presenting " << fd.d3dSharedHandle << " " << width << " x " << height);

	nativeSurface->GetAPI()->Present(fd);

	LogDebug("doPresent finished");
}

void D3DShareManager::prepare()
{
	JNIHelper::AttachThread();

	glContext->SetCurrent();
	glewInit();

	LogDebug("ShareManager ctx " << glContext->IsCurrent());
	HGLRC glCtx = dynamic_cast<WGLGLContext*>(glContext)->GetHandle();

	shareDevice = wglDXOpenDeviceNV(dxContext->Device());
	LogDebug("shareDevice = " << shareDevice);
}

void D3DShareManager::cleanup() {

	wglDXCloseDeviceNV(shareDevice);


	JNIHelper::ReleaseThread();
}
