package org.eclipse.fx.drift.internal.frontend;

import java.util.List;
import java.util.function.Consumer;

import org.eclipse.fx.drift.DriftFXSurface2;
import org.eclipse.fx.drift.internal.backend.BackSwapChain.PresentationMode;
import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.math.Vec2i;

public class FrontendImpl implements Frontend {

	private DriftFXSurface2 surface;
	
	private FrontSwapChain swapChain;
	
	private Consumer<ImageData> onRelease;
	
	
	public FrontendImpl(DriftFXSurface2 surface) {
		this.surface = surface;
	}
	
	@Override
	public Vec2i getSize() {
		double w = surface.getWidth();
		double h = surface.getHeight();
		double userScale = surface.getUserScaleFactor();
		double screenScale = surface.getScreenScaleFactor();
		
		int x = (int) Math.ceil(w * userScale * screenScale);
		int y = (int) Math.ceil(h * userScale * screenScale);
		
		return new Vec2i(x, y);
	}

	@Override
	public void createSwapchain(List<ImageData> images, PresentationMode presentationMode) {
		swapChain = new SimpleFrontSwapChain(images, presentationMode, imageData -> this.onRelease.accept(imageData));
		
		surface.setSwapChain(swapChain);
	}

	@Override
	public void present(ImageData image) {
		swapChain.present(image);
		
		surface.dirty();
	}

	@Override
	public void setOnRelease(Consumer<ImageData> onRelease) {
		this.onRelease = onRelease;
	}

}
