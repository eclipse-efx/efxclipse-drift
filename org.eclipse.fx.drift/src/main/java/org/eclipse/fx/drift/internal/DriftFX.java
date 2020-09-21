package org.eclipse.fx.drift.internal;

import org.eclipse.fx.drift.util.NativeUtil;

public final class DriftFX {
	private static final DriftLogger LOGGER = DriftFX.createLogger(DriftFX.class);
	
	
	private static boolean once = false;
	
	private DriftFX() {
	}
	
	public static DriftLogger createLogger(Class<?> context) {
		return new DefaultLogger(context);
	}
	
	public static void require() {
		if (!once) {
			LOGGER.debug(() -> "Initialize DriftFX");
			initOnce();
			once = true;
		}
	}
	
	public static void initOnce() {
		NativeUtil.loadLibrary(DriftFX.class, "driftfx", System::loadLibrary, System::load);
	}
	
	
}
