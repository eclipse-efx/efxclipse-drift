package org.eclipse.fx.drift.internal.frontend;

import org.eclipse.fx.drift.internal.GraphicsPipelineUtil;
import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.common.MainMemoryImageData;
import org.eclipse.fx.drift.internal.prism.Prism;

import com.sun.prism.PixelFormat;
import com.sun.prism.ResourceFactory;
import com.sun.prism.Texture;

public abstract class AMainMemoryFxImage implements FxImage {

	private Texture texture;


	
	
	protected MainMemoryImageData data;

	public AMainMemoryFxImage() {
		super();
	}

	@Override
	public void update() {
			System.err.println("*update");
			uploadTexture();
		}

	@Override
	public ImageData getData() {
		return data;
	}

	@Override
	public void allocate(ResourceFactory rf) {
		texture = rf.createTexture(PixelFormat.BYTE_BGRA_PRE, Texture.Usage.DYNAMIC, Texture.WrapMode.CLAMP_NOT_NEEDED, data.size.x, data.size.y);
		texture.makePermanent();
		System.err.println("Texture Created! " + this + " / " + texture + " / " + Prism.getTextureHandle(texture));
	}
	
	protected abstract void uploadTexture();

	@Override
	public void release() {
		texture.dispose();
	}

	@Override
	public Texture getTexture() {
		return texture;
	}

}