package org.eclipse.fx.drift.internal;

public final class SYS {

	private SYS() {}
	
	static {
		DriftFX.require();
	}
	
	public static native long malloc(int size);
	public static native void free(long pointer);
	public static native void memcpy(long pDst, long pSrc, int size);
	
}
