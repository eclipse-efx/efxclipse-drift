package org.eclipse.fx.drift.internal.frontend;

import com.sun.prism.PixelFormat;
import com.sun.prism.ResourceFactory;
import com.sun.prism.Texture;

import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.common.MainMemoryImageData;
import org.eclipse.fx.drift.internal.prism.Prism;

@SuppressWarnings("restriction")
public abstract class AMainMemoryFxImage extends AFxImage<MainMemoryImageData> {

	public AMainMemoryFxImage(MainMemoryImageData data) {
		super(data);
	}

	@Override
	public void update() {
		System.err.println("*update");
		uploadTexture();
	}

	protected abstract void uploadTexture();

}