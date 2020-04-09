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

import org.eclipse.fx.drift.impl.DriftDebug;
import org.eclipse.fx.drift.impl.NGDriftFXSurface;
import org.eclipse.fx.drift.internal.SurfaceData;

import com.sun.javafx.geom.BaseBounds;
import com.sun.javafx.geom.transform.BaseTransform;
import com.sun.javafx.jmx.MXNodeAlgorithm;
import com.sun.javafx.jmx.MXNodeAlgorithmContext;
import com.sun.javafx.scene.DirtyBits;
import com.sun.javafx.sg.prism.NGNode;

import javafx.geometry.Bounds;
import javafx.scene.Scene; 

//Note: this implementation is against internal JavafX API
@SuppressWarnings("restriction")
public class DriftFXSurface extends BaseDriftFXSurface {
	
	public DriftFXSurface() {
		init();
	}
	
	@SuppressWarnings("deprecation")
	protected InnerHelper getHelper() {
		return new InnerHelper() {
			@Override
			public NGDriftFXSurface getPeer() {
				return impl_getPeer();
			}
			@Override
			public boolean isDirty(DirtyBits bit) {
				return impl_isDirty(bit);
			}
			@Override
			public void markDirty(DirtyBits bit) {
				impl_markDirty(bit);
			}
			@Override
			public void beginPeerAccess() {
				Scene.impl_setAllowPGAccess(true);
			}
			@Override
			public void endPeerAccess() {
				Scene.impl_setAllowPGAccess(false);
			}
			@Override
			public void geomChanged() {
				impl_geomChanged();
			}
			@Override
			public void layoutBoundsChanged() {
				impl_layoutBoundsChanged();
			}
		};
	}
	
	@Override
	public void impl_updatePeer() {
		super.impl_updatePeer();
		drift_updatePeer();
	}
	
	@Override
	public BaseBounds impl_computeGeomBounds(BaseBounds bounds, BaseTransform tx) {
		return drift_computeGeomBounds(bounds, tx);
	}
	
	
	@Override
	protected boolean impl_computeContains(double localX, double localY) {
		return drift_computeContains(localX, localY);
	}
	
	@Override
	protected NGNode impl_createPeer() {
		return drift_createPeer();
	}
	
	@Override
	public Object impl_processMXNode(MXNodeAlgorithm alg, MXNodeAlgorithmContext ctx) {
		throw new UnsupportedOperationException("Not supported yet.");
	}
	

}