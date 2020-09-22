/* ******************************************************************************
 * Copyright (c) 2019, 2020 BestSolution.at and others.
 * All rights reserved. This program and the accompanying materials 
 * are made available under the terms of the Eclipse Public License 2.0 
 * which is available at http://www.eclipse.org/legal/epl-2.0
 *
 * SPDX-License-Identifier: EPL-2.0
 * 
 * Contributors:
 *     Christoph Caks <ccaks@bestsolution.at> - initial API and implementation
 * ******************************************************************************/
package org.eclipse.fx.drift.internal;

import java.util.function.Supplier;

import org.eclipse.fx.drift.DriftFXConfig;
import org.eclipse.fx.drift.LoggingService;

public class DefaultLogger implements DriftLogger {

	private Class<?> ctx;
	
	private LoggingService loggingService;
	
	public DefaultLogger(Class<?> ctx) {
		this.ctx = ctx;
		loggingService = DriftFXConfig.getLoggingService();
	}
	
	@Override
	public void trace(Supplier<String> msg) {
		loggingService.log(6, ctx, msg, null);
	}

	@Override
	public void debug(Supplier<String> msg) {
		loggingService.log(5, ctx, msg, null);
	}

	@Override
	public void info(Supplier<String> msg) {
		loggingService.log(4, ctx, msg, null);
	}
	
	@Override
	public void warn(Supplier<String> msg) {
		loggingService.log(3, ctx, msg, null);
	}

	@Override
	public void error(Supplier<String> msg) {
		loggingService.log(2, ctx, msg, null);
	}
	
	@Override
	public void error(Supplier<String> msg, Throwable t) {
		loggingService.log(2, ctx, msg, null);
	}

	@Override
	public boolean isTraceEnabled() {
		return loggingService.isActive(6);
	}

	@Override
	public boolean isDebugEnabled() {
		return loggingService.isActive(5);
	}

	@Override
	public boolean isInfoEnabled() {
		return loggingService.isActive(4);
	}
	
	@Override
	public boolean isWarnEnabled() {
		return loggingService.isActive(3);
	}

	@Override
	public boolean isErrorEnabled() {
		return loggingService.isActive(2);
	}

}
