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
import org.eclipse.fx.drift.internal.DriftHelper;
import org.eclipse.fx.drift.internal.DriftHelper.DriftFXSurfaceAccessor;
import org.eclipse.fx.drift.internal.SurfaceData;

import com.sun.javafx.geom.BaseBounds;
import com.sun.javafx.geom.transform.BaseTransform;
import com.sun.javafx.scene.DirtyBits;
import com.sun.javafx.scene.NodeHelper;
import com.sun.javafx.sg.prism.NGNode;

import javafx.scene.Node;

//Note: this implementation is against internal JavafX API
public class DriftFXSurface extends BaseDriftFXSurface {
	static {
		DriftHelper.setDriftFXSurfaceAccessor(new DriftFXSurfaceAccessor() {
			private BaseDriftFXSurface cast(Node node) {
				return (BaseDriftFXSurface) node;
			}

			@Override
			public void doUpdatePeer(Node node) {
				cast(node).drift_updatePeer();
			}

			@Override
			public NGNode doCreatePeer(Node node) {
				return cast(node).drift_createPeer();
			}

			@Override
			public BaseBounds doComputeGeomBounds(Node node, BaseBounds bounds, BaseTransform tx) {
				return cast(node).drift_computeGeomBounds(bounds, tx);
			}

			@Override
			public boolean doComputeContains(Node node, double localX, double localY) {
				return cast(node).drift_computeContains(localX, localY);
			}
		});
	}
	
	{
		// To initialize the class helper at the begining each constructor of this class
		DriftHelper.initHelper(this);
	}
	
	public DriftFXSurface() {
		init();
	}

	@Override
	protected void drift_updatePeer() {
		NGDriftFXSurface peer = drift_getPeer();

		if ( NodeHelper.isDirty(this,DirtyBits.NODE_GEOMETRY)) {
			SurfaceData data = surfaceData.get();
			peer.updateSurface(data);
			peer.markDirty();
		}

		if ( NodeHelper.isDirty(this,DirtyBits.NODE_CONTENTS)) {
			peer.markDirty();
		}
	}
	
	@Override
	protected NGNode drift_createPeer() {
		return new NGDriftFXSurface(this, nativeSurfaceId);
	}

	@Override
	protected void drift_markDirty(DirtyBits dirtyBit) {
		NodeHelper.getNodeAccessor().doMarkDirty(this, dirtyBit);
	}

	@Override
	protected NGDriftFXSurface drift_getPeer() {
		return NodeHelper.getPeer(this);
	}

	@Override
	protected void drift_geomChanged() {
		NodeHelper.getNodeAccessor().doGeomChanged(this);
	}

	@Override
	protected void drift_layoutBoundsChanged() {
		NodeHelper.getNodeAccessor().layoutBoundsChanged(this);
	}
	
		
	
}
