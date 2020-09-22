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

public class StdOutLoggingService implements LoggingService {

	
	private String toString(int level) {
		switch (level) {
		case 6: return "TRACE";
		case 5: return "DEBUG";
		case 4: return "INFO";
		case 3: return "WARN";
		case 2: return "ERROR";
		}
		return "???";
	}
	
	private String prefix(String level) {
		return String.format("[J] [%1$5s] ", level);
	}
	
	@Override
	public void log(int level, Class<?> context, Supplier<String> message, Throwable exception) {
		if (isActive(level)) {
			System.out.println(prefix(toString(level)) + context.getSimpleName() + ": " + message.get());
			if (exception != null) {
				exception.printStackTrace(System.out);
			}
		}
	}

	@Override
	public boolean isActive(int level) {
		return DriftFXConfig.getLogLevel() >= level;
	}

	
	
	
	
}
