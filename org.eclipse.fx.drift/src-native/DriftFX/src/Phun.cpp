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


#include <gl/cgl/CGLGLContext.h>
#include <gl/InternalGLContext.h>

#include <iostream>
using namespace std;

using namespace driftfx::internal::gl;
using namespace driftfx::internal::gl::cgl;


int main() {

	cout << "Hello Context!" << endl;
	CGLGLContext* context = new CGLGLContext();


	context->SetCurrent();
	InternalGLContext::Initialize();

	cout << glGetString( GL_VERSION ) << endl;

	cout <<"glGetError: "<< (void*) glGetError << endl;
	GLenum x = glGetError();

	cout <<"glGenTextures: "<< (void*) glGenTextures << endl;

	GLuint texa = 0; glGenTextures(1, &texa);
	cout << "texa="<<texa<<endl;



	GLuint texc = 0; InternalGLContext::glGenTextures(1, &texc);
	cout << "texc="<<texc<<endl;


	GLenum err = InternalGLContext::glGetError();
	cout << "gl err = " << err << endl;


	GLuint tex = 0; InternalGLContext::glGenTextures(1, &tex);
	cout << " created tex " << tex << endl;

	err = InternalGLContext::glGetError();
		cout << "gl err = " << err << endl;
	InternalGLContext::glBindTexture(GL_TEXTURE_2D, tex);
	err = InternalGLContext::glGetError();
		cout << "gl err = " << err << endl;
	InternalGLContext::glBindTexture(GL_TEXTURE_2D, 0);
	err = InternalGLContext::glGetError();
		cout << "gl err = " << err << endl;
	InternalGLContext::glDeleteTextures(1, &tex);
	err = InternalGLContext::glGetError();
		cout << "gl err = " << err << endl;
	cout << " deleted tex again" << endl;;

	delete context;
	cout << "end." << endl;
	return 0;
}
