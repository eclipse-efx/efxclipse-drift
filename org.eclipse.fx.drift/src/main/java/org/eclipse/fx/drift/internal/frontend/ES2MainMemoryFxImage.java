package org.eclipse.fx.drift.internal.frontend;

import static org.eclipse.fx.drift.internal.GL.*;
import static org.eclipse.fx.drift.internal.SYS.*;

import java.lang.reflect.InvocationTargetException;

import org.eclipse.fx.drift.internal.GraphicsPipelineUtil;
import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.common.MainMemoryImageData;
import org.eclipse.fx.drift.internal.math.Vec2i;

import com.sun.prism.PixelFormat;
import com.sun.prism.ResourceFactory;
import com.sun.prism.Texture;

public class ES2MainMemoryFxImage implements FxImage {

	
	private Texture texture;
	
	MainMemoryImageData data;
	
	public ES2MainMemoryFxImage(MainMemoryImageData data) {
		this.data = data;
	}
	
	
	@Override
	public void update() {
		System.err.println("*update");
		int targetTex = GraphicsPipelineUtil.ES2.getTextureName(texture);
//		uploadTexture(targetTex, data.size.x, data.size.y, data.memPointer, data.memSize);
	}
	
	
	private void uploadTexture(int targetTex, int width, int height, long pPixels, int size) {
		System.err.println("*uploadTexture(" + targetTex + ", " + width + ", " + height + ", " + pPixels + ", " + size + ")");
		glBindTexture(GL_TEXTURE_2D, targetTex);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, pPixels);
		glBindTexture(GL_TEXTURE_2D, 0);
	}


	@Override
	public ImageData getData() {
		return data;
	}



	@Override
	public void allocate(ResourceFactory rf) {
		texture = rf.createTexture(PixelFormat.BYTE_BGRA_PRE, Texture.Usage.DYNAMIC, Texture.WrapMode.CLAMP_NOT_NEEDED, data.size.x, data.size.y);
		texture.makePermanent();

	}



	@Override
	public void release() {
		texture.dispose();
	}


	@Override
	public Texture getTexture() {
		return texture;
	}

	
	
}
