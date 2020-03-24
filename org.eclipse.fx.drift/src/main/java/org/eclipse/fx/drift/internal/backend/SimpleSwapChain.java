package org.eclipse.fx.drift.internal.backend;

import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.Set;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.function.Consumer;
import java.util.stream.Collectors;

import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.common.ImageData.ImageDataType;
import org.eclipse.fx.drift.internal.math.Vec2i;

public class SimpleSwapChain implements BackSwapChain {

	private Vec2i size;
	private int imageCount;
	private PresentationMode presentationMode;
	private ImageDataType type;
	
	private Set<Image> images;
	private Map<ImageData, Image> imageMap;
	private BlockingQueue<Image> freeImages = new LinkedBlockingQueue<>();
	private Consumer<Image> onPresent;
	
	
	public SimpleSwapChain(Vec2i size, int imageCount, PresentationMode presentationMode, ImageDataType type, Consumer<Image> onPresent) {
		this.size = size;
		this.imageCount = imageCount;
		this.presentationMode = presentationMode;
		this.type = type;
		this.onPresent = onPresent;
	}
	
	public void allocate() {
		synchronized (freeImages) {
			images = new HashSet<>();
			imageMap = new HashMap<>();
			for (int number = 0; number < imageCount; number++) {
				Image image = ImageFactory.createImage(number, size, type);
				image.allocate();
				images.add(image);
				freeImages.add(image);
				imageMap.put(image.getData(), image);
			}
		}
	}
	
	public void release() {
		synchronized (freeImages) {
			for (Image image : freeImages) {
				image.release();
			}
			// TODO release ohter images
		}
	}

	@Override
	public Image acquire() throws InterruptedException {
		synchronized (freeImages) {
			return freeImages.take();
		}
	}
	
	// => called by frontend
	@Override
	public void release(ImageData imageData) {
//		System.err.println("DriftFX Backend: Swapchain#release " + imageData.number);
		synchronized (freeImages) {
			Image image = imageMap.get(imageData);
			if (image == null) {
				// panic
				System.err.println("Wrong image released !!!!!");
			}
			else {
				freeImages.add(image);
			}
		}
	}

	@Override
	public Optional<Image> tryAcquire() {
		synchronized (freeImages) {
			if (freeImages.isEmpty()) {
				return Optional.empty();
			}
			else {
				return Optional.of(freeImages.poll());
			}
		}
	}
	
	
	// => calls fontend present
	@Override
	public void present(Image image) {
//		System.err.println("DriftFX Backend: Swapchain#present " + image.getData().number);
		onPresent.accept(image);
	}
	
	@Override
	public List<ImageData> getImages() {
		return images.stream().map(Image::getData).collect(Collectors.toList());
	}
}
