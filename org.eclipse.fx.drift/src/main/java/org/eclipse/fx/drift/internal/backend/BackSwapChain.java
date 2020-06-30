package org.eclipse.fx.drift.internal.backend;

import java.util.List;

import org.eclipse.fx.drift.Swapchain;
import org.eclipse.fx.drift.internal.common.ImageData;

public interface BackSwapChain extends Swapchain {

	void allocate();

	
	void release(ImageData image);

	
	List<ImageData> getImages();
	
}
