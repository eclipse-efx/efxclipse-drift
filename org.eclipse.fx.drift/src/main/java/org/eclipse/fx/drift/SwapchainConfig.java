package org.eclipse.fx.drift;

public class SwapchainConfig {

	public final Vec2i size;
	public final int imageCount;
	public final PresentationMode presentationMode;
	public final TransferType transferType;
	
	
	public SwapchainConfig(Vec2i size, int imageCount, PresentationMode presentationMode, TransferType transferType) {
		this.size = size;
		this.imageCount = imageCount;
		this.presentationMode = presentationMode;
		this.transferType = transferType;
	}
	
}
