package org.eclipse.fx.drift;

import org.eclipse.fx.drift.internal.RendererImpl;

public interface Renderer {
	/**
	 * creates a new Swapchain
	 * <p>must be called from the rendering thread with a current OpenGL context</p>
	 * @return
	 */
	SwapChain createSwapChain(Vec2i size, int imageCount, PresentationMode presentationMode, TransferType type);
	
	Vec2i getSize();
	
	static Renderer getRenderer(DriftFXSurface surface) {
		return RendererImpl.getRenderer(surface);
	}
}
