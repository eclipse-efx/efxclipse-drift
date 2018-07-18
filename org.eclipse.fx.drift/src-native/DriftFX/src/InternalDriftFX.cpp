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

#include "NativeSurfaceRegistry.h"
#include "InternalDriftFX.h"

using namespace driftfx;
using namespace driftfx::internal;

InternalDriftFX* InternalDriftFX::instance = nullptr;

DriftFX::~DriftFX() {
}

InternalDriftFX::~InternalDriftFX() {
}

DriftFX* DriftFX::Get() {
	if (InternalDriftFX::instance == nullptr) {
		InternalDriftFX::instance = new InternalDriftFX();
	}
	return InternalDriftFX::instance;
}

DriftFXSurface* InternalDriftFX::GetSurface(long surfaceId) {
	return NativeSurfaceRegistry::Get()->Get(surfaceId);
}

long InternalDriftFX::CreateSurface(JNINativeSurface* api) {
	return NativeSurfaceRegistry::Get()->Create(api);
}
