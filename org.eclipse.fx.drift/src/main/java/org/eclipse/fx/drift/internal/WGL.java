package org.eclipse.fx.drift.internal;

public class WGL {

	public final static int WGL_ACCESS_READ_ONLY_NV = 0x0000;
	public final static int WGL_ACCESS_READ_WRITE_NV = 0x0001;
	public final static int WGL_ACCESS_WRITE_DISCARD_NV = 0x0002;
	
	public static native boolean wglDXSetResourceShareHandleNV(long texture, long shareHandle);
	public static native long wglDXRegisterObjectNV(long hDevice, long dxObject, int name, int type, int access);
	public static native boolean wglDXUnregisterObjectNV(long hDevice, long hObject);
	public static native boolean wglDXLockObjectsNV(long hDevice, int num, long[] objects);
	public static native boolean wglDXUnlockObjectsNV(long hDevice, int num, long[] objects);
	public static native boolean wglDXObjectAccessNV(long hObject, int access);
	public static native long wglDXOpenDeviceNV(long dxDevice);
	public static native boolean wglDXCloseDeviceNV(long hDevice);
	
	public static boolean wglDXLockObjectsNV(long hDevice, long... objects) {
		return wglDXLockObjectsNV(hDevice, objects.length, objects);
	}
	public static boolean wglDXUnlockObjectsNV(long hDevice, long... objects) {
		return wglDXUnlockObjectsNV(hDevice, objects.length, objects);
	}
}
