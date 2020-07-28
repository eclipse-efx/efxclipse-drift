package org.eclipse.fx.drift.internal;

import org.eclipse.fx.drift.util.NativeUtil;

public class SYS {

	static {
		NativeUtil.loadLibrary(SYS.class, "driftfx");
	}
	
	public static native long malloc(int size);
	public static native void free(long pointer);
	public static native void memcpy(long pDst, long pSrc, int size);
	
}
