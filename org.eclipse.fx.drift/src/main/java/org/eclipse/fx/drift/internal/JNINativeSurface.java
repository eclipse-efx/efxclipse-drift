/*
 * Copyright (c) 2018 BestSolution and Others. All rights reserved.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0, which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * This Source Code may also be made available under the following Secondary
 * Licenses when the conditions for such availability set forth in the
 * Eclipse Public License v. 2.0 are satisfied: GNU General Public License,
 * version 2 with the GNU Classpath Exception, which is available at
 * https://www.gnu.org/software/classpath/license.html.
 *
 * SPDX-License-Identifier: EPL-2.0 OR GPL-2.0 WITH Classpath-exception-2.0
 */
package org.eclipse.fx.drift.internal;

import java.util.function.Consumer;

public class JNINativeSurface {

	public static class FrameData {
		public long d3dShareHandle;
		public long ioSurfaceHandle;
		public int width;
		public int height;
		public int textureName;
		
		public FrameData() {
			
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + (int) (d3dShareHandle ^ (d3dShareHandle >>> 32));
			result = prime * result + height;
			result = prime * result + (int) (ioSurfaceHandle ^ (ioSurfaceHandle >>> 32));
			result = prime * result + textureName;
			result = prime * result + width;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			FrameData other = (FrameData) obj;
			if (d3dShareHandle != other.d3dShareHandle)
				return false;
			if (height != other.height)
				return false;
			if (ioSurfaceHandle != other.ioSurfaceHandle)
				return false;
			if (textureName != other.textureName)
				return false;
			if (width != other.width)
				return false;
			return true;
		}

		
		
	}
	
	private Consumer<FrameData> presentFrame;
	
	public JNINativeSurface(Consumer<FrameData> presentFrame) {
		this.presentFrame = presentFrame;
	}

	public void present(long handle, long ioSurfaceHandle, int textureName, int width, int height) {
		FrameData dat = new FrameData();
		dat.d3dShareHandle = handle;
		dat.ioSurfaceHandle = ioSurfaceHandle;
		dat.textureName = textureName;
		dat.width = width;
		dat.height = height;
		presentFrame.accept(dat);
	}
	
	public void present(FrameData frame) {
		presentFrame.accept(frame);
	}
	
}
