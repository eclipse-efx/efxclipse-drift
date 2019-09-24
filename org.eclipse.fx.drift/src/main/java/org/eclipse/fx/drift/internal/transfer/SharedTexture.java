package org.eclipse.fx.drift.internal.transfer;

import com.sun.prism.Texture;

public abstract class SharedTexture {

	protected int width;
	protected int height;
	
	protected abstract void allocate();
	protected abstract void release();
	protected abstract void onAcquire();
	protected abstract void onPresent();
	
	
	protected abstract void OnTextureCreated(Texture texture);
}
