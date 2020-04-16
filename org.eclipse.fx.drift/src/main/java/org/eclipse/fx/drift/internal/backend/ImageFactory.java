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
		
		throw new RuntimeException();
	}
}
