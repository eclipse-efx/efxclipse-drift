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

import java.util.Optional;
import java.util.stream.Stream;

import org.eclipse.fx.drift.internal.DriftFX;
import org.eclipse.fx.drift.internal.DriftLogger;

public enum HRESULT {
	E_OUTOFMEMORY(0x8007000EL),
	E_INVALIDARG(0x80070057L),
	D3DERR_INVALIDCALL(((1l)<<31) | ((0x876l)<<16) | ((2156l)) ),
	D3DERR_OUTOFVIDEOMEMORY(((1l)<<31) | ((0x876l)<<16) | ((380l)));
	
	private static final DriftLogger LOGGER = DriftFX.createLogger(HRESULT.class);
	
	public long value;
	
	private HRESULT(long value) {
		this.value = value;
	}
	
	public static HRESULT fromValue(long value) {
		Optional<HRESULT> code = Stream.of(values()).filter(v -> v.value == value).findFirst();
		if (code.isPresent()) {
			return code.get();
		}
		else {
			LOGGER.error(() -> "Error code not yet supported: " + Long.toHexString(value), new Exception());
			return null;
		}
	}
}
