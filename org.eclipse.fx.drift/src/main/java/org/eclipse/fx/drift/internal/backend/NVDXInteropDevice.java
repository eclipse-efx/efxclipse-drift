package org.eclipse.fx.drift.internal.backend;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import org.eclipse.fx.drift.internal.GL;
import org.eclipse.fx.drift.internal.jni.win32.NVDXInterop;
import org.eclipse.fx.drift.internal.jni.win32.Win32;
import org.eclipse.fx.drift.internal.jni.win32.WindowsError;

public class NVDXInteropDevice {

	public final Win32.HANDLE hDevice;
	private Win32.IDirect3DDevice9Ex dxDevice;
	private long glContext;
	
	private NVDXInteropDevice(Win32.HANDLE hDevice) {
		this.hDevice = hDevice;
	}
	
	@Override
	public String toString() {
		return "NVDXInteropDevice " + hDevice + " / " + dxDevice + " / " + glContext;
	}
	
	private int usageCount = 0;
	
	private static List<NVDXInteropDevice> devices = new ArrayList<>();
	
	public static NVDXInteropDevice openDevice(Win32.IDirect3DDevice9Ex dxDevice) throws WindowsError {
		synchronized (devices) {
			long glContext = GL.getCurrentContext();
			NVDXInteropDevice device = null;
			Optional<NVDXInteropDevice> existing = devices.stream().filter(dev -> dev.glContext == glContext && dev.dxDevice.address == dxDevice.address).findFirst();
			if (existing.isPresent()) {
				device = existing.get();
			}
			else {
				device = new NVDXInteropDevice(NVDXInterop.wglDXOpenDeviceNV(dxDevice));
				device.glContext = glContext;
				device.dxDevice = dxDevice;
				devices.add(device);
			}
		
			device.usageCount++;
			System.err.println(device);
			return device;
		}
	}
	
	
	public void closeDevice() throws WindowsError {
		synchronized (devices) {
			usageCount--;
			
			if (usageCount == 0) {
				NVDXInterop.wglDXCloseDeviceNV(hDevice);
				devices.remove(this);
			}
		}
	}
}
