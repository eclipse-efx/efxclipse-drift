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
