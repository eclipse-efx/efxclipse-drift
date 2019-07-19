/*******************************************************************************
 * Copyright (c) 2019 BestSolution.at and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Christoph Caks <ccaks@bestsolution.at> - initial API and implementation
 *******************************************************************************/
package org.eclipse.fx.drift.internal;

import java.util.function.Consumer;

public class JNINativeSurface {

	private Consumer<FrameData> presentFrame;
	private Consumer<Frame> presentFrame2;
	
	public JNINativeSurface(Consumer<FrameData> presentFrame, Consumer<Frame> presentFrame2) {
		this.presentFrame = presentFrame;
		this.presentFrame2 = presentFrame2;
	}
	
	public void present(FrameData frame) {
		//System.err.println("Present call " + frame);
		presentFrame.accept(frame);
	}
	
	public void present(Frame frame) {
		presentFrame2.accept(frame);
	}
	
}
