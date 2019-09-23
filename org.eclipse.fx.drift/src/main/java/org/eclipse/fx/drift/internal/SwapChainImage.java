package org.eclipse.fx.drift.internal;

import com.sun.prism.ResourceFactory;
import com.sun.prism.Texture;

public class SwapChainImage {

//	public final long surfaceId;
//	public final long frameId;
	
	public final long pSwapChainImage;
	private final long pShareData;
	
	public final int number;
	
	private Texture fxTexture;

	public SwapChainImage(long pSwapChainImage, long pShareData, int number) {
		this.pSwapChainImage = pSwapChainImage;
		this.pShareData = pShareData;
		
		this.number = number;
		
		System.out.println("java SwapChainImage pShareData = " + Long.toHexString(pShareData));
	}
	
	public void InitializeFX(ResourceFactory rf) {
		
	}
	
	private boolean isFXInitialized() {
		return fxTexture != null;
	}
	
	public int onTextureCreated(Texture fxTexture) {
		System.out.println("SwapChainImage#onTextureCreated " + Long.toHexString(pSwapChainImage) );
		return nOnTextureCreated(pShareData, fxTexture);
	}
	
	@Override
	public String toString() {
		return "SwapChainImage("+number+", "+Long.toHexString(pSwapChainImage)+")";
	}
	
	private static native int nOnTextureCreated(long pShareData, Texture fxTexture);
		

}
