package org.eclipse.fx.drift.internal.common;

import org.eclipse.fx.drift.TransferType;
import org.eclipse.fx.drift.Vec2i;
import org.eclipse.fx.drift.util.NativeUtil;

public class IOSurfaceImageData extends ImageData {
	
	public static final TransferType TYPE = new TransferType("IOSurface", () -> NativeUtil.isMacOs());

	public final long ioSurfaceID;
	
	public IOSurfaceImageData(int number, Vec2i size, long ioSurfaceID) {
		super(number, TYPE, size);
		this.ioSurfaceID = ioSurfaceID;
	}
	
	@Override
	public String toString() {
		return TYPE.id + "Data(" + ioSurfaceID + ")";
	}

}
