package org.eclipse.fx.drift.internal.frontend;

import org.eclipse.fx.drift.internal.D3DBatch;
import org.eclipse.fx.drift.internal.common.MainMemoryImageData;

public class D3DMainMemoryFxImage extends AMainMemoryFxImage {

	public D3DMainMemoryFxImage(MainMemoryImageData data) {
		super(data);
	}
	
	@Override
	protected void uploadTexture() {
		D3DBatch.uploadTexture(getTexture(), data.memPointer, data.size.x, data.size.y, data.memSize);
	}

}
