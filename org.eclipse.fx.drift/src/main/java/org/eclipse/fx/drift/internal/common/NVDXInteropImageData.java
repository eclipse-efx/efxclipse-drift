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
import org.eclipse.fx.drift.internal.prism.Prism;

public class NVDXInteropImageData extends ImageData {

	public static final TransferType TYPE = new TransferType("NVDXInterop", Prism::isD3D);

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
