package org.eclipse.fx.drift.internal;

import java.util.function.Supplier;

public class StdOutLogger implements DriftLogger {

	private Class<?> ctx;
	
	public StdOutLogger(Class<?> ctx) {
		this.ctx = ctx;
	}
	
	private String prefix(String level) {
		return String.format("[J] [%1$5s] ", level);
	}
	
	@Override
	public void trace(Supplier<String> msg) {
		if (isTraceEnabled()) {
			System.out.println(prefix("TRACE") + ctx.getSimpleName() + ": " + msg.get());
		}
	}

	@Override
	public void debug(Supplier<String> msg) {
		if (isDebugEnabled()) {
			System.out.println(prefix("DEBUG") + ctx.getSimpleName() + ": " + msg.get());
		}
	}

	@Override
	public void info(Supplier<String> msg) {
		if (isInfoEnabled()) {
			System.out.println(prefix("INFO") + ctx.getSimpleName() + ": " + msg.get());
		}
	}
	
	@Override
	public void warn(Supplier<String> msg) {
		if (isWarnEnabled()) {
			System.out.println(prefix("WARN") + ctx.getSimpleName() + ": " + msg.get());
		}
	}

	@Override
	public void error(Supplier<String> msg) {
		if (isErrorEnabled()) {
			System.out.println(prefix("ERROR") + ctx.getSimpleName() + ": " + msg.get());
		}
	}
	
	@Override
	public void error(Supplier<String> msg, Throwable t) {
		if (isErrorEnabled()) {
			System.out.println(prefix("ERROR") + ctx.getSimpleName() + ": " + msg.get());
			t.printStackTrace(System.out);
		}
	}

	@Override
	public boolean isTraceEnabled() {
		return false;
	}

	@Override
	public boolean isDebugEnabled() {
		return true;
	}

	@Override
	public boolean isInfoEnabled() {
		return true;
	}
	
	@Override
	public boolean isWarnEnabled() {
		return true;
	}

	@Override
	public boolean isErrorEnabled() {
		return true;
	}

}
