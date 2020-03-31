package org.eclipse.fx.drift.internal.backend;

import static org.eclipse.fx.drift.internal.GL.glDeleteTexture;
import static org.eclipse.fx.drift.internal.GL.glGenTexture;

import org.eclipse.fx.drift.internal.GL;
import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.common.NVDXInteropImageData;
import org.eclipse.fx.drift.internal.jni.win32.D3D9;
import org.eclipse.fx.drift.internal.jni.win32.NVDXInterop;
import org.eclipse.fx.drift.internal.jni.win32.Win32;
import org.eclipse.fx.drift.internal.jni.win32.WindowsError;
import org.eclipse.fx.drift.internal.math.Vec2i;

public class NVDXInteropImage implements Image {

	public static final ImageType TYPE = new ImageType("NVDXInterop");
	
	
	private int number;
	private Vec2i size;
	
	private NVDXInteropImageData data;
	
	int glTexture;
	
	static Win32.IDirect3DDevice9Ex dxDevice = D3D9.CreateOffscreenDevice();
//	private static DXInteropDevice dxInteropDevice = new DXInteropDevice(dxDevice);
	
	private static Win32.HANDLE hDevice;
	private Win32.HANDLE hObject;
	
	Win32.IDirect3DTexture9 dxTexture;
	Win32.HANDLE dxTextureShareHandle;
	
	
	public NVDXInteropImage(int number, Vec2i size) {
		this.number = number;
		this.size = size;
	}
	
	@Override
	public ImageData getData() {
		return data;
	}
	
	@Override
	public int getGLTexture() {
		return glTexture;
	}
	
	@Override
	public void allocate() {
		try {
			// TODO hDevice management, we only want to have one
			if (hDevice == null) hDevice = NVDXInterop.wglDXOpenDeviceNV(dxDevice);
			
			glTexture = glGenTexture();
	
			dxTexture = dxDevice.CreateTexture(size.x, size.y, 0, Win32.D3DUSAGE_DYNAMIC, Win32.D3DFMT_A8R8G8B8, Win32.D3DPOOL_DEFAULT);
			NVDXInterop.wglDXSetResourceShareHandleNV(dxTexture, dxTexture.shareHandle);
			// TODO add constant: WGL_ACCESS_READ_WRITE_NV 0x0001
			hObject = NVDXInterop.wglDXRegisterObjectNV(hDevice, dxTexture, glTexture, GL.GL_TEXTURE_2D, 0x0001);
			
			this.data = new NVDXInteropImageData(number, size, dxTexture.shareHandle.address);
		}
		catch (WindowsError e) {
			throw new RuntimeException(e);
		}
	}
	
	@Override
	public void release() {
		try {
			NVDXInterop.wglDXUnregisterObjectNV(hDevice, hObject);
			
			glDeleteTexture(glTexture);
			dxTexture.Release();
		}
		catch (WindowsError e) {
			throw new RuntimeException(e);
		}
	}
	
	@Override
	public void beforeRender() {
		try {
			NVDXInterop.wglDXLockObjectsNV(hDevice, hObject);
		}
		catch (WindowsError e) {
			throw new RuntimeException(e);
		}
	}
	
	@Override
	public void afterRender() {
		try {
			NVDXInterop.wglDXUnlockObjectsNV(hDevice, hObject);
		}
		catch (WindowsError e) {
			throw new RuntimeException(e);
		}
	}
}
