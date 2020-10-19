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

import java.util.Optional;
import java.util.UUID;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.Future;

import org.eclipse.fx.drift.TransferType;
import org.eclipse.fx.drift.Vec2i;
import org.eclipse.fx.drift.internal.common.ImageData;

import com.sun.prism.ResourceFactory;

@SuppressWarnings("restriction")
public interface FrontSwapChain {
	
	Optional<FxImage<?>> getCurrentImage();
	
	
	Vec2i getSize();
	TransferType getTransferType();
	
	void present(ImageData image);
	
	CompletableFuture<Void> allocate();
	CompletableFuture<Void> dispose();
	
	UUID getId();
	
	boolean isDisposed();
}
