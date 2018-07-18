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

#ifndef PRISM_ES2_GLX_GLXES2PRISMBRIDGE_H_
#define PRISM_ES2_GLX_GLXES2PRISMBRIDGE_H_


#include "../ES2PrismBridge.h"

namespace driftfx {
namespace internal {
namespace prism {
namespace es2 {
namespace glx {


class GLXES2PrismBridge : public ES2PrismBridge {

public:
	GLXES2PrismBridge(jlong pContext);
	virtual ~GLXES2PrismBridge();

	static void Initialize(jlong pContext);
};

}
}
}
}
}

#endif /* PRISM_ES2_GLX_GLXES2PRISMBRIDGE_H_ */
