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
	public static class TransferMode {
		private String name;
		int id;

		protected TransferMode(String name, int id) {
			this.name = name;
			this.id = id;
		}

		@Override
		public String toString() {
			return name + " " + id;
		}

		public String getKey() {
			return name;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + id;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			TransferMode other = (TransferMode) obj;
			if (id != other.id)
				return false;
			return true;
		}
	}
	
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

	protected NGNode impl_createPeer() {
		throw new UnsupportedOperationException("The class should not have been loaded");
	}

	public BaseBounds impl_computeGeomBounds(BaseBounds bounds, BaseTransform tx) {
		throw new UnsupportedOperationException("The class should not have been loaded");
	}

	protected boolean impl_computeContains(double localX, double localY) {
		throw new UnsupportedOperationException("The class should not have been loaded");
	}

	public Object impl_processMXNode(MXNodeAlgorithm alg, MXNodeAlgorithmContext ctx) {
		throw new UnsupportedOperationException("The class should not have been loaded");
	}
	
		
}
