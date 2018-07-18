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
#ifndef SHAREDSURFACE_WIN32_D3D9EXCONTEXT_H_
#define SHAREDSURFACE_WIN32_D3D9EXCONTEXT_H_

#define D3D_DEBUG_INFO
#include <d3d9.h>

#include <DriftFX/Context.h>
#include <DriftFX/Texture.h>

namespace driftfx {
namespace internal {
namespace win32 {

class D3D9Texture;
class D3D9ExContext : public Context {
	friend D3D9Texture;

public:
	D3D9ExContext();
	D3D9ExContext(IDirect3D9Ex* d3d9, IDirect3DDevice9Ex* device);

	virtual ~D3D9ExContext();

	virtual Texture* CreateTexture(int width, int height);

	virtual IDirect3D9Ex* GetD3D9();
	virtual IDirect3DDevice9Ex* Device();

private:

	IDirect3D9Ex* d3d9;
	IDirect3DDevice9Ex* d3d9Device;

	HWND hWnd;

	static LRESULT APIENTRY WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};

}
}
}

#endif /* SHAREDSURFACE_WIN32_D3D9EXCONTEXT_H_ */
