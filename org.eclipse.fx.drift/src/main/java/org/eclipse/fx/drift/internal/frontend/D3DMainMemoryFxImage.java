package org.eclipse.fx.drift.internal.frontend;

import org.eclipse.fx.drift.internal.D3DBatch;

public class D3DMainMemoryFxImage extends AMainMemoryFxImage {

	@Override
	protected void uploadTexture() {
		D3DBatch.uploadTexture(getTexture(), data.memPointer, data.size.x, data.size.y, data.memSize);
	}

}
