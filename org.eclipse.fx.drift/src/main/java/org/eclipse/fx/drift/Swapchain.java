package org.eclipse.fx.drift;

import java.util.Optional;

public interface Swapchain {
	
	SwapchainConfig getConfig();
	
	RenderTarget acquire() throws InterruptedException;
	Optional<RenderTarget> tryAcquire();
	
	void present(RenderTarget image);
	
	void dispose();
}
