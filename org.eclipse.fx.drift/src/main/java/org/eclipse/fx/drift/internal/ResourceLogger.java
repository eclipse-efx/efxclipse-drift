package org.eclipse.fx.drift.internal;

public class ResourceLogger {

	
	public static void resourceAllocated(long id, String type, String nfo) {
		System.err.println("RESOURCE: + " + type + "(0x"+ Long.toHexString(id) + ") " + nfo);
	}
	
	public static void resourceDisposed(long id) {
		System.err.println("RESOURCE: - 0x" + Long.toHexString(id));
	}

	
}
