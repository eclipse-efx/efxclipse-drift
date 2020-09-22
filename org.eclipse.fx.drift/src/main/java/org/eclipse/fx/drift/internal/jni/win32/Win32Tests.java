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
package org.eclipse.fx.drift.internal.jni.win32;

import static org.eclipse.fx.drift.internal.jni.win32.Win32.D3DFMT_A8R8G8B8;
import static org.eclipse.fx.drift.internal.jni.win32.Win32.D3DPOOL_DEFAULT;
import static org.eclipse.fx.drift.internal.jni.win32.Win32.D3DUSAGE_DYNAMIC;

import org.eclipse.fx.drift.internal.DriftFX;
import org.eclipse.fx.drift.internal.jni.win32.Win32.IDirect3DDevice9Ex;
import org.eclipse.fx.drift.internal.jni.win32.Win32.IDirect3DTexture9;
public class Win32Tests {

	public static void main(String[] args) throws WindowsError {
		DriftFX.require();
		
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
