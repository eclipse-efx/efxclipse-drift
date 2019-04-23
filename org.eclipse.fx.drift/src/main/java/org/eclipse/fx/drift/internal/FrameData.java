/*
 * Copyright (c) 2019 BestSolution.at and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Christoph Caks <ccaks@bestsolution.at> - initial API and implementation
 */
package org.eclipse.fx.drift.internal;

public class FrameData {
	public long frameId;
	
	public SurfaceData surfaceData;	
	
	public long d3dShareHandle;
	public long ioSurfaceHandle;
	public int width;
	public int height;
	public int textureName;
	
	public int placementHint;
	
	public FrameData() {
	}
	

	public FrameData(long frameId, int width, int height, SurfaceData surfaceData, long d3dShareHandle, long ioSurfaceHandle, int textureName, int placementHint) {
		this.frameId = frameId;
		this.width = width;
		this.height = height;
		this.surfaceData = surfaceData;
		this.d3dShareHandle = d3dShareHandle;
		this.ioSurfaceHandle = ioSurfaceHandle;
		this.textureName = textureName;
		this.placementHint = placementHint;
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

	@Override
	public String toString() {
		return String.format("FrameData[%d: %d x %d] (%d,%d,%d) %s", frameId, width, height, d3dShareHandle, ioSurfaceHandle, textureName, surfaceData);
	}
	
}