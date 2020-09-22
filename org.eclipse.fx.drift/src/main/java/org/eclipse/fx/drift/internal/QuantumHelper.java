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

import java.util.concurrent.Executor;
import java.util.concurrent.Executors;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

import org.eclipse.fx.drift.internal.jni.macos.MacOS;
import org.eclipse.fx.drift.internal.prism.Prism;

import com.sun.prism.ResourceFactory;

@SuppressWarnings("restriction")
public class QuantumHelper {
	private static final DriftLogger LOGGER = DriftFX.createLogger(QuantumHelper.class);
	
	private static Executor executor;
	private static long glContext;
	
	private static Thread createThread(Runnable runnable) {
		Thread thread = new Thread(runnable);
		thread.setName("DriftFX - QuantumHelper");
		thread.setDaemon(true);
		return thread;
	}
	
	private static void initializeContext(ResourceFactory rf) {
		if (Prism.isES2()) {
			long prismContext = Prism.getES2ContextHandle(); 
			long wrapContext = GL.wrapContext(prismContext);
//			glContext = GL.createSharedCompatContext(wrapContext);
			glContext = GL.createContext(wrapContext, 2, 0);
			boolean su = GL.makeContextCurrent(glContext);
			LOGGER.debug(() -> "QuantumHelper#initializeContext");
			LOGGER.debug(() -> "prismContext = " + prismContext);
			LOGGER.debug(() -> "glContext = " + glContext);
			LOGGER.debug(() -> "makeCurrent: " + su);
			
			long nativeHandle = GL.getNativeContextHandle(glContext);
			LOGGER.debug(() -> "nativeHandle = " + nativeHandle);
			LOGGER.debug(() -> "CGLGetCurrent = " + MacOS.CGLGetCurrentContext() ) ;
		}
	}
	
	private static void initialize(ResourceFactory rf) {
		if (executor == null) {
			executor = Executors.newSingleThreadExecutor(QuantumHelper::createThread);
			executor.execute(() -> initializeContext(rf));
		}
	}
	
	public static void execute(ResourceFactory rf, Runnable command) {
		initialize(rf);
		executor.execute(command);
	}
	
	public static void syncExecute(ResourceFactory rf, Runnable command) {
		initialize(rf);
		internalSyncExecute(command);
	}
	
	static void internalSyncExecute(Runnable r) {
		ReentrantLock lock = new ReentrantLock();
		Condition done = lock.newCondition();
		lock.lock();
		executor.execute(() -> {
			lock.lock();
			r.run();
			done.signal();
			lock.unlock();
		});
		try {
			done.await();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
	
}
