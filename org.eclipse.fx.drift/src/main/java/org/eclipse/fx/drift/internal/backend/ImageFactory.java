package org.eclipse.fx.drift.internal.backend;

import org.eclipse.fx.drift.internal.common.ImageData.ImageDataType;
import org.eclipse.fx.drift.internal.common.MainMemoryImageData;
import org.eclipse.fx.drift.internal.math.Vec2i;

public class ImageFactory {

	
	public static Image createImage(int number, Vec2i size, ImageDataType type) {
		if (type == MainMemoryImageData.TYPE) {
			return new MainMemoryImage(number, size);
		}
		
		throw new RuntimeException();
	}
}
