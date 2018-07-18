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
#ifndef SHAREDSURFACE_WIN32_D3D9TEXTURE_H_
#define SHAREDSURFACE_WIN32_D3D9TEXTURE_H_

#define D3D_DEBUG_INFO
#include <d3d9.h>

#include <DriftFX/Texture.h>

namespace driftfx {
namespace internal {
namespace win32 {

class D3D9ExContext;
class D3D9Texture : public Texture {
	friend D3D9ExContext;

public:
	D3D9Texture(D3D9ExContext *context, int width, int height);
	virtual ~D3D9Texture();

	IDirect3DTexture9* GetTexture();
	HANDLE GetShareHandle();

protected:
	D3D9ExContext *context;

	IDirect3DTexture9 *texture;
	HANDLE textureShareHandle;

};

}
}
}

#endif /* SHAREDSURFACE_WIN32_D3D9TEXTURE_H_ */
