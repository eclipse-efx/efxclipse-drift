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
#ifndef DRIFTFX_SRC_INTERNALDRIFTFX_H_
#define DRIFTFX_SRC_INTERNALDRIFTFX_H_

#include <DriftFX/DriftFX.h>

#include "JNINativeSurface.h"

namespace driftfx {
namespace internal {


class InternalDriftFX : public DriftFX {

public:
	virtual DriftFXSurface* GetSurface(long surfaceId);
	virtual long CreateSurface(JNINativeSurface* api);

	static InternalDriftFX* instance;
protected:
	virtual ~InternalDriftFX();

};


}
}

#endif /* DRIFTFX_SRC_INTERNALDRIFTFX_H_ */
