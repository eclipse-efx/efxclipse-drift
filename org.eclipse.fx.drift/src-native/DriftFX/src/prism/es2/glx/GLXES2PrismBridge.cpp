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

#include "../ES2PrismBridge.h"
#include "GLXES2PrismBridge.h"

#include "gl/glx/GLXGLContext.h"

using namespace driftfx::internal::gl::glx;
using namespace driftfx::internal::prism::es2;
using namespace driftfx::internal::prism::es2::glx;

GLXES2PrismBridge::GLXES2PrismBridge(jlong pContext) :
	ES2PrismBridge(new GLXGLContext((GLXContext) pContext))
{
	defaultContext = fxGLContext->CreateSharedContext();
	defaultContext->SetCurrent();
	glewInit();
	defaultContext->UnsetCurrent();
}

GLXES2PrismBridge::~GLXES2PrismBridge() {

}

void GLXES2PrismBridge::Initialize(jlong pContext) {
	PrismBridge::bridge = new GLXES2PrismBridge(pContext);
}
