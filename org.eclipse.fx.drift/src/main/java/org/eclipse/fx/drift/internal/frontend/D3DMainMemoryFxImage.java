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

import org.eclipse.fx.drift.internal.D3DBatch;
import org.eclipse.fx.drift.internal.common.MainMemoryImageData;

public class D3DMainMemoryFxImage extends AMainMemoryFxImage {

	public D3DMainMemoryFxImage(MainMemoryImageData data) {
		super(data);
	}
	
	@Override
	protected void uploadTexture() {
		D3DBatch.uploadTexture(getTexture(), data.memPointer, data.size.x, data.size.y, data.memSize);
	}

}
