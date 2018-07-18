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
#ifndef PRISM_ES2_ES2NATIVESURFACE_H_
#define PRISM_ES2_ES2NATIVESURFACE_H_

#include "../../NativeSurface.h"

namespace driftfx {
namespace internal {
namespace prism {
namespace es2 {


class ES2NativeSurface : public NativeSurface {

protected:
	gl::GLContext* sharedFXContext;

public:
	ES2NativeSurface(JNINativeSurface* api);
	virtual ~ES2NativeSurface();

	virtual Context* GetFxContext();

};


}
}
}
}

#endif /* PRISM_ES2_ES2NATIVESURFACE_H_ */
