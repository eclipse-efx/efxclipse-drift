package org.eclipse.fx.drift.internal.frontend;

import org.eclipse.fx.drift.internal.common.ImageData;

import com.sun.prism.ResourceFactory;
import com.sun.prism.Texture;

@SuppressWarnings("restriction")
public interface FxImage {
	
	ImageData getData();

	void allocate(ResourceFactory rf);
	void release();
	
	void update();

	Texture getTexture();
	
}
