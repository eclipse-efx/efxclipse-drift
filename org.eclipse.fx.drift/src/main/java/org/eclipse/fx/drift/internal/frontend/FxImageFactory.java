package org.eclipse.fx.drift.internal.frontend;

import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.common.MainMemoryImageData;

public class FxImageFactory {

	public static FxImage createFxImage(ImageData data) {
		if (data.type == MainMemoryImageData.TYPE) {
			return new ES2MainMemoryFxImage((MainMemoryImageData) data);
		}
		
		throw new RuntimeException();
	}
}
