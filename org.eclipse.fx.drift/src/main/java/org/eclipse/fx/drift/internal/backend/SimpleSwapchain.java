package org.eclipse.fx.drift.internal.backend;

import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.Set;
import java.util.UUID;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.stream.Collectors;

import org.eclipse.fx.drift.RenderTarget;
import org.eclipse.fx.drift.SwapchainConfig;
import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.transport.command.DisposeSwapchainCommand;
import org.eclipse.fx.drift.internal.transport.command.PresentCommand;

public class SimpleSwapchain implements BackendSwapchain {

	private final UUID id;
	private final Backend backend;
	private final SwapchainConfig config;
	
	private Set<Image> images;
	private Map<ImageData, Image> imageMap;
	private BlockingQueue<Image> freeImages = new LinkedBlockingQueue<>();
	
	private boolean disposed = false;
	
	public SimpleSwapchain(Backend backend, UUID id, SwapchainConfig config) {
		this.backend = backend;
		this.id = id;
		this.config = config;
	}
	
	@Override
	public SwapchainConfig getConfig() {
		return config;
	}
	
	public void allocate() {
		synchronized (freeImages) {
			images = new HashSet<>();
			imageMap = new HashMap<>();
			for (int number = 0; number < config.imageCount; number++) {
				Image image = ImageFactory.createImage(number, config.size, config.transferType);
				image.allocate();
				images.add(image);
				freeImages.add(image);
				imageMap.put(image.getData(), image);
			}
		}
	}
	
	public void dispose() {
		long disposeTime = -System.nanoTime();
		backend.sendCommand(new DisposeSwapchainCommand(id));
		while (freeImages.size() != images.size()) {
			try {
				Thread.sleep(1);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		disposeTime += System.nanoTime();
		System.err.println("Dispose waiting time was " + disposeTime + "ns");
		synchronized (freeImages) {
			for (Image image : freeImages) {
				image.release();
			}
			// TODO release ohter images
			images.removeAll(freeImages);
			if (!images.isEmpty()) {
				System.err.println("Unreleased Swapchain images remaining: " + images);
			}
			disposed = true;
		}
		
	}

	@Override
	public RenderTarget acquire() throws InterruptedException {
		synchronized (freeImages) {
			Image image = freeImages.take();
			image.onAcquire();
			return image;
		}
	}
	
	// => called by frontend
	@Override
	public void release(ImageData imageData) {
//		System.err.println("DriftFX Backend: Swapchain#release " + imageData.number);
//		synchronized (freeImages) {
			Image image = imageMap.get(imageData);
			if (image == null) {
				// panic
				System.err.println("Wrong image released !!!!!");
			}
			else {
				freeImages.add(image);
			}
//		}
	}

	@Override
	public Optional<RenderTarget> tryAcquire() {
		synchronized (freeImages) {
			if (freeImages.isEmpty()) {
				return Optional.empty();
			}
			else {
				Image image = freeImages.poll();
				if (image != null) image.onAcquire();
				return Optional.of(image);
			}
		}
	}
	
	
	// => calls fontend present
	@Override
	public void present(RenderTarget renderTarget) {
		Image image = (Image) renderTarget;
//		System.err.println("DriftFX Backend: Swapchain#present " + image.getData().number);
		image.onPresent();
		backend.sendCommand(new PresentCommand(id, image.getData()));
	}
	
	@Override
	public List<ImageData> getImages() {
		return images.stream().map(Image::getData).collect(Collectors.toList());
	}
}
