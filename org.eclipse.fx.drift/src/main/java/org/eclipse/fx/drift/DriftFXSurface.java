package org.eclipse.fx.drift;

import org.eclipse.fx.drift.internal.prism.Prism;

import com.sun.javafx.geom.BaseBounds;
import com.sun.javafx.geom.transform.BaseTransform;
import com.sun.javafx.jmx.MXNodeAlgorithm;
import com.sun.javafx.jmx.MXNodeAlgorithmContext;
import com.sun.javafx.sg.prism.NGNode;

public class DriftFXSurface extends BaseDriftFXSurface {
	
	@Override
	protected InnerHelper getHelper() {
		throw new UnsupportedOperationException();
	}

	@Override
	protected NGNode drift_createPeer() {
		throw new UnsupportedOperationException();
	}

	@Override
	protected boolean impl_computeContains(double arg0, double arg1) {
		throw new UnsupportedOperationException();
	}

	@Override
	public BaseBounds impl_computeGeomBounds(BaseBounds arg0, BaseTransform arg1) {
		throw new UnsupportedOperationException();
	}

	@Override
	protected NGNode impl_createPeer() {
		throw new UnsupportedOperationException();
	}

	@Override
	public Object impl_processMXNode(MXNodeAlgorithm arg0, MXNodeAlgorithmContext arg1) {
		throw new UnsupportedOperationException();
	}
	


}
