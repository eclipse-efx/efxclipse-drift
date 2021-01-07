/* ******************************************************************************
 * Copyright (c) 2019, 2020 BestSolution.at and others.
 * All rights reserved. This program and the accompanying materials 
 * are made available under the terms of the Eclipse Public License 2.0 
 * which is available at http://www.eclipse.org/legal/epl-2.0
 *
 * SPDX-License-Identifier: EPL-2.0
 * 
 * Contributors:
 *     Christoph Caks <ccaks@bestsolution.at> - initial API and implementation
 * ******************************************************************************/
package org.eclipse.fx.drift.internal.backend;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import org.eclipse.fx.drift.internal.DriftFX;
import org.eclipse.fx.drift.internal.DriftLogger;
import org.eclipse.fx.drift.internal.GL;
import org.eclipse.fx.drift.internal.jni.win32.NVDXInterop;
import org.eclipse.fx.drift.internal.jni.win32.Win32;
import org.eclipse.fx.drift.internal.jni.win32.WindowsError;

public class NVDXInteropDevice {
	private static final DriftLogger LOGGER = DriftFX.createLogger(NVDXInteropDevice.class);
	
	public final Win32.HANDLE hDevice;
	private Win32.IDirect3DDevice9Ex dxDevice;
	private long glContext;
	private long threadId;
	
	private NVDXInteropDevice(Win32.HANDLE hDevice) {
		this.hDevice = hDevice;
	}
	
	@Override
	public String toString() {
		return "NVDXInteropDevice " + hDevice + " / " + dxDevice + " / " + glContext + " / " + threadId;
	}
	
	private int usageCount = 0;
	
	private static List<NVDXInteropDevice> devices = new ArrayList<>();
	
	public static NVDXInteropDevice openDevice(Win32.IDirect3DDevice9Ex dxDevice) throws WindowsError {
		synchronized (devices) {
			long threadId = Thread.currentThread().getId();
			long glContext = GL.getCurrentContext();
			NVDXInteropDevice device = null;
			Optional<NVDXInteropDevice> existing = devices.stream().filter(dev -> 
				dev.glContext == glContext && 
				dev.dxDevice.address == dxDevice.address &&
				dev.threadId == threadId).findFirst();
			if (existing.isPresent()) {
				device = existing.get();
			}
			else {
				device = new NVDXInteropDevice(NVDXInterop.wglDXOpenDeviceNV(dxDevice));
				device.glContext = glContext;
				device.dxDevice = dxDevice;
				device.threadId = threadId;
				devices.add(device);
			}
		
			device.usageCount++;
			
			NVDXInteropDevice fDevice = device;
			LOGGER.debug(() -> "" + fDevice);
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
