package org.eclipse.fx.drift.internal.jni.win32;

import java.util.Optional;
import java.util.stream.Stream;

public enum ErrorCode {
	ERROR_INVALID_HANDLE(0x6),
	ERROR_INVALID_DATA(0xD),
	ERROR_OPEN_FAILED(0x6E),
	ERROR_NOT_SUPPORTED(0x32),
	ERROR_NOT_LOCKED(0x9E),
	ERROR_LOCK_FAILED(0xA7),
	ERROR_BUSY(0xAA);
	
	public int value;
	
	private ErrorCode(int value) {
		this.value = value;
	}
	
	public static ErrorCode fromValue(int value) {
		Optional<ErrorCode> code = Stream.of(values()).filter(v -> v.value == value).findFirst();
		if (code.isPresent()) {
			return code.get();
		}
		else {
			System.err.println("Error code not yet supported: " + Integer.toHexString(value));
			Thread.dumpStack();
			return null;
		}
	}
}
