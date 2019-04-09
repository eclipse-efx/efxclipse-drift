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

#ifndef DRIFTFX_SHAREMANAGER_H_
#define DRIFTFX_SHAREMANAGER_H_

#include <DriftFX/RenderTarget.h>

#include <thread>
#include <mutex>
#include <queue>

namespace driftfx {
namespace internal {

class ShareManager {

public:

	virtual ~ShareManager();

	void Present(RenderTarget* target);

	void Start();
	void Stop();

protected:

	virtual void prepare() = 0;
	virtual void doPresent(RenderTarget* target) = 0;
	virtual void cleanup() = 0;
	

private:
	void run();

	bool running;
	std::thread* worker;

	std::queue<RenderTarget*> presentQueue;
	std::mutex presentQueueMutex;

};

}
}

#endif