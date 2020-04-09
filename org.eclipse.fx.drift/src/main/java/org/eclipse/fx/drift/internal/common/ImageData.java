package org.eclipse.fx.drift.internal.common;

import org.eclipse.fx.drift.TransferType;
import org.eclipse.fx.drift.Vec2i;

public class ImageData {

	public final int number;
	public final Vec2i size;
	public final TransferType type;
	
	public ImageData(int number, TransferType type, Vec2i size) {
		this.number = number;
		this.type = type;
		this.size = size;
	}
}
