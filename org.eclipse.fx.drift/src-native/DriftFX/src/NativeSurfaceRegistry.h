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
#ifndef DRIFTFX_INTERNAL_NATIVESURFACEREGISTRY_H_
#define DRIFTFX_INTERNAL_NATIVESURFACEREGISTRY_H_

#include <map>
#include <mutex>

#include <jni.h>

#include "NativeSurface.h"
#include "JNINativeSurface.h"

namespace driftfx {
namespace internal {


class NativeSurfaceRegistry {

public:
	long Create(JNINativeSurface *api);
	void Destroy(long surfaceid);
	NativeSurface* Get(long surfaceId);

	static NativeSurfaceRegistry* Get();

private:
	NativeSurfaceRegistry();
	virtual ~NativeSurfaceRegistry();

	static NativeSurfaceRegistry* instance;

	long nextSurfaceId;
	std::mutex mutex;
	std::map<long, NativeSurface*> registry;
};

}
}

#endif /* DRIFTFX_INTERNAL_NATIVESURFACEREGISTRY_H_ */
