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

public class FPSCounter {
	
	long thisFrameTime;
	long frameTime;
	long frameStart;
	long lastLoop;
	long time;
	
	double smoothing = 1.0;
	
	public double fps;
	public long duration;
	
	
	public double[] fpsHistory;
	public long[] durationHistory;
	
	public FPSCounter(int historySize) {
		this.fpsHistory = new double[historySize];
		this.durationHistory = new long[historySize];
	}
	
	private long getTime() {
		return System.currentTimeMillis();
	}
	
	public void tickStart() {
		frameStart = getTime();
	}
	
	public void tick() {
		time = getTime();
		thisFrameTime = time - lastLoop;
		frameTime += (thisFrameTime - frameTime) / smoothing;
		fps = frameTime == 0 ? 0 : (1000 / frameTime);
		duration = frameStart < lastLoop ? frameTime : time - frameStart;
		lastLoop = time;
	}
	
	public void historyTick() {
		for (int i = fpsHistory.length-1; i>=0; i--) {
			fpsHistory[i] = i == 0 ? fps : fpsHistory[i-1];
			durationHistory[i] = i == 0 ? duration : durationHistory[i-1];
		}
	}
	
}
