package org.eclipse.fx.drift.internal.backend;

import java.util.List;

import org.eclipse.fx.drift.SwapChain;
import org.eclipse.fx.drift.internal.common.ImageData;

public interface BackSwapChain extends SwapChain {

	void allocate();

	
	void release(ImageData image);

	
	List<ImageData> getImages();
	
}
