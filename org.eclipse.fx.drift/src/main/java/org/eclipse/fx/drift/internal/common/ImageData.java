package org.eclipse.fx.drift.internal.common;

import org.eclipse.fx.drift.internal.math.Vec2i;

public class ImageData {

	public static class ImageDataType {
		public final String id;
		public ImageDataType(String id) {
			this.id = id;
		}
	}
	
	public final int number;
	public final Vec2i size;
	public final ImageDataType type;
	
	public ImageData(int number, ImageDataType type, Vec2i size) {
		this.number = number;
		this.type = type;
		this.size = size;
	}
}
