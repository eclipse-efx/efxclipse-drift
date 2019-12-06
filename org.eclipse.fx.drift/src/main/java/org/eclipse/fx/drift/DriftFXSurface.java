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
package org.eclipse.fx.drift;

import org.eclipse.fx.drift.impl.NGDriftFXSurface;

import com.sun.javafx.geom.BaseBounds;
import com.sun.javafx.geom.transform.BaseTransform;
import com.sun.javafx.jmx.MXNodeAlgorithm;
import com.sun.javafx.jmx.MXNodeAlgorithmContext;
import com.sun.javafx.scene.DirtyBits;
import com.sun.javafx.sg.prism.NGNode;

//Note: this implementation is against internal JavafX API
@SuppressWarnings("restriction")
public class DriftFXSurface extends BaseDriftFXSurface {

	@Override
	public void drift_updatePeer() {
		throw new UnsupportedOperationException("The class should not have been loaded");
	}

	@Override
	protected NGNode drift_createPeer() {
		throw new UnsupportedOperationException("The class should not have been loaded");
	}

	@Override
	protected void drift_markDirty(DirtyBits dirtyBit) {
		throw new UnsupportedOperationException("The class should not have been loaded");
	}

	@Override
	public NGDriftFXSurface drift_getPeer() {
		throw new UnsupportedOperationException("The class should not have been loaded");
	}

	@Override
	protected void drift_geomChanged() {
		throw new UnsupportedOperationException("The class should not have been loaded");
	}

	@Override
	protected void drift_layoutBoundsChanged() {
		throw new UnsupportedOperationException("The class should not have been loaded");
	}

	@Override
	protected NGNode impl_createPeer() {
		throw new UnsupportedOperationException("The class should not have been loaded");
	}

	@Override
	public BaseBounds impl_computeGeomBounds(BaseBounds bounds, BaseTransform tx) {
		throw new UnsupportedOperationException("The class should not have been loaded");
	}

	@Override
	protected boolean impl_computeContains(double localX, double localY) {
		throw new UnsupportedOperationException("The class should not have been loaded");
	}

	@Override
	public Object impl_processMXNode(MXNodeAlgorithm alg, MXNodeAlgorithmContext ctx) {
		throw new UnsupportedOperationException("The class should not have been loaded");
	}
	
		
}
