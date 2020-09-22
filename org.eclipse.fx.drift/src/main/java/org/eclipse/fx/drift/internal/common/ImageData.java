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
package org.eclipse.fx.drift.internal.common;

import org.eclipse.fx.drift.TransferType;
import org.eclipse.fx.drift.Vec2i;

public class ImageData {

	public final int number;
	public final Vec2i size;
	public final TransferType type;
	
	public ImageData(int number, TransferType type, Vec2i size) {
		this.number = number;
		this.type = type;
		this.size = size;
	}
}
