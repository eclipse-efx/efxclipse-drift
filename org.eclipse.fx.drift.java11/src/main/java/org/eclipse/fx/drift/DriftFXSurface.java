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

import com.sun.javafx.geom.BaseBounds;
import com.sun.javafx.geom.transform.BaseTransform;
import com.sun.javafx.scene.DirtyBits;
import com.sun.javafx.scene.NodeHelper;
import com.sun.javafx.scene.SceneHelper;
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
	protected InnerHelper getHelper() {
		return new InnerHelper() {
			@Override
			public NGDriftFXSurface getPeer() {
				return NodeHelper.getPeer(DriftFXSurface.this);
			}
			@Override
			public boolean isDirty(DirtyBits bit) {
				return NodeHelper.isDirty(DriftFXSurface.this, bit);
			}
			@Override
			public void markDirty(DirtyBits bit) {
				NodeHelper.markDirty(DriftFXSurface.this, bit);
			}
			@Override
			public void beginPeerAccess() {
				SceneHelper.setAllowPGAccess(true);
			}
			@Override
			public void endPeerAccess() {
				SceneHelper.setAllowPGAccess(false);
			}
			@Override
			public void geomChanged() {
				NodeHelper.geomChanged(DriftFXSurface.this);
			}
			@Override
			public void layoutBoundsChanged() {
				DriftHelper.layoutBoundsChanged(DriftFXSurface.this);
			}
		};
	}
	
}