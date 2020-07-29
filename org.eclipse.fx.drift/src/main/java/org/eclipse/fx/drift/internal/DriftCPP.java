package org.eclipse.fx.drift.internal;

import org.eclipse.fx.drift.util.NativeUtil;

public class DriftCPP {

	static {
		NativeUtil.loadLibrary(DriftCPP.class, "driftcpp");
	}
	
	static native void init(ClassLoader classLoader);
	static native void dispose();
	
}
