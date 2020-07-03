package org.eclipse.fx.drift;

/**
 * The API for rendering to a driftfx surface.
 * <p>To acquire an instance use the rendering api dependent factory. For OpenGL use {@link GLRenderer#getRenderer(DriftFXSurface)}.</p>
 *
 */
public interface Renderer {
	
	/**
	 * creates a new Swapchain.
	 * <p>must be called from the rendering thread with a current OpenGL context</p>
	 * @return a new swapchain
	 */
	Swapchain createSwapchain(SwapchainConfig config);
	
	/**
	 * returns the current size of the associated driftfx surface.
	 * @return the size
	 */
	Vec2i getSize();
	
}
