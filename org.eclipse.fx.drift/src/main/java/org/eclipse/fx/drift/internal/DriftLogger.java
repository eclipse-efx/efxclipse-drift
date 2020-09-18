package org.eclipse.fx.drift.internal;

import java.util.function.Supplier;

public interface DriftLogger {
	
	void trace(Supplier<String> msg);
	
	void debug(Supplier<String> msg);
	
	void info(Supplier<String> msg);
	
	void warn(Supplier<String> msg);
	
	void error(Supplier<String> msg);
	
	void error(Supplier<String> msg, Throwable t);
	
	boolean isTraceEnabled();
	boolean isDebugEnabled();
	boolean isInfoEnabled();
	boolean isWarnEnabled();
	boolean isErrorEnabled();
}
