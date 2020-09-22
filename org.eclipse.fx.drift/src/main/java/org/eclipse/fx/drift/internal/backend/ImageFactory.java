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
package org.eclipse.fx.drift.internal.backend;

import org.eclipse.fx.drift.TransferType;
import org.eclipse.fx.drift.Vec2i;
import org.eclipse.fx.drift.internal.common.IOSurfaceImageData;
import org.eclipse.fx.drift.internal.common.MainMemoryImageData;
import org.eclipse.fx.drift.internal.common.NVDXInteropImageData;

public class ImageFactory {

	
	public static Image createImage(int number, Vec2i size, TransferType type) {
		if (type == MainMemoryImageData.TYPE) {
			return new MainMemoryImage(number, size);
		}
		if (type == NVDXInteropImageData.TYPE) {
			return new NVDXInteropImage(number, size);
		}
		if (type == IOSurfaceImageData.TYPE) {
			return new IOSurfaceImage(number, size);
		}
		
		throw new RuntimeException("ImageFactory#createImage: Unknown TransferType (" + type + ")");
	}
}
