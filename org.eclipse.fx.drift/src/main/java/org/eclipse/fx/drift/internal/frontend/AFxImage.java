package org.eclipse.fx.drift.internal.frontend;

import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.prism.Prism;

import com.sun.prism.PixelFormat;
import com.sun.prism.ResourceFactory;
import com.sun.prism.Texture;

public abstract class AFxImage<D extends ImageData> implements FxImage<D> {

	private Texture texture;
	
	protected final D data;
	
	public AFxImage(D data) {
		this.data = data;
	}
	
	@Override
	public D getData() {
		return data;
	}

	@Override
	public void allocate(ResourceFactory rf) {
		texture = rf.createTexture(PixelFormat.BYTE_BGRA_PRE, Texture.Usage.DYNAMIC, Texture.WrapMode.CLAMP_NOT_NEEDED, data.size.x, data.size.y);
		texture.makePermanent();
		System.err.println("Texture Created! " + this + " / " + texture + " / " + Prism.getTextureHandle(texture));
	}

	@Override
	public void release() {
		texture.dispose();
	}

	@Override
	public void update() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public Texture getTexture() {
		return texture;
	}

}
