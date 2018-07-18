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
#ifndef DRIFTFX_DRIFTFX_H_
#define DRIFTFX_DRIFTFX_H_

#include <DriftFX/DriftFXSurface.h>

namespace driftfx {

class DriftFX {

public:
	static DriftFX* Get();
	virtual DriftFXSurface* GetSurface(long surfaceId) = 0;

protected:
	virtual ~DriftFX();
};

}

#endif /* DRIFTFX_DRIFTFX_H_ */
