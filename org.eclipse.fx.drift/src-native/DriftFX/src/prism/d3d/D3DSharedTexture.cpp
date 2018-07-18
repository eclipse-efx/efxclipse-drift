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

#include "D3DSharedTexture.h"

#include <utils/Logger.h>

#include <GL/glew.h>
#include <GL/wglew.h>

#include "SharedTexture.h"
#include "win32/Error.h"
#include "win32/D3D9ExContext.h"
#include "gl/wgl/WGLGLContext.h"

#include <iostream>

using namespace std;

using namespace driftfx;

using namespace driftfx::internal;
using namespace driftfx::internal::gl::wgl;

using namespace driftfx::internal::prism::d3d;


mutex D3DSharedTexture::sharedDevicesMutex;
map<pair<IDirect3DDevice9Ex*, HGLRC>, HANDLE> D3DSharedTexture::sharedDevices;
map<HANDLE, int> D3DSharedTexture::sharedDevicesUsageCount;

HANDLE D3DSharedTexture::OpenSharedDevice(D3D9ExContext* d3dContext, GLContext* glContext) {
	LogDebug("OpenSharedDevice( " << d3dContext << ", " << glContext << ")");
	IDirect3DDevice9Ex* d3dDevice = d3dContext->Device();
	HGLRC glContxtHandle = dynamic_cast<WGLGLContext*>(glContext)->GetHandle();

	HGLRC curContext;
	WERR(curContext = wglGetCurrentContext(););
	if (glContxtHandle != curContext) {
		LogError("OpenSharedDevice called with wrong current gl context; This is FATAL!");
	}

	sharedDevicesMutex.lock();

	pair<IDirect3DDevice9Ex*, HGLRC> key = make_pair(d3dDevice, glContxtHandle);

	if (sharedDevices.count( key ) != 1) {
		LogDebug("NV_DX_interop: Opening Device " << d3dDevice);
		HANDLE nh;
		WERR(nh = wglDXOpenDeviceNV(d3dDevice);)
		sharedDevices[key] = nh;
		LogDebug("               -> " << nh);
	}

	HANDLE h = sharedDevices[key];

	if (sharedDevicesUsageCount.count( h ) == 0) {
		sharedDevicesUsageCount[h] = 0;
	}

	sharedDevicesUsageCount[h] = sharedDevicesUsageCount[h] + 1;

	sharedDevicesMutex.unlock();
	LogDebug("OpenSharedDevice returns " << h);
	return h;
}

void D3DSharedTexture::CloseSharedDevice(D3D9ExContext* d3dContext, GLContext* glContext) {
	IDirect3DDevice9Ex* d3dDevice = d3dContext->Device();
	HGLRC glContxtHandle = dynamic_cast<WGLGLContext*>(glContext)->GetHandle();

	HGLRC curContext;
	WERR(curContext = wglGetCurrentContext(););
	if (glContxtHandle != curContext) {
		LogError("CloseSharedDevice called with wrong current gl context; This is FATAL!");
	}

	sharedDevicesMutex.lock();

	pair<IDirect3DDevice9Ex*, HGLRC> key = make_pair(d3dDevice, glContxtHandle);

	if (sharedDevices.count( key ) == 1) {
		HANDLE h = sharedDevices[key];
		int usages = sharedDevicesUsageCount[h];
		usages -= 1;

		if (usages == 0) {
			LogDebug("NV_DX_interop: Closing Device: " << d3dDevice);
			WERR(wglDXCloseDeviceNV(h););
			sharedDevices.erase(key);
			sharedDevicesUsageCount.erase(h);
			LogDebug("               -> closed.");
		}
		else {
			sharedDevicesUsageCount[h] = usages;
			LogDebug("NV_DX_interop: Not Closing Device: " << d3dDevice << " still used by " << usages << " others");
		}
	}
	else {
		LogError("NV_DX_interop: No open device found!");
	}

	sharedDevicesMutex.unlock();
}

D3DSharedTexture::D3DSharedTexture(GLContext* glContext, D3D9ExContext* d3dContext, unsigned int width, unsigned int height) :
	SharedTexture(glContext, width, height),
	d3dContext(d3dContext),
	d3dTexture(nullptr),
	hDevice(nullptr),
	hObject(nullptr) {


	d3dTexture = new D3D9Texture(d3dContext, width, height);

}

D3DSharedTexture::~D3DSharedTexture() {
	LogDebug("destroy tex");

	delete d3dTexture;

}

bool D3DSharedTexture::Connect() {
	if (glTexture != nullptr) return false;
	glTexture = new GLTexture(glContext, GetWidth(), GetHeight());
	hDevice = OpenSharedDevice(d3dContext, glContext);
	WERR( wglDXSetResourceShareHandleNV(d3dTexture->GetTexture(), d3dTexture->GetShareHandle()); );
	WERR( hObject = wglDXRegisterObjectNV(hDevice, d3dTexture->GetTexture(), glTexture->Name(), GL_TEXTURE_2D, WGL_ACCESS_READ_WRITE_NV); );
	return hObject != 0;
}

bool D3DSharedTexture::Disconnect() {
	WERR( wglDXUnregisterObjectNV( hDevice, hObject ); );
	delete glTexture; glTexture = nullptr;
	CloseSharedDevice(d3dContext, glContext);
	return true;
}

bool D3DSharedTexture::Lock() {
	bool success = false;
	WERR( success = wglDXLockObjectsNV( hDevice, 1, &hObject ); );
	return success;
}

bool D3DSharedTexture::Unlock() {
	bool success = false;
	WERR( success = wglDXUnlockObjectsNV( hDevice, 1, &hObject ); );
	return success;
}

FrameData* D3DSharedTexture::CreateFrameData() {
	FrameData* data = new FrameData();
	data->d3dSharedHandle = (long long) d3dTexture->GetShareHandle();
	data->height = GetHeight();
	data->width = GetWidth();
	return data;
}

SharedTexture* SharedTexture::Create(GLContext* glContext, Context* fxContext, unsigned int width, unsigned int height) {
	D3D9ExContext* d3dContext = dynamic_cast<D3D9ExContext*>(fxContext);
	return new D3DSharedTexture(glContext, d3dContext, width, height);
}

