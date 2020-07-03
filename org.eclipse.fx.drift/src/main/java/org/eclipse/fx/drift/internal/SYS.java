package org.eclipse.fx.drift.internal;

public class SYS {

	static {
		NativeLoader.loadLibrary(SYS.class, "driftfx");
	}
	
	public static native long malloc(int size);
	public static native void free(long pointer);
	public static native void memcpy(long pDst, long pSrc, int size);
	
}
