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

#include <utils/Logger.h>

#include "win32/D3D9ExContext.h"
#include "D3DNativeSurface.h"

using namespace driftfx;
using namespace driftfx::internal::win32;
using namespace driftfx::internal::prism::d3d;

D3DNativeSurface::D3DNativeSurface(JNINativeSurface* api) :
	NativeSurface(api),
	fxContext(nullptr) {

}

D3DNativeSurface::~D3DNativeSurface() {

	delete fxContext;
	fxContext = nullptr;
}

void D3DNativeSurface::Initialize() {
	NativeSurface::Initialize();

	LogDebug("init D3DContext");
	fxContext = new D3D9ExContext();
}

void D3DNativeSurface::Cleanup() {
	NativeSurface::Cleanup();

	LogDebug("clean D3DContext");
	delete fxContext;
	fxContext = nullptr;
}


Context* D3DNativeSurface::GetFxContext() {
	return fxContext;
}


//NativeSurface* NativeSurface::Create(JNINativeSurface* api) {
//	return new D3DNativeSurface
//}
