package org.eclipse.fx.drift.internal;

import org.eclipse.fx.drift.internal.jni.win32.Win32;

public class DX9 {

	public static class DXTexture {
		public final Win32.IDirect3DTexture9 texture;
		public final Win32.HANDLE shareHandle;
		public DXTexture(long texture, long shareHandle) {
			this.texture = new Win32.IDirect3DTexture9(texture);
			this.shareHandle = new Win32.HANDLE(shareHandle);
		}
	}
	
	public static native DXTexture createTexture(long device, int width, int height);
}
