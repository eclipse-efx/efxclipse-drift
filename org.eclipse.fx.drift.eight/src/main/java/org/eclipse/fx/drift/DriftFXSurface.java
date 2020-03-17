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
import org.eclipse.fx.drift.internal.SurfaceData;

import com.sun.javafx.geom.BaseBounds;
import com.sun.javafx.geom.transform.BaseTransform;
import com.sun.javafx.jmx.MXNodeAlgorithm;
import com.sun.javafx.jmx.MXNodeAlgorithmContext;
import com.sun.javafx.scene.DirtyBits;
import com.sun.javafx.sg.prism.NGNode;

import javafx.scene.Scene; 

//Note: this implementation is against internal JavafX API
@SuppressWarnings("restriction")
public class DriftFXSurface extends BaseDriftFXSurface {
	public DriftFXSurface() {
		init();
	}
	
	@Override
	protected void drift_updatePeer() {
		impl_updatePeer();
	}
	
	@Deprecated
	@Override
	public void impl_updatePeer() {
		super.impl_updatePeer();
		NGDriftFXSurface peer = impl_getPeer();
		
		if (impl_isDirty(DirtyBits.NODE_GEOMETRY)) {
			SurfaceData data = surfaceData.get();
			peer.updateSurface(data);
			peer.markDirty();
		}
		
		if (impl_isDirty(DirtyBits.NODE_CONTENTS)) {
			peer.markDirty();
		}
		
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
	public Object impl_processMXNode(MXNodeAlgorithm alg, MXNodeAlgorithmContext ctx) {
		throw new UnsupportedOperationException("Not supported yet.");
	}
	
	@Override
	protected NGNode impl_createPeer() {
		NGDriftFXSurface peer = new NGDriftFXSurface(this, nativeSurfaceId);
		return peer;
	}
	
	@Override
	protected NGNode drift_createPeer() {
		return impl_createPeer();
	}
	
	@Override
	protected void drift_markDirty(DirtyBits dirtyBit) {
		impl_markDirty(dirtyBit);
	}
	
	@Override
	protected NGDriftFXSurface drift_getPeer() {
		return impl_getPeer();
	}
	
	@Override
	protected void drift_beginPeerAccess() {
		Scene.impl_setAllowPGAccess(true);
	}
	
	@Override
	protected void drift_endPeerAccess() {
		Scene.impl_setAllowPGAccess(false);
	}
	
	@Override
	protected void drift_geomChanged() {
		impl_geomChanged();
	}
	
	@Override
	protected void drift_layoutBoundsChanged() {
		impl_layoutBoundsChanged();
	}
}
