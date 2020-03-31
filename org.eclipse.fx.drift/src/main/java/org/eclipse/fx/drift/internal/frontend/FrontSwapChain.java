package org.eclipse.fx.drift.internal.frontend;

import java.util.Optional;

import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.math.Vec2i;

import com.sun.prism.ResourceFactory;

@SuppressWarnings("restriction")
public interface FrontSwapChain {
	Optional<FxImage> getNext();
	void release(FxImage image);
	
	Vec2i getSize();
	
	void present(ImageData image);
	void allocate(ResourceFactory resourceFactory);
	void release();
}
