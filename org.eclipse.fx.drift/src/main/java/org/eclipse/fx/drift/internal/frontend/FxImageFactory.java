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
package org.eclipse.fx.drift.internal.frontend;

import org.eclipse.fx.drift.internal.common.IOSurfaceImageData;
import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.common.MainMemoryImageData;
import org.eclipse.fx.drift.internal.common.NVDXInteropImageData;
import org.eclipse.fx.drift.internal.prism.Prism;

public class FxImageFactory {

	public static FxImage createFxImage(ImageData data) {
		if (data.type == MainMemoryImageData.TYPE) {
			// TODO switch between prism types
			if (Prism.isES2())
			return new ES2MainMemoryFxImage((MainMemoryImageData) data);
			if (Prism.isD3D())
			return new D3DMainMemoryFxImage((MainMemoryImageData) data);
		}
		if (data.type == NVDXInteropImageData.TYPE) {
			return new NVDXInteropFXImage((NVDXInteropImageData)data);
		}
		if (data.type == IOSurfaceImageData.TYPE) {
			return new IOSurfaceFxImage((IOSurfaceImageData) data);
		}
		
		throw new RuntimeException();
	}
}
