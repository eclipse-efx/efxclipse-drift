package org.eclipse.fx.drift.internal;

import java.util.function.Supplier;

public class StdOutLogger implements DriftLogger {

	private Class<?> ctx;
	
	public StdOutLogger(Class<?> ctx) {
		this.ctx = ctx;
	}
	
	@Override
	public void trace(Supplier<String> msg) {
		if (isTraceEnabled()) {
			System.out.println("[J] [TRACE] " + ctx.getSimpleName() + ": " + msg.get());
		}
	}

	@Override
	public void debug(Supplier<String> msg) {
		if (isDebugEnabled()) {
			System.out.println("[J] [DEBUG] " + ctx.getSimpleName() + ": " + msg.get());
		}
	}

	@Override
	public void info(Supplier<String> msg) {
		if (isInfoEnabled()) {
			System.out.println("[J] [INFO ] " + ctx.getSimpleName() + ": " + msg.get());
		}
	}
	
	@Override
	public void warn(Supplier<String> msg) {
		if (isWarnEnabled()) {
			System.out.println("[J] [WARN ] " + ctx.getSimpleName() + ": " + msg.get());
		}
	}

	@Override
	public void error(Supplier<String> msg) {
		if (isErrorEnabled()) {
			System.out.println("[J] [ERROR] " + ctx.getSimpleName() + ": " + msg.get());
		}
	}
	
	@Override
	public void error(Supplier<String> msg, Throwable t) {
		if (isErrorEnabled()) {
			System.out.println("[J] [ERROR] " + ctx.getSimpleName() + ": " + msg.get());
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
