package org.eclipse.fx.drift.internal.common;

import org.eclipse.fx.drift.TransferType;
import org.eclipse.fx.drift.Vec2i;

public class NVDXInteropImageData extends ImageData {

	public static final TransferType TYPE = new TransferType("NVDXInterop");

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
