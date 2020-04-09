package org.eclipse.fx.drift.internal.transport.command;

import java.util.UUID;

import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.transport.Command;

public class ReleaseCommand implements Command {
	public static final String NAME = "Release";
	
	private UUID swapChain;
	private ImageData imageData;
	
	public ReleaseCommand(UUID swapChain, ImageData imageData) {
		this.swapChain = swapChain;
		this.imageData = imageData;
	}
	
	public UUID getSwapChainId() {
		return swapChain;
	}
	
	public ImageData getImageData() {
		return imageData;
	}
	
	public String getName() {
		return NAME;
	}
	
	@Override
	public String toString() {
		return NAME + " " + swapChain + " " + imageData;
	}
}
