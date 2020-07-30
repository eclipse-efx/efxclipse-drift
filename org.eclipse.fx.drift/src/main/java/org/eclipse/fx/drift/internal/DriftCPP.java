package org.eclipse.fx.drift.internal;

import org.eclipse.fx.drift.util.NativeUtil;

public final class DriftCPP {

	private static boolean once = false;
	/*package*/ static ClassLoader classLoader;
	
	private DriftCPP() {
	}
	
	public static void require() {
		if (!once) {
			Log.debug("Initialize DriftCPP (using classLoader="+classLoader+")");
			initOnce();
			once = true;
		}
	}
	
	private static void initOnce() {
		NativeUtil.loadLibrary(DriftCPP.class, "driftcpp");
		init(classLoader == null ? DriftCPP.class.getClassLoader() : classLoader);
	}
	
	public static native void init(ClassLoader classLoader);
	public static native void dispose();
	
}
