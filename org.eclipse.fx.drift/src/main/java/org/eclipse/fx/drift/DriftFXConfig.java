package org.eclipse.fx.drift;

import java.util.HashMap;
import java.util.Map;
import java.util.function.Function;

import org.eclipse.fx.drift.internal.StdOutLoggingService;

/**
 * Configures drift.
 * <p>The properties initialisation order is system properties and then defaults. The defaults can be found in the static initialiser below. User Code can change all properties before drift is used.</p>
 * <p>The properties may also be changed after drift is used, but it is not guaranteed that already created systems will update accordingly.</p>
 */
public final class DriftFXConfig {
	private static final Map<String, ConfigValue<?>> CONFIG = new HashMap<>();
	
	private static final String KEY_LOG_LEVEL = "driftfx.loglevel";
	private static final String KEY_SHOW_FPS = "driftfx.showfps";
	private static final String KEY_USE_JAVA_LIBRARY_PATH = "driftfx.use.java.library.path";
	private static final String KEY_LOGGING_SERVICE = "driftfx.logging.service";
	
	static {
		register(new ConfigValue<Integer>(KEY_LOG_LEVEL, 0, Integer::parseInt));
		register(new ConfigValue<Boolean>(KEY_SHOW_FPS, false, Boolean::parseBoolean));
		register(new ConfigValue<Boolean>(KEY_USE_JAVA_LIBRARY_PATH, false, Boolean::parseBoolean));
		register(new ConfigValue<LoggingService>(KEY_LOGGING_SERVICE, new StdOutLoggingService(), DriftFXConfig::convert));
	}
	
	private DriftFXConfig() {}
	
	private static LoggingService convert(String name) {
		try {
			return (LoggingService) Class.forName(name).newInstance();
		} catch (InstantiationException | IllegalAccessException | ClassNotFoundException e) {
			e.printStackTrace();
			return new StdOutLoggingService();
		}
	}
	
	private static class ConfigValue<T> {
		private final String key;
		private final Function<String, T> converter;
		private final T defaultValue;
		
		private T value;
		
		public ConfigValue(String key, T defaultValue, Function<String, T> converter) {
			this.key = key;
			this.defaultValue = defaultValue;
			this.converter = converter;
			
			initialize();
		}
		
		public final void initialize() {
			String propValue = System.getProperty(key);
			if (propValue != null) {
				this.value = converter.apply(propValue);
			} else {
				this.value = defaultValue;
			}
		}
		
		public T getValue() {
			return value;
		}
		public void setValue(T value) {
			this.value = value;
		}
	}
	
	
	private static <T> void register(ConfigValue<T> value) {
		CONFIG.put(value.key, value);
	}
	@SuppressWarnings("unchecked")
	private static <T> ConfigValue<T> get(String key) {
		return (ConfigValue<T>) CONFIG.get(key);
	}
	
	public static int getLogLevel() {
		return DriftFXConfig.<Integer>get(KEY_LOG_LEVEL).getValue();
	}
	
	public static void setLogLevel(int logLevel) {
		DriftFXConfig.<Integer>get(KEY_LOG_LEVEL).setValue(logLevel);
	}
	
	public static boolean isShowFps() {
		return DriftFXConfig.<Boolean>get(KEY_SHOW_FPS).getValue();
	}
	
	public static void setShowFps(boolean showFps) {
		DriftFXConfig.<Boolean>get(KEY_SHOW_FPS).setValue(showFps);
	}
	
	public static boolean isUseJavaLibraryPath() {
		return DriftFXConfig.<Boolean>get(KEY_USE_JAVA_LIBRARY_PATH).getValue();
	}
	
	public static void setUseJavaLibraryPath(boolean useJavaLibraryPath) {
		DriftFXConfig.<Boolean>get(KEY_USE_JAVA_LIBRARY_PATH).setValue(useJavaLibraryPath);
	}
	
	public static LoggingService getLoggingService() {
		return DriftFXConfig.<LoggingService>get(KEY_LOGGING_SERVICE).getValue();
	}
	
	public static void setLoggingService(LoggingService service) {
		DriftFXConfig.<LoggingService>get(KEY_LOGGING_SERVICE).setValue(service);
	}
	
}
