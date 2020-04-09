package org.eclipse.fx.drift.internal.jni.win32;

public class WindowsError extends Exception {
	public final int errorCode;
	public final ErrorCode error;
	public final long hresultCode;
	public final HRESULT hresult;
	
	private static String createMessage(int errorCode) {
		return "0x" + Integer.toHexString(errorCode) + ": " + ErrorCode.fromValue(errorCode);
	}
	private static String createHResultMessage(long hresult) {
		return "HRESULT 0x" + Long.toHexString(hresult) + ": " + HRESULT.fromValue(hresult);
	}
	
	public WindowsError(int errorCode) {
		super(createMessage(errorCode));
		this.errorCode = errorCode;
		this.error = ErrorCode.fromValue(errorCode);
		this.hresultCode = 0;
		this.hresult = null;
	}
	public WindowsError(long hresult) {
		super(createHResultMessage(hresult));
		this.hresultCode = hresult;
		this.hresult = HRESULT.fromValue(hresult);
		this.errorCode = 0;
		this.error = null;
	}
	
	private static boolean checkErrors = true;
	
	
	public static native int getLastError();
	public static void checkLastError() throws WindowsError {
		if (checkErrors) {
			int error = getLastError();
			if (error != 0) {
				throw WindowsError.fromErrorCode(error);
			}
		}
	}
	public static void checkHResult(long hresult) throws WindowsError {
		hresult = hresult & 0xFFFF_FFFFL;
		if (checkErrors) {
			if (hresult != 0) {
				throw WindowsError.fromHResult(hresult);
			}
		}
	}

	private static WindowsError fromHResult(long hresult) {
		return new WindowsError(hresult);
	}
	
	private static WindowsError fromErrorCode(int errorCode) {
		return new WindowsError(errorCode);
	}
}
