#include "ShareManager.h"
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

#include "ShareManager.h"

#include <utils/Logger.h>
#include <thread>
#include <mutex>
using namespace std;

using namespace driftfx;
using namespace internal;

ShareManager::~ShareManager()
{
}

void ShareManager::Present(RenderTarget* target) {
	presentQueueMutex.lock();
	presentQueue.push(target);
	presentQueueMutex.unlock();
}

void ShareManager::Start() {
	running = true;
	worker = new thread(&ShareManager::run, this);
}

void ShareManager::Stop() {
	running = false;
	worker->join();
}

void ShareManager::run()
{
	// setup context stuff
	prepare();

	while (running) {
		RenderTarget* target = nullptr;
		presentQueueMutex.lock();
		if (!presentQueue.empty()) {
			target = presentQueue.back();
			int count = 0;
			while (!presentQueue.empty()) {
				presentQueue.pop();
				count++;
			}
			LogDebug("dropped " << count << " frames");
		}
		presentQueueMutex.unlock();

		if (target != nullptr) {
			doPresent(target);
		}

		chrono::milliseconds pause(100);
		this_thread::sleep_for(pause);
	}

	cleanup();
}
