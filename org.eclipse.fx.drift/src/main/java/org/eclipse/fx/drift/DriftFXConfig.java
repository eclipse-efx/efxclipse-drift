package org.eclipse.fx.drift;

import org.eclipse.fx.drift.internal.Configuration;

public class DriftFXConfig {

	private boolean debug;
	private boolean useWinFallback;
	private int logLevel;
	
	public static DriftFXConfig initDefaults() {
		DriftFXConfig config = new DriftFXConfig();
		config.debug = false;
		config.useWinFallback = false;
		config.logLevel = 1;
		return config;
	}
	
	public static DriftFXConfig initSystemProperties() {
		DriftFXConfig config = new DriftFXConfig();
		config.debug = Configuration.getBoolean(Configuration.KEY_DEBUG, false);
		config.useWinFallback = Configuration.getBoolean(Configuration.KEY_USEWINFALLBACK, false);
		config.logLevel = Configuration.getInt(Configuration.KEY_LOGLEVEL, 1);
		return config;
	}
	
	public DriftFXConfig debug(boolean debug) {
		this.debug = debug;
		return this;
	}
	
	public DriftFXConfig useWinFallback(boolean useWinFallback) {
		this.useWinFallback = useWinFallback;
		return this;
	}
	
	public DriftFXConfig logLevel(int level) {
		this.logLevel = level;
		return this;
	}
	
	public boolean isDebug() {
		return debug;
	}
	public boolean isUseWinFallback() {
		return useWinFallback;
	}
	public int getLogLevel() {
		return logLevel;
	}
	
	
	
}
