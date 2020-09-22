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

public final class Prism {
	
	private Prism() {}

	public static Win32.IDirect3DDevice9Ex getPrismIDirect3DDevice9Ex(long prismD3DContext) {
		long address = nGetPrismIDirect3DDevice9Ex(prismD3DContext);
		return new Win32.IDirect3DDevice9Ex(address);
	}
	
	public static native long nGetPrismIDirect3DDevice9Ex(long prismD3DContext);
	
	
	public static void replacePrismD3DTexture(long prismTexture, Win32.IDirect3DTexture9 texture) {
		nReplacePrismD3DTexture(prismTexture, texture.address);
	}
	
	public native static void nReplacePrismD3DTexture(long prismTexture, long texture);
}
