package org.eclipse.fx.drift.internal;

public class FPSCounter2 {
	
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
	
	public FPSCounter2(int historySize) {
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
		fps = 1000 / frameTime;
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
