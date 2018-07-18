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


#include <jni.h>

#include "ES2PrismBridge.h"
#include "ES2NativeSurface.h"

#include <DriftFX/GL/GLContext.h>
#include <DriftFX/GL/GLDebug.h>
#include <utils/Logger.h>

using namespace driftfx::gl;

using namespace driftfx::internal;
using namespace driftfx::internal::prism;
using namespace driftfx::internal::prism::es2;

ES2PrismBridge::ES2PrismBridge(GLContext* fxContext) :
	PrismBridge(fxContext),
	fxGLContext(fxContext) {

	LogDebug("Constructed PrismBridge with fxContext = " << fxContext);

	defaultContext = fxContext->CreateSharedContext();


}

ES2PrismBridge::~ES2PrismBridge() {

}

#include <iomanip>

int ES2PrismBridge::CopyTexture(int sourceTex, int targetTex, int width, int height) {
	// COPY OVER
	GLuint fbos[2];

	GLERR( glGenFramebuffers(2, &fbos[0]); );

	GLERR( glBindFramebuffer(GL_READ_FRAMEBUFFER, fbos[0]); );
	GLERR( glFramebufferTexture(GL_READ_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, sourceTex, 0); );

	GLERR( glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fbos[1]); );
	GLERR( glFramebufferTexture(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, targetTex, 0); );

	GLERR( glClearColor(0, 0, 0, 0); );
	GLERR( glClear(GL_COLOR_BUFFER_BIT); );

	GLERR( glBlitFramebuffer(0, 0, width, height, 0, 0, width, height, GL_COLOR_BUFFER_BIT, GL_LINEAR); );

	// We need to wait here for the blit operation to finish to prevent copying an empty texture in FX context
	glFinish();

	GLERR( glDeleteFramebuffers(2, &fbos[0]); );

	return 0;
}

NativeSurface* ES2PrismBridge::CreateNativeSurface(JNINativeSurface* api) {
	return new ES2NativeSurface(api);
}


