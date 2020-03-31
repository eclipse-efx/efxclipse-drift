package org.eclipse.fx.drift.internal.jni.win32;

import org.eclipse.fx.drift.internal.jni.win32.Win32.IDirect3DDevice9Ex;
import org.eclipse.fx.drift.internal.jni.win32.Win32.IDirect3DTexture9;

import static org.eclipse.fx.drift.internal.jni.win32.Win32.*;
public class Win32Tests {

	public static void main(String[] args) {
		System.loadLibrary("DriftGL");
		System.loadLibrary("driftfx");
		
		IDirect3DDevice9Ex device = D3D9.CreateOffscreenDevice();
		System.err.println("device: " + device.address);
		
		//while (true) {
		IDirect3DTexture9 tex = device.CreateTexture(1000, 1000, 1, D3DUSAGE_DYNAMIC, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT);
		System.err.println("tex: " + Long.toHexString(tex.address));
		System.err.println("tex.shareHandle "+Long.toHexString(tex.shareHandle.address));
		
		IDirect3DTexture9 tex2 = device.CreateTexture(1000, 1000, 1, D3DUSAGE_DYNAMIC, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, tex.shareHandle);
		System.err.println(Long.toHexString(tex2.address));
		System.err.println(Long.toHexString(tex2.shareHandle.address));
		//}
		
		System.err.println(tex.Release());
		System.err.println(tex2.Release());
		System.err.println(device.Release());
	}
}
