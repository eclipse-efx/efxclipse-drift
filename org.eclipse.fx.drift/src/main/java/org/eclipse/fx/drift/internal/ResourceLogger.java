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
package org.eclipse.fx.drift.internal;

public class ResourceLogger {
	private static final DriftLogger LOGGER = DriftFX.createLogger(ResourceLogger.class);
	
	
	public static void resourceAllocated(long id, String type, String nfo) {
		LOGGER.debug(() -> "RESOURCE: + " + type + "(0x"+ Long.toHexString(id) + ") " + nfo);
	}
	
	public static void resourceDisposed(long id) {
		LOGGER.debug(() -> "RESOURCE: - 0x" + Long.toHexString(id));
	}

	
}
