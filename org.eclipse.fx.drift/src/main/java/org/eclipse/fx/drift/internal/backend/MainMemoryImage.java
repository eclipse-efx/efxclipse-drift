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

import static org.eclipse.fx.drift.internal.GL.GL_BGRA;
import static org.eclipse.fx.drift.internal.GL.GL_PIXEL_PACK_BUFFER;
import static org.eclipse.fx.drift.internal.GL.GL_READ_ONLY;
import static org.eclipse.fx.drift.internal.GL.GL_RGBA;
import static org.eclipse.fx.drift.internal.GL.GL_STATIC_READ;
import static org.eclipse.fx.drift.internal.GL.GL_TEXTURE_2D;
import static org.eclipse.fx.drift.internal.GL.GL_UNSIGNED_BYTE;
import static org.eclipse.fx.drift.internal.GL.GL_UNSIGNED_INT_8_8_8_8_REV;
import static org.eclipse.fx.drift.internal.GL.glBindBuffer;
import static org.eclipse.fx.drift.internal.GL.glBindTexture;
import static org.eclipse.fx.drift.internal.GL.glBufferData;
import static org.eclipse.fx.drift.internal.GL.glDeleteBuffer;
import static org.eclipse.fx.drift.internal.GL.glDeleteTexture;
import static org.eclipse.fx.drift.internal.GL.glGenBuffer;
import static org.eclipse.fx.drift.internal.GL.glGenTexture;
import static org.eclipse.fx.drift.internal.GL.glGetTexImage;
import static org.eclipse.fx.drift.internal.GL.glMapBuffer;
import static org.eclipse.fx.drift.internal.GL.glTexImage2D;
import static org.eclipse.fx.drift.internal.GL.glUnmapBuffer;
import static org.eclipse.fx.drift.internal.SYS.free;
import static org.eclipse.fx.drift.internal.SYS.malloc;
import static org.eclipse.fx.drift.internal.SYS.memcpy;

import org.eclipse.fx.drift.Vec2i;
import org.eclipse.fx.drift.internal.DriftFX;
import org.eclipse.fx.drift.internal.DriftLogger;
import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.common.MainMemoryImageData;
import org.eclipse.fx.drift.internal.prism.Prism;

public class MainMemoryImage implements Image {
	private static final DriftLogger LOGGER = DriftFX.createLogger(MainMemoryImage.class);
	
	public static final ImageType TYPE = new ImageType("MainMemory");
	
	private int number;
	private Vec2i size;
	
	private MainMemoryImageData data;
	
	int glTexture;
	long memPointer;
	int memSize;
	
	public MainMemoryImage(int number, Vec2i size) {
		this.number = number;
		this.size = size;
	}
	
	@Override
	public ImageData getData() {
		return data;
	}

	
	@Override
	public void allocate() {
		glTexture = glGenTexture();
		glBindTexture(GL_TEXTURE_2D, glTexture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, size.x, size.y, 0, GL_BGRA, GL_UNSIGNED_BYTE, 0);
		glBindTexture(GL_TEXTURE_2D, 0);
		
		memSize = size.x * size.y * 4;
		memPointer = malloc(memSize);
		
		LOGGER.debug(() -> "*allocated " + number + " 0x" + Long.toHexString(memPointer) + "("+size.x+"x"+size.y+": " + memSize + "B)");
		this.data =  new MainMemoryImageData(number, size, memPointer, memSize);
	}

	@Override
	public void release() {
		glDeleteTexture(glTexture);
		LOGGER.debug(() -> "*release " + glTexture + " 0x" + Long.toHexString(memPointer));
		free(memPointer);
	}

	@Override
	public void onAcquire() {

	}

	@Override
	public void onPresent() {
		synchronized (data) {
			downloadToMemorySimple(glTexture, memPointer);
		}
	}

	private void downloadToMemorySimple(int tex, long pPixels) {
		
//		int format = GL_RGBA; // TODO need GL_BGRA on windows
//		int format = GL_BGRA;
		
		// we change the colors here for directx upload
		int format = Prism.isD3D() ? GL_BGRA : GL_RGBA;
		
		glBindTexture(GL_TEXTURE_2D, glTexture);
		glGetTexImage(GL_TEXTURE_2D, 0, format, GL_UNSIGNED_INT_8_8_8_8_REV, memPointer);
		glBindTexture(GL_TEXTURE_2D, 0);
		LOGGER.trace(() -> "*downloaded " + tex + " => 0x" + Long.toHexString(memPointer));
	}
	
	private void downloadToMemoryBuf(int tex, int size, long pPixels) {
		int buf = glGenBuffer();
		glBindBuffer(GL_PIXEL_PACK_BUFFER, buf);
		glBufferData(GL_PIXEL_PACK_BUFFER, size, 0, GL_STATIC_READ);
		int format = GL_RGBA; // TODO need GL_BGRA on windows
		glBindTexture(GL_TEXTURE_2D, tex);
		glGetTexImage(GL_TEXTURE_2D, 0, format, GL_UNSIGNED_INT_8_8_8_8_REV, 0);
		glBindTexture(GL_TEXTURE_2D, 0);
		
		long glBuf = glMapBuffer(GL_PIXEL_PACK_BUFFER, GL_READ_ONLY);
		memcpy(pPixels, glBuf, size);
		glUnmapBuffer(GL_PIXEL_PACK_BUFFER);
		glBindBuffer(GL_PIXEL_PACK_BUFFER, 0);
		glDeleteBuffer(buf);
	}
	
	@Override
	public int getGLTexture() {
		return glTexture;
	}
}
