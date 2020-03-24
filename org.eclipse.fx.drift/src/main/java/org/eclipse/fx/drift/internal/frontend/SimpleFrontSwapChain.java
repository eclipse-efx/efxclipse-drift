package org.eclipse.fx.drift.internal.frontend;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.concurrent.atomic.AtomicReference;
import java.util.function.Consumer;

import org.eclipse.fx.drift.internal.backend.BackSwapChain.PresentationMode;
import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.math.Vec2i;

import com.sun.prism.ResourceFactory;

public class SimpleFrontSwapChain implements FrontSwapChain {

	private List<FxImage> images = new ArrayList<>();
	private Map<ImageData, FxImage> imageMap = new HashMap<>();
	
	private AtomicReference<ImageData> mailbox = new AtomicReference<>();
	
	private Consumer<ImageData> onRelease;
	private Vec2i size;
	private int imageCount;
	private PresentationMode presentationMode;
	
	
	public SimpleFrontSwapChain(List<ImageData> images, PresentationMode presentationMode, Consumer<ImageData> onRelease) {
		for (ImageData image : images) {
			FxImage fxImage = FxImageFactory.createFxImage(image);
			this.images.add(fxImage);
			imageMap.put(image, fxImage);
		}
		
		this.presentationMode = presentationMode;
		this.onRelease = onRelease;
	}
	
	public void allocate(ResourceFactory rf) {
		for (FxImage fxImage : images) {
			fxImage.allocate(rf);
		}
	}
	
	public void release() {
		
	}
	
	
	
	@Override
	public Optional<FxImage> getNext() {
		return getNextData().map(imageMap::get);
	}
	
	public Optional<ImageData> getNextData() {
		return Optional.ofNullable(mailbox.getAndSet(null));
	}
	
	// => called by backend
	public void present(ImageData image) {
//		System.err.println("DriftFX Frontend: Swapchain#present " + image.number);
		ImageData old = mailbox.getAndSet(image);
		if (old != null) {
			release(old);
		}
	}

	// => calls backend
	@Override
	public void release(FxImage image) {
//		System.err.println("DriftFX Frontend: Swapchain#release " + image.getData().number);
		onRelease.accept(image.getData());
	}
	public void release(ImageData image) {
		System.err.println("DriftFX Frontend: Swapchain#release " + image.number);
		onRelease.accept(image);
	}
}
