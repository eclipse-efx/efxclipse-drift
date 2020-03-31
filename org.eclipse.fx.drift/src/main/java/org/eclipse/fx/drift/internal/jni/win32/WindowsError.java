package org.eclipse.fx.drift.internal.jni.win32;

public class WindowsError extends Exception {
	public final int errorCode;
	public final ErrorCode error;
	
	private static String createMessage(int errorCode) {
		return "0x" + Integer.toHexString(errorCode) + ": " + ErrorCode.fromValue(errorCode);
	}
	
	public WindowsError(int errorCode) {
		super(createMessage(errorCode));
		this.errorCode = errorCode;
		this.error = ErrorCode.fromValue(errorCode);
	}
	
	private static boolean checkErrors = true;
	
	
	public static native int getLastError();
	public static void checkLastError() throws WindowsError {
		if (checkErrors) {
			int error = getLastError();
			if (error != 0) {
				throw new WindowsError(error);
			}
		}
	}
}
