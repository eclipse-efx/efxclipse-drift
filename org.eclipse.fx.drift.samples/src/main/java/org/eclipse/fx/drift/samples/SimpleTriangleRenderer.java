
package org.eclipse.fx.drift.samples;

import org.eclipse.fx.drift.DriftFXSurface;

public class SimpleTriangleRenderer extends ARenderer {

	static {
		System.loadLibrary("samples");
	}
	
	private DriftFXSurface surface;
	
	
	
	public SimpleTriangleRenderer(DriftFXSurface surface) {
		this.surface = surface;
	}
	
	public long getNativeSurfaceId() {
		return surface.getNativeSurfaceHandle();
	}
	
	private native void nRun(SimpleTriangleRenderer renderer);
	
	protected void run() {
		nRun(this);
	}
	
}
