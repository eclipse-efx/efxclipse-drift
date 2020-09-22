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

public class SwapchainConfig {

	public final Vec2i size;
	public final int imageCount;
	public final PresentationMode presentationMode;
	public final TransferType transferType;
	
	
	public SwapchainConfig(Vec2i size, int imageCount, PresentationMode presentationMode, TransferType transferType) {
		this.size = size;
		this.imageCount = imageCount;
		this.presentationMode = check(presentationMode);
		this.transferType = check(transferType);
	}
	
	
	private static final PresentationMode check(PresentationMode presentationMode) {
		if (presentationMode == null) {
			presentationMode = PresentationMode.MAILBOX;
		}
		return presentationMode;
	}
	
	private static final TransferType check(TransferType transferType) {
		if (transferType == null) {
			transferType = StandardTransferTypes.MainMemory;
		}
		return transferType;
	}
}
