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
package org.eclipse.fx.drift.internal.backend;

import org.eclipse.fx.drift.RenderTarget;
import org.eclipse.fx.drift.internal.common.ImageData;

public interface Image extends RenderTarget, GLRenderTarget {

	public static class ImageType {
		public final String id;
		public ImageType(String id) {
			this.id = id;
		}
		@Override
		public String toString() {
			return id;
		}
	}
	
	ImageData getData();
	
	void allocate();
	void release();
	/** called on acquire before the image is returned to the renderer */
	void onAcquire();
	/** called right before the image is presented to the frontend */
	void onPresent();
	
	
	
	int getGLTexture();
	
}

