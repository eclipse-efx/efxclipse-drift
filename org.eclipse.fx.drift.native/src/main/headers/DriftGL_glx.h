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
#ifdef DRIFTGL_GLX

#ifndef DRIFTGL_GLX_H_
#define DRIFTGL_GLX_H_

#include <X11/Xlib.h>
#include <GL/glx.h>

namespace driftgl {

	extern Display* display;

	typedef GLXContext (*glXCreateContextAttribsARBProc)(Display*, GLXFBConfig, GLXContext, Bool, const int*);
	typedef Bool (*glXMakeContextCurrentARBProc)(Display*, GLXDrawable, GLXDrawable, GLXContext);

	extern glXCreateContextAttribsARBProc glXCreateContextAttribsARB;
	extern glXMakeContextCurrentARBProc glXMakeContextCurrentARB;



}

#endif


#endif
