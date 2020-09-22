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
package org.eclipse.fx.drift.impl;

public class DriftDebug {
	public static void assertThreadName(String name) {
		String currentName = Thread.currentThread().getName();
		if (!name.equals(currentName)) {
			throw new RuntimeException("Wrong Thread! expected "+ name +", got " + currentName);
		}
	}
	public static void assertQuantumRenderer() {
		assertThreadName("QuantumRenderer-0");
	}
	public static void assertJavaFXApplicationThread() {
		assertThreadName("JavaFX Application Thread");
	}
	public static void outputThread() {
		//StackTraceElement[] stack = Thread.currentThread().getStackTrace();
		//StackTraceElement source = stack[2];
		//System.out.println(Thread.currentThread().getName() + " - " + source.getClassName() + "#" + source.getMethodName());
	}
}
