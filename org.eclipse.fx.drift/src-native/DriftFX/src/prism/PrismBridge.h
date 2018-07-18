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

#ifndef PRISM_PRISMBRIDGE_H_
#define PRISM_PRISMBRIDGE_H_

#include <set>

#include <DriftFX/Context.h>
#include <DriftFX/GL/GLContext.h>
#include <DriftFX/DriftFXSurface.h>

#include "../JNINativeSurface.h"

#include "../NativeSurface.h"

namespace driftfx {
using namespace driftfx::gl;
namespace internal {
namespace prism {

class PrismBridge {

public:
	static PrismBridge* Get();

	virtual GLContext* GetDefaultContext();

	virtual Context* GetFxContext();

	virtual NativeSurface* CreateNativeSurface(JNINativeSurface* api) = 0;

	static void Destroy();

protected:
	PrismBridge(Context* fxContext);
	virtual ~PrismBridge();

	static PrismBridge* bridge;

	GLContext* defaultContext;

	Context* fxContext;

};

}
}
}

#endif /* PRISM_PRISMBRIDGE_H_ */
