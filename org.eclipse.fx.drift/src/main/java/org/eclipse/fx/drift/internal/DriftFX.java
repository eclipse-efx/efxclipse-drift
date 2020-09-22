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

import org.eclipse.fx.drift.util.NativeUtil;

public final class DriftFX {
	private static final DriftLogger LOGGER = DriftFX.createLogger(DriftFX.class);
	
	
	private static boolean once = false;
	
	private DriftFX() {
	}
	
	public static DriftLogger createLogger(Class<?> context) {
		return new DefaultLogger(context);
	}
	
	public static void require() {
		if (!once) {
			LOGGER.debug(() -> "Initialize DriftFX");
			initOnce();
			once = true;
		}
	}
	
	public static void initOnce() {
		NativeUtil.loadLibrary(DriftFX.class, "driftfx", System::loadLibrary, System::load);
	}
	
	
}
