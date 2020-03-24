package org.eclipse.fx.drift.internal.frontend;

import java.util.List;
import java.util.function.Consumer;

import org.eclipse.fx.drift.internal.backend.BackSwapChain.PresentationMode;
import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.math.Vec2i;

public interface Frontend {

	Vec2i getSize();
	
	// transport api
	void createSwapchain(List<ImageData> images, PresentationMode presentationMode);
	void present(ImageData image);
	
	void setOnRelease(Consumer<ImageData> onRelease);
}
