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
package org.eclipse.fx.drift.internal.frontend;

import org.eclipse.fx.drift.internal.common.ImageData;

import com.sun.prism.ResourceFactory;
import com.sun.prism.Texture;

@SuppressWarnings("restriction")
public interface FxImage<D extends ImageData> {
	
	D getData();

	void allocate(ResourceFactory rf) throws Exception;
	void release();
	
	/** is called by the quantum renderer before the texture is rendered */
	void update();

	Texture getTexture();
	
}
