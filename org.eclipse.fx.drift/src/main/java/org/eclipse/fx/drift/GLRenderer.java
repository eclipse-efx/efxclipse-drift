package org.eclipse.fx.drift;

import org.eclipse.fx.drift.internal.RendererImpl;
import org.eclipse.fx.drift.internal.backend.GLRenderTarget;

public final class GLRenderer {

	private GLRenderer() {}
	
	
	public static Renderer getRenderer(DriftFXSurface surface) {
		return RendererImpl.getRenderer(surface);
	}
	
	public static int getGLTextureId(RenderTarget renderTarget) {
		return ((GLRenderTarget) renderTarget).getGLTexture();
	}
	
}
