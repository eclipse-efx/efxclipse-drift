package org.eclipse.fx.drift.internal.frontend;

import static org.eclipse.fx.drift.internal.GL.GL_RGBA;
import static org.eclipse.fx.drift.internal.GL.GL_RGBA8;
import static org.eclipse.fx.drift.internal.GL.GL_TEXTURE_2D;
import static org.eclipse.fx.drift.internal.GL.GL_UNPACK_ALIGNMENT;
import static org.eclipse.fx.drift.internal.GL.GL_UNPACK_ROW_LENGTH;
import static org.eclipse.fx.drift.internal.GL.GL_UNSIGNED_INT_8_8_8_8_REV;
import static org.eclipse.fx.drift.internal.GL.glBindTexture;
import static org.eclipse.fx.drift.internal.GL.glGetInteger;
import static org.eclipse.fx.drift.internal.GL.glIsTexture;
import static org.eclipse.fx.drift.internal.GL.glPixelStorei;
import static org.eclipse.fx.drift.internal.GL.glTexImage2D;

import org.eclipse.fx.drift.internal.common.MainMemoryImageData;
import org.eclipse.fx.drift.internal.prism.PrismES2;

public class ES2MainMemoryFxImage extends AMainMemoryFxImage {
	
	public ES2MainMemoryFxImage(MainMemoryImageData data) {
		super(data);
	}
	
	@Override
	protected void uploadTexture() {
		int targetTex = PrismES2.getTextureName(getTexture());
		System.out.println("*uploadTexture 0x" + Long.toHexString(data.memPointer) + " => " + targetTex);
		System.out.println(" with Unpack.alignment = " + glGetInteger(GL_UNPACK_ALIGNMENT));
		System.out.println(" with Unpack.rowLength = " + glGetInteger(GL_UNPACK_ROW_LENGTH));
		System.out.flush();
		synchronized (data) {
			uploadTexture(targetTex, data.size.x, data.size.y, data.memPointer, data.memSize);
		}
	}
	
	private void uploadTexture(int targetTex, int width, int height, long pPixels, int size) {
//		System.err.println("*uploadTexture(" + targetTex + ", " + width + ", " + height + ", " + Long.toHexString(pPixels) + ", " + size + ")");
		if (targetTex == 0) {
			System.err.println("  !  Invalid Texture ID");
		}
		System.out.println("isTexture(" + targetTex + "): " + glIsTexture(targetTex));
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
		glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
		glBindTexture(GL_TEXTURE_2D, targetTex);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, pPixels);
		glBindTexture(GL_TEXTURE_2D, 0);
//		glFlush();
//		glFinish();
	}
	
}
