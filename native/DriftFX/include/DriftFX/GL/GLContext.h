/*
 * Copyright (c) 2019 BestSolution.at and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Christoph Caks <ccaks@bestsolution.at> - initial API and implementation
 */
#ifndef DRIFTFX_GL_GLCONTEXT_H_
#define DRIFTFX_GL_GLCONTEXT_H_

#include <DriftFX/Common.h>
#include <DriftFX/Context.h>

namespace driftfx {
namespace gl {

class DRIFT_API GLContext : public Context {

public:
	virtual void SetCurrent() = 0;
	virtual void UnsetCurrent() = 0;

	virtual bool IsCurrent() = 0;

	virtual GLContext* CreateSharedContext() = 0;

	virtual Texture* CreateTexture(int width, int height);


};

}
}

#endif /* DRIFTFX_GL_GLCONTEXT_H_ */
