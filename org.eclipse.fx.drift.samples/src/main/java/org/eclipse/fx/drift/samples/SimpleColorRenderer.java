package org.eclipse.fx.drift.samples;

import org.eclipse.fx.drift.DriftFXSurface;

public class SimpleColorRenderer extends ARenderer {

	static {
		System.err.println("Loading samples " + System.getProperty("java.library.path"));
		System.loadLibrary("samples");
	}
	
	private DriftFXSurface surface;
	
	public SimpleColorRenderer(DriftFXSurface surface) {
		this.surface = surface;
	}
	
	public long getNativeSurfaceId() {
		return surface.getNativeSurfaceHandle();
	}
	
	private native void nRun(SimpleColorRenderer renderer);
	
	protected void run() {
		nRun(this);
	}
	
}
