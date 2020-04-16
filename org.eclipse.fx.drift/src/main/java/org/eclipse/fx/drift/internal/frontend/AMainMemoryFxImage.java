package org.eclipse.fx.drift.internal.frontend;

import org.eclipse.fx.drift.internal.common.MainMemoryImageData;

public abstract class AMainMemoryFxImage extends AFxImage<MainMemoryImageData> {

	public AMainMemoryFxImage(MainMemoryImageData data) {
		super(data);
	}

	@Override
	public void update() {
		uploadTexture();
	}

	protected abstract void uploadTexture();

}