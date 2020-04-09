package org.eclipse.fx.drift.internal.frontend;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.UUID;
import java.util.concurrent.atomic.AtomicReference;
import java.util.function.BiConsumer;
import java.util.function.Consumer;

import org.eclipse.fx.drift.PresentationMode;
import org.eclipse.fx.drift.TransferType;
import org.eclipse.fx.drift.Vec2i;
import org.eclipse.fx.drift.internal.FPSCounter2;
import org.eclipse.fx.drift.internal.common.ImageData;

import com.sun.prism.ResourceFactory;

@SuppressWarnings("restriction")
public class SimpleFrontSwapChain implements FrontSwapChain {

	private UUID id;
	private List<FxImage<?>> images = new ArrayList<>();
	private Map<ImageData, FxImage<?>> imageMap = new HashMap<>();
	
	private AtomicReference<ImageData> mailbox = new AtomicReference<>();
	
	private BiConsumer<UUID, ImageData> onRelease;
	private Vec2i size;
	private int imageCount;
	private PresentationMode presentationMode;
	
	public FPSCounter2 fpsCounter = new FPSCounter2(100);
	private boolean disposeScheduled;
	
	public SimpleFrontSwapChain(UUID id, List<ImageData> images, PresentationMode presentationMode, BiConsumer<UUID, ImageData> onRelease) {
		this.id = id;
		for (ImageData image : images) {
			FxImage<?> fxImage = FxImageFactory.createFxImage(image);
			this.images.add(fxImage);
			imageMap.put(image, fxImage);
		}
		
		this.presentationMode = presentationMode;
		this.onRelease = onRelease;
	}
	
	public Vec2i getSize() {
		return images.get(0).getData().size;
	}
	
	@Override
	public TransferType getTransferType() {
		return images.get(0).getData().type;
	}
	
	public void allocate(ResourceFactory rf) throws Exception {
		for (FxImage<?> fxImage : images) {
			fxImage.allocate(rf);
		}
	}
	
	// TODO who calls me?
	public void release() {
		for (FxImage<?> fxImage : images) {
			fxImage.release();
		}
	}
	
	@Override
	public void scheduleDispose() {
		disposeScheduled = true;
	}
	
	@Override
	public boolean isDisposeScheduled() {
		return disposeScheduled;
	}
	
	
	@Override
	public Optional<FxImage<?>> getNext() {
		return getNextData().map(imageMap::get);
	}
	
	public Optional<ImageData> getNextData() {
		return Optional.ofNullable(mailbox.getAndSet(null));
	}
	
	@Override
	public UUID getId() {
		return id;
	}
	
	// => called by backend
	public void present(ImageData image) {
//		System.err.println("DriftFX Frontend: Swapchain#present " + image.number);
		ImageData old = mailbox.getAndSet(image);
		if (old != null) {
			release(old);
		}
		fpsCounter.tick();
	}

	// => calls backend
	@Override
	public void release(FxImage<?> image) {
//		System.err.println("DriftFX Frontend: Swapchain#release " + image.getData().number);
		onRelease.accept(id, image.getData());
	}
	public void release(ImageData image) {
//		System.err.println("DriftFX Frontend: Swapchain#release " + image.number);
		onRelease.accept(id, image);
	}
}
