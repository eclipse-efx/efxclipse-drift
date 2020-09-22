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
package org.eclipse.fx.drift;

import com.sun.javafx.geom.BaseBounds;
import com.sun.javafx.geom.transform.BaseTransform;
import com.sun.javafx.jmx.MXNodeAlgorithm;
import com.sun.javafx.jmx.MXNodeAlgorithmContext;
import com.sun.javafx.sg.prism.NGNode;

@SuppressWarnings("restriction")
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
