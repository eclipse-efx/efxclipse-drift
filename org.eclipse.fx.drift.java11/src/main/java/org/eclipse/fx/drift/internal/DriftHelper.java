/* ******************************************************************************
 * Copyright (c) 2019, 2020 BestSolution.at and others.
 * All rights reserved. This program and the accompanying materials 
 * are made available under the terms of the Eclipse Public License 2.0 
 * which is available at http://www.eclipse.org/legal/epl-2.0
 *
 * SPDX-License-Identifier: EPL-2.0
 * 
 * Contributors:
 *     Christoph Caks <ccaks@bestsolution.at> - initial API and implementation
 * ******************************************************************************/
package org.eclipse.fx.drift.internal;

import org.eclipse.fx.drift.DriftFXSurface;

import com.sun.javafx.geom.BaseBounds;
import com.sun.javafx.geom.transform.BaseTransform;
import com.sun.javafx.scene.NodeHelper;
import com.sun.javafx.sg.prism.NGNode;
import com.sun.javafx.util.Utils;

import javafx.scene.Node;

public class DriftHelper extends NodeHelper {
	private static final DriftHelper INSTANCE;
    private static DriftFXSurfaceAccessor driftFXSurfaceAccessor;

    static {
        INSTANCE = new DriftHelper();
        Utils.forceInit(DriftFXSurface.class);
    }

    private static DriftHelper getInstance() {
        return INSTANCE;
    }

    public static void initHelper(DriftFXSurface driftFXSurface) {
        setHelper(driftFXSurface, getInstance());
    }

	@Override
	protected NGNode createPeerImpl(Node node) {
		return driftFXSurfaceAccessor.doCreatePeer(node);
	}

	@Override
	protected void updatePeerImpl(Node node) {
		super.updatePeerImpl(node);
		driftFXSurfaceAccessor.doUpdatePeer(node);
	}

	@Override
	protected boolean computeContainsImpl(Node node, double localX, double localY) {
		return driftFXSurfaceAccessor.doComputeContains(node, localX, localY);
	}

	@Override
	protected BaseBounds computeGeomBoundsImpl(Node node, BaseBounds bounds, BaseTransform tx) {
		return driftFXSurfaceAccessor.doComputeGeomBounds(node, bounds, tx);
	}

	public static void setDriftFXSurfaceAccessor(final DriftFXSurfaceAccessor newAccessor) {
        if (driftFXSurfaceAccessor != null) {
            throw new IllegalStateException();
        }

        driftFXSurfaceAccessor = newAccessor;
    }

	public interface DriftFXSurfaceAccessor {
        NGNode doCreatePeer(Node node);
        BaseBounds doComputeGeomBounds(Node node, BaseBounds bounds, BaseTransform tx);
        boolean doComputeContains(Node node, double localX, double localY);
        void doUpdatePeer(Node node);
    }
}