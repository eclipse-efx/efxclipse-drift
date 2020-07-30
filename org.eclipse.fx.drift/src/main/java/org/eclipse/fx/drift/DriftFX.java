package org.eclipse.fx.drift;

import org.eclipse.fx.drift.internal.DriftCPP;

public class DriftFX {
	
	private DriftFX() {}
	
	public static void useDriftCPP() {
		DriftCPP.require();
	}

}
