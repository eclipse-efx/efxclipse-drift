package org.eclipse.fx.drift.internal.jni.win32;

import org.eclipse.fx.drift.internal.GL;
import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

public class TestNV_DX_Interop {

	long glContext;
	Win32.IDirect3DDevice9Ex dxDevice;
	
	int name;
	Win32.IDirect3DTexture9 texture;
	
	@BeforeClass
	public static void setupGlobal() {
		System.loadLibrary("DriftGL");
		System.loadLibrary("driftfx");
	}
	
	@Before
	public void before() throws WindowsError {
		glContext = GL.createContext(0, 3, 2);
		dxDevice = D3D9.CreateOffscreenDevice();
		
		GL.makeContextCurrent(glContext);
		
		name = GL.glGenTexture();
		GL.glBindTexture(GL.GL_TEXTURE_2D, name);
		GL.glTexImage2D(GL.GL_TEXTURE_2D, 1, GL.GL_RGBA, 100, 100, 0, GL.GL_RGBA, GL.GL_UNSIGNED_INT_8_8_8_8_REV, 0);
		GL.glBindTexture(GL.GL_TEXTURE_2D, 0);
		
		texture = dxDevice.CreateTexture(100, 100, 0, Win32.D3DUSAGE_DYNAMIC, Win32.D3DFMT_A8R8G8B8, Win32.D3DPOOL_DEFAULT);
	}
	
	@After
	public void after() {
		GL.glDeleteTexture(name);
		// TODO delete glContext
		
		texture.Release();
		dxDevice.Release();
	}
	
	@Test
	public void testOpenDevice() throws WindowsError {
		Win32.HANDLE hDevice = NVDXInterop.wglDXOpenDeviceNV(dxDevice);
		Assert.assertNotEquals(0, hDevice.address);
		
		boolean closeDevice = NVDXInterop.wglDXCloseDeviceNV(hDevice);
		Assert.assertTrue(closeDevice);
	}
	
	@Test
	public void testRegisterObject() throws WindowsError {
		Win32.HANDLE hDevice = NVDXInterop.wglDXOpenDeviceNV(dxDevice);
		Assert.assertNotEquals(0, hDevice.address);
		boolean setHandle = NVDXInterop.wglDXSetResourceShareHandleNV(texture, texture.shareHandle);
		Assert.assertTrue(setHandle);
		
		Win32.HANDLE hObject = NVDXInterop.wglDXRegisterObjectNV(hDevice, texture, name, GL.GL_TEXTURE_2D, 0x0002);
		Assert.assertNotEquals(0, hObject.address);
		
		boolean unregisterObject = NVDXInterop.wglDXUnregisterObjectNV(hDevice, hObject);
		Assert.assertTrue(unregisterObject);
		
		boolean closeDevice = NVDXInterop.wglDXCloseDeviceNV(hDevice);
		Assert.assertTrue(closeDevice);
	}
	
	@Test
	public void testLockObject() throws WindowsError {
		Win32.HANDLE hDevice = NVDXInterop.wglDXOpenDeviceNV(dxDevice);
		Assert.assertNotEquals(0, hDevice.address);
		boolean setHandle = NVDXInterop.wglDXSetResourceShareHandleNV(texture, texture.shareHandle);
		Assert.assertTrue(setHandle);
		
		Win32.HANDLE hObject = NVDXInterop.wglDXRegisterObjectNV(hDevice, texture, name, GL.GL_TEXTURE_2D, 0x0002);
		Assert.assertNotEquals(0, hObject.address);
		
		boolean lock = NVDXInterop.wglDXLockObjectsNV(hDevice, hObject);
		Assert.assertTrue(lock);
		
		boolean unlock = NVDXInterop.wglDXUnlockObjectsNV(hDevice, hObject);
		Assert.assertTrue(unlock);
		
		boolean unregisterObject = NVDXInterop.wglDXUnregisterObjectNV(hDevice, hObject);
		Assert.assertTrue(unregisterObject);
		
		boolean closeDevice = NVDXInterop.wglDXCloseDeviceNV(hDevice);
		Assert.assertTrue(closeDevice);
	}
	
	
}
