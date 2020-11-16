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
package org.eclipse.fx.drift.internal.common;

import org.eclipse.fx.drift.TransferType;
import org.eclipse.fx.drift.Vec2i;
import org.eclipse.fx.drift.internal.DriftFX;
import org.eclipse.fx.drift.internal.DriftLogger;
import org.eclipse.fx.drift.internal.jni.win32.NVDXInterop;
import org.eclipse.fx.drift.internal.prism.Prism;

public class NVDXInteropImageData extends ImageData {
	
	private static final DriftLogger LOGGER = DriftFX.createLogger(NVDXInteropImageData.class);
	
	private static Boolean dxInteropAvailable = null;
	private static boolean isDXInteropAvailable() {
		if (dxInteropAvailable == null) {
			dxInteropAvailable = NVDXInterop.isAvailable();
			LOGGER.info(() -> "NVDXInterop available: " + dxInteropAvailable);
		}
		return dxInteropAvailable != null && dxInteropAvailable;
	}
	
	public static final TransferType TYPE = new TransferType("NVDXInterop", () -> Prism.isD3D() && isDXInteropAvailable());

	public final long dxShareHandle;
	
	public NVDXInteropImageData(int number, Vec2i size, long dxShareHandle) {
		super(number, TYPE, size);
		this.dxShareHandle = dxShareHandle;
	}
	
	@Override
	public String toString() {
		return TYPE.id + "Data(" + dxShareHandle + ")";
	}

}
