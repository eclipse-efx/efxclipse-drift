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

#include "prism/PrismBridge.h"
#include "NativeSurfaceRegistry.h"

using namespace std;

using namespace driftfx::internal;
using namespace driftfx::internal::prism;

NativeSurfaceRegistry* NativeSurfaceRegistry::instance = nullptr;

NativeSurfaceRegistry::NativeSurfaceRegistry() :
		mutex(),
		registry(),
		nextSurfaceId(1) {

}

NativeSurfaceRegistry::~NativeSurfaceRegistry() {

}

NativeSurfaceRegistry* NativeSurfaceRegistry::Get() {
	if (instance == nullptr) {
		instance = new NativeSurfaceRegistry();
	}
	return instance;
}

long NativeSurfaceRegistry::Create(JNINativeSurface* api) {
	mutex.lock();
	long surfaceId = nextSurfaceId++;
	NativeSurface* surface = PrismBridge::Get()->CreateNativeSurface(api);
	registry[surfaceId] = surface;
	mutex.unlock();
	return surfaceId;
}

void NativeSurfaceRegistry::Destroy(long surfaceId) {
	mutex.lock();
	NativeSurface* surface = registry[surfaceId];
	delete surface;
	registry.erase(surfaceId);
	mutex.unlock();
}

NativeSurface* NativeSurfaceRegistry::Get(long surfaceId) {
	mutex.lock();
	NativeSurface* surface = registry[surfaceId];
	mutex.unlock();
	return surface;
}

