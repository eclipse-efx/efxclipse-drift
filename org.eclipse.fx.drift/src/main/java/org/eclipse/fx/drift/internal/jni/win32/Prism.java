package org.eclipse.fx.drift.internal.jni.win32;

public class Prism {

	public static Win32.IDirect3DDevice9Ex getPrismIDirect3DDevice9Ex(long prismD3DContext) {
		long address = nGetPrismIDirect3DDevice9Ex(prismD3DContext);
		return new Win32.IDirect3DDevice9Ex(address);
	}
	
	public native static long nGetPrismIDirect3DDevice9Ex(long prismD3DContext);
	
	
	public static void replacePrismD3DTexture(long prismTexture, Win32.IDirect3DTexture9 texture) {
		nReplacePrismD3DTexture(prismTexture, texture.address);
	}
	
	public native static void nReplacePrismD3DTexture(long prismTexture, long texture);
}
