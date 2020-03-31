package org.eclipse.fx.drift.internal.frontend;

import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.common.MainMemoryImageData;
import org.eclipse.fx.drift.internal.common.NVDXInteropImageData;

public class FxImageFactory {

	public static FxImage createFxImage(ImageData data) {
		if (data.type == MainMemoryImageData.TYPE) {
			// TODO switch between prism types
//			return new ES2MainMemoryFxImage((MainMemoryImageData) data);
			return new D3DMainMemoryFxImage((MainMemoryImageData) data);
		}
		if (data.type == NVDXInteropImageData.TYPE) {
			return new NVDXInteropFXImage((NVDXInteropImageData)data);
		}
		
		throw new RuntimeException();
	}
}
