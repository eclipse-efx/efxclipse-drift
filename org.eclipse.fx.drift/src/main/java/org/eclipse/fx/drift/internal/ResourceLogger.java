package org.eclipse.fx.drift.internal;

public class ResourceLogger {
	private static final DriftLogger LOGGER = DriftFX.createLogger(ResourceLogger.class);
	
	
	public static void resourceAllocated(long id, String type, String nfo) {
		LOGGER.debug(() -> "RESOURCE: + " + type + "(0x"+ Long.toHexString(id) + ") " + nfo);
	}
	
	public static void resourceDisposed(long id) {
		LOGGER.debug(() -> "RESOURCE: - 0x" + Long.toHexString(id));
	}

	
}
