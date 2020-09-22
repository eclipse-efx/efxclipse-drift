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
package org.eclipse.fx.drift.internal.transport.command;

import java.util.List;
import java.util.UUID;

import org.eclipse.fx.drift.PresentationMode;
import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.transport.Command;

public class CreateSwapchainCommand implements Command {
	public final static String NAME = "CreateSwapchain";
	private UUID id;
	private List<ImageData> images;
	private PresentationMode presentationMode;
	
	public CreateSwapchainCommand(UUID id, List<ImageData> images, PresentationMode presentationMode) {
		this.id = id;
		this.images = images;
		this.presentationMode = presentationMode;
	}
	
	public UUID getId() {
		return id;
	}
	
	public List<ImageData> getImages() {
		return images;
	}
	
	public PresentationMode getPresentatioMode() {
		return presentationMode;
	}
	
	@Override
	public String getName() {
		return NAME;
	}
	
	@Override
	public String toString() {
		return NAME + " " + id + " " + images + ", " + presentationMode;
	}
}
