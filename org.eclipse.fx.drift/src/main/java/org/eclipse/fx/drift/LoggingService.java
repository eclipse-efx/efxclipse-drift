package org.eclipse.fx.drift;

import java.util.function.Supplier;

/**
 * Allow custom logging.
 * <p>Drift uses the following log levels</p>
 * <ul>
 * <li>TRACE - 6
 * <li>DEBUG - 5
 * <li>INFO  - 4
 * <li>WARN  - 3
 * <li>ERROR - 2
 * <li>(reserved) - 1
 * <li>OFF   - 0
 * </ul>
 * <p>The default implementation uses the log level from the drift configuration.</p>
 */
public interface LoggingService {

	void log(int level, Class<?> context, Supplier<String> message, Throwable exception);
	
	boolean isActive(int level);
	
}
