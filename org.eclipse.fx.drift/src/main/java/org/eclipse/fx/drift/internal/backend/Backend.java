package org.eclipse.fx.drift.internal.backend;

import java.util.List;
import java.util.function.Consumer;

import org.eclipse.fx.drift.internal.backend.BackSwapChain.PresentationMode;
import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.common.ImageData.ImageDataType;
import org.eclipse.fx.drift.internal.math.Vec2i;

public interface Backend {

	BackSwapChain createSwapChain(Vec2i size, int imageCount, PresentationMode presentationMode, ImageDataType type);

	
	
	// transport api
	void release(ImageData image);
	
	void setOnPresent(Consumer<ImageData> onPresent);
	void setOnCreateSwapchain(OnCreateSwapchain onCreateSwapchain);
	
	@FunctionalInterface
	public static interface OnCreateSwapchain {
		void onCreateSwapchain(List<ImageData> images, PresentationMode presentationMode);
	}
}
