package org.eclipse.fx.drift.internal.backend;

import java.util.function.Consumer;

import org.eclipse.fx.drift.internal.backend.BackSwapChain.PresentationMode;
import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.common.ImageData.ImageDataType;
import org.eclipse.fx.drift.internal.math.Vec2i;

public class BackendImpl implements Backend {

	private BackSwapChain swapChain;
	private OnCreateSwapchain onCreateSwapChain;
	private Consumer<ImageData> onPresent;
	
	@Override
	public BackSwapChain createSwapChain(Vec2i size, int imageCount, PresentationMode presentationMode, ImageDataType type) {
		// TODO release old swapChain
		
		swapChain = new SimpleSwapChain(size, imageCount, presentationMode, type, this::onPresent);
		swapChain.allocate();
		
		
		
		if (onCreateSwapChain != null) {
			onCreateSwapChain.onCreateSwapchain(swapChain.getImages(), presentationMode);
		}
		
		return swapChain;
	}

	@Override
	public void setOnCreateSwapchain(OnCreateSwapchain onCreateSwapChain) {
		this.onCreateSwapChain = onCreateSwapChain;
	}

	@Override
	public void release(ImageData image) {
		swapChain.release(image);
	}
	
	private void onPresent(Image image) {
		// TODO is this the right place to call before/after Render?
//		image.beforeRender();
		if (onPresent != null) {
			onPresent.accept(image.getData());
		}
//		image.afterRender();
	}

	@Override
	public void setOnPresent(Consumer<ImageData> onPresent) {
		this.onPresent = onPresent;
	}

}
