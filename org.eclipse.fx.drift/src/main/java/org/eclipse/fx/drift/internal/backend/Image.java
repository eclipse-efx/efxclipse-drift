package org.eclipse.fx.drift.internal.backend;

import org.eclipse.fx.drift.internal.common.ImageData;

public interface Image {

	public static class ImageType {
		public final String id;
		public ImageType(String id) {
			this.id = id;
		}
	}
	
	ImageData getData();
	
	void allocate();
	void release();
	void beforeRender();
	void afterRender();
	
	
	
	int getGLTexture();
	
}

