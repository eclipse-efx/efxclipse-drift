package org.eclipse.fx.drift.internal;

import org.eclipse.fx.drift.util.NativeUtil;

public final class DriftFX {
	
	private static boolean once = false;
	
	private DriftFX() {
	}
	
	public static void require() {
		if (!once) {
			Log.debug("Initialize DriftFX");
			initOnce();
			once = true;
		}
	}
	
	public static void initOnce() {
		NativeUtil.loadLibrary(DriftFX.class, "driftfx", System::loadLibrary, System::load);
	}
}
