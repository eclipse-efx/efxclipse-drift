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
package org.eclipse.fx.drift.internal.transfer.gles;

import org.eclipse.fx.drift.internal.transfer.ShareData;
import org.eclipse.fx.drift.internal.transfer.SharedTexture;
import org.eclipse.fx.drift.internal.transfer.TransferMode;

import com.sun.prism.Texture;

@SuppressWarnings("restriction")
public class GLESMainMemoryTransferMode implements TransferMode {

	@Override
	public String getName() {
		return "MainMemory";
	}

	@Override
	public SharedTexture createSharedTexture() {
		
		return null;
	}

	@Override
	public ShareData createShareData(SharedTexture tx) {
		
		return null;
	}

	@Override
	public void connectTexture(Texture texture, ShareData shareData) {
		
	}

}
