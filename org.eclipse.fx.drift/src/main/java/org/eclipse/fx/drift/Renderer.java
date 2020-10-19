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

/**
 * The API for rendering to a driftfx surface.
 * <p>To acquire an instance use the rendering api dependent factory. For OpenGL use {@link GLRenderer#getRenderer(DriftFXSurface)}.</p>
 *
 */
public interface Renderer {
	
	/**
	 * creates a new Swapchain.
	 * <p>must be called from the rendering thread with a current OpenGL context</p>
	 * @return a new swapchain
	 */
	Swapchain createSwapchain(SwapchainConfig config);
	
	/**
	 * returns the current size of the associated driftfx surface.
	 * <p>this is the premultiplied size for the texture (logical size * screen scale * user scale)</p>
	 * @return the size
	 */
	Vec2i getSize();
	
	
	/**
	 * the current logical size of the associated driftfx surface.
	 * @return the logical size
	 */
	Vec2d getLogicalSize();
	
	/**
	 * the current screen scale of the associated driftfx surface as reported by javafx.
	 * @return the screen scale.
	 */
	Vec2d getScreenScale();
	
	/**
	 * the current user scale of the associated driftfx surface.
	 * @return the user scale
	 */
	Vec2d getUserScale();
	
}
