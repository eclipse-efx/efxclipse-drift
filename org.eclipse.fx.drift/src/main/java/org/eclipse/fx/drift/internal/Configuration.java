package org.eclipse.fx.drift.internal;

public class Configuration {

	public static final boolean DEBUG = getBoolean("driftfx.debug", false);
	public static final int LOGLEVEL = getInt("driftfx.loglevel", 1);

	private static boolean getBoolean(String name, boolean defaultValue) {
		if (null == System.getProperty(name)) {
			return defaultValue;
		}
		else {
			return Boolean.getBoolean(name); 
		}
	}
	
	private static int getInt(String name, int defaultValue) {
		String prop = System.getProperty(name);
		try {
			return Integer.parseInt(prop);
		}
		catch (Throwable t) {
			return defaultValue;
		}
	}
	
}
