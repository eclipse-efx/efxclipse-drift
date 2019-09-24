package org.eclipse.fx.drift.internal.common;

public class ImageData {

	
	public static class ImageDataType {
		public final String id;
		public ImageDataType(String id) {
			this.id = id;
		}
	}
	
	public final int number;
	public final ImageDataType type;
	
	public ImageData(int number, ImageDataType type) {
		this.number = number;
		this.type = type;
	}
}
