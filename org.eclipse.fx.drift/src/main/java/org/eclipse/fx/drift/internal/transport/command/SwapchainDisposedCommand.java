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
package org.eclipse.fx.drift.internal.transport.command;

import java.util.UUID;

import org.eclipse.fx.drift.internal.transport.Command;

public class SwapchainDisposedCommand implements Command {
	public final static String NAME = "SwapchainDisposed";
	private UUID id;
	
	public SwapchainDisposedCommand(UUID id) {
		this.id = id;
	}
	
	public UUID getId() {
		return id;
	}
	
	@Override
	public String getName() {
		return NAME;
	}
	
	@Override
	public String toString() {
		return NAME + " " + id;
	}
}
