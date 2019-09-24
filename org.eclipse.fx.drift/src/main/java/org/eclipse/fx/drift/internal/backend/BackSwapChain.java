package org.eclipse.fx.drift.internal.backend;

import java.util.List;
import java.util.Optional;

import org.eclipse.fx.drift.internal.common.ImageData;

public interface BackSwapChain {

	public static enum PresentationMode {
		MAILBOX,
		QUEUE
	}
	
	Image acquire() throws InterruptedException;
	Optional<Image> tryAcquire();
	
	
	void allocate();
	void release();
	
	void release(ImageData image);
	void present(Image image);
	
	List<ImageData> getImages();
	
}
