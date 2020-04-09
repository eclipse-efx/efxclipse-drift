package org.eclipse.fx.drift.internal.jni.win32;

import java.util.Optional;
import java.util.stream.Stream;

public enum HRESULT {
	E_OUTOFMEMORY(0x8007000EL),
	E_INVALIDARG(0x80070057L),
	D3DERR_INVALIDCALL(((1l)<<31) | ((0x876l)<<16) | ((2156l)) ),
	D3DERR_OUTOFVIDEOMEMORY(((1l)<<31) | ((0x876l)<<16) | ((380l)));
	
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
			System.err.println("Error code not yet supported: " + Long.toHexString(value));
			Thread.dumpStack();
			return null;
		}
	}
}
