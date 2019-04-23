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

#include "D3DSharedFallbackTexture.h"

#include <utils/Logger.h>

#include "gl/InternalGLContext.h"

#include "SharedTexture.h"
#include "win32/Error.h"
#include "win32/D3D9ExContext.h"
#include "gl/wgl/WGLGLContext.h"

#include <DriftFX/math/Vec2.h>

#include <iostream>

using namespace std;

using namespace driftfx;
using namespace driftfx::math;

using namespace driftfx::internal;
using namespace driftfx::internal::gl;
using namespace driftfx::internal::gl::wgl;

using namespace driftfx::internal::prism::d3d;


void D3DSharedFallbackTexture::UploadPixels(D3D9Texture* texture, byte* pixels) {
	//LogDebug("Upload Pixels " << hex << texture->GetShareHandle() << " w: " << dec << texture->GetWidth() << ", h: " << dec << texture->GetHeight());
	D3DLOCKED_RECT tmp;
	auto start = chrono::steady_clock::now();
	WERR( texture->GetTexture()->LockRect(0, &tmp, NULL, D3DLOCK_DISCARD));

	byte* rowBits = (byte*) tmp.pBits;
	int sourcePitch = GetWidth() * 4 * sizeof(byte);
	for (unsigned int h = 0; h < GetHeight(); h++) {

		int offset = h * sourcePitch;
		memcpy(rowBits, (pixels + offset), sourcePitch);
		rowBits += tmp.Pitch;
	}

	WERR(texture->GetTexture()->UnlockRect(0));
	auto end = chrono::steady_clock::now();
	LogDebug("Uploading " << dec << texture->GetWidth() * texture->GetHeight() << "px needed " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns");

	// it seems if we lock the texture again in readonly it gets ready...
	// if we do not do this here it sometimes won't have any content..
	auto startSync = chrono::steady_clock::now();
	WERR(texture->GetTexture()->LockRect(0, &tmp, NULL, D3DLOCK_READONLY));

	//byte* data = (byte*) tmp.pBits;
	//LogDebug("1st D3D pixel: " << hex << (int)data[0] << (int)data[1] << (int)data[2] << (int)data[3]);

	WERR(texture->GetTexture()->UnlockRect(0));
	auto endSync = chrono::steady_clock::now();
	LogDebug("Relocking d3d tex for sync needed " << chrono::duration_cast<chrono::nanoseconds>(endSync - startSync).count() << "ns");
}

void D3DSharedFallbackTexture::DownloadPixels(GLTexture* texture, byte* pixels) {
	auto start = chrono::steady_clock::now();
	glBindTexture(GL_TEXTURE_2D, texture->Name());
	glGetTexImage(GL_TEXTURE_2D, 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
	glBindTexture(GL_TEXTURE_2D, 0); // TODO should we restore the previously bound texture?
	auto end = chrono::steady_clock::now();
	LogDebug("Downloading " << dec << texture->GetWidth() * texture->GetHeight() << "px needed " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns");


	/*
	auto s1 = chrono::steady_clock::now();
	GLuint buf;
	InternalGLContext::GenBuffers(1, &buf);
	LogDebug("my buf: " << dec << buf);


	InternalGLContext::BindBuffer(GL_PIXEL_PACK_BUFFER, buf);
	glBindTexture(GL_TEXTURE_2D, texture->Name());
	InternalGLContext::GetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) 0);
	GLsync pixelTransferDone = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);
	// Now i suspect texture is in pbo?

	auto status = glClientWaitSync(pixelTransferDone, 0, 1000000);
	if (status == GL_ALREADY_SIGNALED) LogDebug("GL_ALREADY_SIGNALED!!");
	if (status == GL_CONDITION_SATISFIED) LogDebug("GL_CONDITION_SATISFIED!!");
	if (status == GL_WAIT_FAILED) LogDebug("GL_WAIT_FAILED!!");
	if (status == GL_TIMEOUT_EXPIRED) LogDebug("GL_TIMEOUT_EXPIRED!!");
	byte *data = (byte*) InternalGLContext::MapBuffer(GL_PIXEL_PACK_BUFFER, GL_READ_ONLY);
	if (data != NULL) {
		LogDebug("1st pixel: " << hex << (int)data[0] << (int)data[1] << (int)data[2] << (int)data[3]);
		InternalGLContext::UnmapBuffer(GL_PIXEL_PACK_BUFFER);
	}
	InternalGLContext::BindBuffer(GL_PIXEL_PACK_BUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0); // TODO should we restore the previously bound texture?
	
	InternalGLContext::DeleteBuffers(1, &buf);
	auto e1 = chrono::steady_clock::now();
	LogDebug("Mapping " << dec << texture->GetWidth() * texture->GetHeight() << "px needed " << chrono::duration_cast<chrono::nanoseconds>(e1 - s1).count() << "ns");
	*/
}


D3DSharedFallbackTexture::D3DSharedFallbackTexture(GLContext* glContext, D3D9ExContext* d3dContext, SurfaceData surfaceData, Vec2ui textureSize) :
	SharedTexture(glContext, surfaceData, textureSize),
	d3dContext(d3dContext),
	d3dTexture(nullptr) {
	d3dTexture = new D3D9Texture(d3dContext, GetWidth(), GetHeight());
}

D3DSharedFallbackTexture::~D3DSharedFallbackTexture() {
	delete d3dTexture;
}

bool D3DSharedFallbackTexture::Connect() {
	glTexture = new GLTexture(glContext, GetWidth(), GetHeight());
	glBindTexture(GL_TEXTURE_2D, glTexture->Name());
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, GetWidth(), GetHeight(), 0, GL_BGRA, GL_UNSIGNED_BYTE, 0);
	glBindTexture(GL_TEXTURE_2D, 0); // TODO should we restore the previously bound texture?
	return true;
}

bool D3DSharedFallbackTexture::Disconnect() {

	size_t size = sizeof(byte) * 4 * GetWidth() * GetHeight();
	LogDebug("Using size: " << dec <<  size);

	byte* pixels = (byte*) malloc(size);

	DownloadPixels(glTexture, pixels);
	delete glTexture;

	UploadPixels(d3dTexture, pixels);

	free(pixels);

	return true;
}

bool D3DSharedFallbackTexture::Lock() {
	return true;
}

bool D3DSharedFallbackTexture::Unlock() {
	return true;
}

FrameData* D3DSharedFallbackTexture::CreateFrameData() {
	FrameData* data = new FrameData();
	data->id = (long long) this;
	data->d3dSharedHandle = (long long) d3dTexture->GetShareHandle();
	data->textureSize = textureSize;
	data->surfaceData = surfaceData;

	return data;
}
