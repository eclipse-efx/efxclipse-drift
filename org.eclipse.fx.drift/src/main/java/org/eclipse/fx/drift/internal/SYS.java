package org.eclipse.fx.drift.internal;

public class SYS {

	static {
		System.loadLibrary("driftfx");
	}
	
	public static native long malloc(int size);
	public static native void free(long pointer);
	public static native void memcpy(long pDst, long pSrc, int size);
	
}
