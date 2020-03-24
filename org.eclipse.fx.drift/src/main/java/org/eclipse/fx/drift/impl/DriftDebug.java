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
		StackTraceElement[] stack = Thread.currentThread().getStackTrace();
		StackTraceElement source = stack[2];
		//System.out.println(Thread.currentThread().getName() + " - " + source.getClassName() + "#" + source.getMethodName());
	}
}
