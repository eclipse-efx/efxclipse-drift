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
#ifndef PRISM_D3D_D3DNATIVESURFACE_H_
#define PRISM_D3D_D3DNATIVESURFACE_H_

#include <DriftFX/Context.h>

#include "NativeSurface.h"
#include "win32/D3D9ExContext.h"

#include "D3DPrismBridge.h"

namespace driftfx {
namespace internal {
namespace prism {
namespace d3d {


class D3DNativeSurface : public NativeSurface {

	friend D3DPrismBridge; // for calling our protected constructor

public:
	virtual ~D3DNativeSurface();

	virtual void Initialize();
	virtual void Cleanup();

protected:
	virtual Context* GetFxContext();
	D3DNativeSurface(JNINativeSurface* api);

private:
	D3D9ExContext* fxContext;
};


}
}
}
}

#endif /* PRISM_D3D_D3DNATIVESURFACE_H_ */
