/*******************************************************************************
 * Copyright (c) 2019 BestSolution.at and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Christoph Caks <ccaks@bestsolution.at> - initial API and implementation
 *******************************************************************************/
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
