/* ******************************************************************************
 * Copyright (c) 2019, 2020 BestSolution.at and others.
 * All rights reserved. This program and the accompanying materials 
 * are made available under the terms of the Eclipse Public License 2.0 
 * which is available at http://www.eclipse.org/legal/epl-2.0
 *
 * SPDX-License-Identifier: EPL-2.0
 * 
 * Contributors:
 *     Christoph Caks <ccaks@bestsolution.at> - initial API and implementation
 * ******************************************************************************/
#ifndef DRIFTGL_H_
#define DRIFTGL_H_

#include "Export.h"
#include "DriftGL_gen.h"

namespace driftgl {

	struct Context {
	};

	DRIFTGL_EXPORT bool Initialize();
	DRIFTGL_EXPORT bool Destroy();

	DRIFTGL_EXPORT Context* CreateContext(Context* sharedContext, int majorHint, int minorHint);
	DRIFTGL_EXPORT Context* CreateSharedCompatContext(Context* sharedContext);

	DRIFTGL_EXPORT Context* WrapContext(long long nativeContextHandle);

	DRIFTGL_EXPORT void DestroyContext(Context* context);
	DRIFTGL_EXPORT bool MakeContextCurrent(Context* context);
	DRIFTGL_EXPORT bool IsContextCurrent(Context* context);

	DRIFTGL_EXPORT void* GetNativeContextHandle(Context* context);

	DRIFTGL_EXPORT Context* GetCurrentContext();
}


#endif
