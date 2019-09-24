package org.eclipse.fx.drift.internal.backend;

import static org.eclipse.fx.drift.internal.GL.*;
import static org.eclipse.fx.drift.internal.SYS.*;

import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.common.MainMemoryImageData;
import org.eclipse.fx.drift.internal.math.Vec2i;

public class MainMemoryImage implements Image {

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
		
		System.err.println("*allocated " + number + " " + memPointer);
		
		this.data =  new MainMemoryImageData(number, size, memPointer, memSize);
	}

	@Override
	public void release() {
		glDeleteTexture(glTexture);
		free(memPointer);
	}

	@Override
	public void beforeRender() {
		downloadToMemorySimple(glTexture, memPointer);
	}

	@Override
	public void afterRender() {
		
	}

	private void downloadToMemorySimple(int tex, long pPixels) {
		int format = GL_RGBA; // TODO need GL_BGRA on windows
		glBindTexture(GL_TEXTURE_2D, glTexture);
		glGetTexImage(GL_TEXTURE_2D, 0, format, GL_UNSIGNED_INT_8_8_8_8_REV, memPointer);
		glBindTexture(GL_TEXTURE_2D, 0);
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
