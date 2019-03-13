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
