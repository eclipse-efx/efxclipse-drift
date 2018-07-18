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

#ifndef DRIFTFX_TEXTURE_H_
#define DRIFTFX_TEXTURE_H_

namespace driftfx {

class Texture {

public:
	virtual ~Texture();


	virtual unsigned int GetWidth();
	virtual unsigned int GetHeight();

protected:
	Texture(unsigned int width, unsigned int height);

private:
	unsigned int width;
	unsigned int height;
};

}

#endif /* DRIFTFX_TEXTURE_H_ */
