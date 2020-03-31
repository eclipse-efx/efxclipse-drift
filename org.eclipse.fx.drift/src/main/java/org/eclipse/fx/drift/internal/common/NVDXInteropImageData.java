package org.eclipse.fx.drift.internal.common;

import org.eclipse.fx.drift.internal.math.Vec2i;

public class NVDXInteropImageData extends ImageData {

	public static final ImageDataType TYPE = new ImageDataType("NVDXInterop");

	public final long dxShareHandle;
	
	public NVDXInteropImageData(int number, Vec2i size, long dxShareHandle) {
		super(number, TYPE, size);
		this.dxShareHandle = dxShareHandle;
	}

}
