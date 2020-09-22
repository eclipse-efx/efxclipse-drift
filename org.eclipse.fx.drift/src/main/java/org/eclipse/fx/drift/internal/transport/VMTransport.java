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
package org.eclipse.fx.drift.internal.transport;

import org.eclipse.fx.drift.internal.backend.Backend;
import org.eclipse.fx.drift.internal.frontend.Frontend;

public class VMTransport {

	private Frontend frontend;
	private Backend backend;
	
	public VMTransport(Frontend frontend, Backend backend) {
		this.frontend = frontend;
		this.backend = backend;
	}
	
	public void start() {
//		frontend.setOnRelease(backend::release);
//		backend.setOnPresent(frontend::present);
//		backend.setOnCreateSwapchain(frontend::createSwapchain);
		
		
		frontend.setCommandChannel(backend::receiveCommand);
		backend.setCommandChannel(frontend::receiveCommand);
	}
}
