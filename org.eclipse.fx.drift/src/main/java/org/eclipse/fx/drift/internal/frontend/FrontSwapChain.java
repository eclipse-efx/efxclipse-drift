package org.eclipse.fx.drift.internal.frontend;

import java.util.Optional;
import java.util.UUID;

import org.eclipse.fx.drift.TransferType;
import org.eclipse.fx.drift.Vec2i;
import org.eclipse.fx.drift.internal.common.ImageData;

import com.sun.prism.ResourceFactory;

@SuppressWarnings("restriction")
public interface FrontSwapChain {
	Optional<FxImage<?>> getNext();
	void release(FxImage<?> image);
	
	Vec2i getSize();
	TransferType getTransferType();
	
	void present(ImageData image);
	void allocate(ResourceFactory resourceFactory) throws Exception;
	void release();
	UUID getId();
	void scheduleDispose();
	boolean isDisposeScheduled();
}
