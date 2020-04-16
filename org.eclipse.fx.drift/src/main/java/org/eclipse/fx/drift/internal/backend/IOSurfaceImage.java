package org.eclipse.fx.drift.internal.backend;

import static org.eclipse.fx.drift.internal.GL.glDeleteTexture;
import static org.eclipse.fx.drift.internal.GL.*;
import static org.eclipse.fx.drift.internal.jni.macos.MacOS.*;

import org.eclipse.fx.drift.Vec2i;
import org.eclipse.fx.drift.internal.GL;
import org.eclipse.fx.drift.internal.ResourceLogger;
import org.eclipse.fx.drift.internal.common.IOSurfaceImageData;
import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.common.NVDXInteropImageData;
import org.eclipse.fx.drift.internal.frontend.IOSurfaceFxImage;
import org.eclipse.fx.drift.internal.jni.macos.MacOS;
import org.eclipse.fx.drift.internal.jni.win32.D3D9;
import org.eclipse.fx.drift.internal.jni.win32.NVDXInterop;
import org.eclipse.fx.drift.internal.jni.win32.Win32;
import org.eclipse.fx.drift.internal.jni.win32.WindowsError;

public class IOSurfaceImage implements Image {

	public static final ImageType TYPE = new ImageType("IOSurface");
	
	
	private int number;
	private Vec2i size;
	
	private IOSurfaceImageData data;
	
	int glTexture;
	
	private MacOS.IOSurfaceRef ioSurface;
	private long ioSurfaceID;
	
	public IOSurfaceImage(int number, Vec2i size) {
		this.number = number;
		this.size = size;
	}
	
	@Override
	public ImageData getData() {
		return data;
	}
	
	@Override
	public int getGLTexture() {
		return glTexture;
	}
	
	@Override
	public void allocate() {
		ioSurface = MacOS.createIOSurface(size.x, size.y);
		glTexture = glGenTexture();
		ioSurfaceID = IOSurfaceGetID(ioSurface);
		glBindTexture(GL_TEXTURE_RECTANGLE, glTexture);
		CGLContextObj cglContext = MacOS.CGLGetCurrentContext();
		CGLError success = CGLTexImageIOSurface2D(cglContext, GL_TEXTURE_RECTANGLE, GL_RGBA, size.x, size.y, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, ioSurface, 0);
		if (success != CGLError.kCGLNoError) {
			throw new RuntimeException("CGLError " + success);
		}
		glBindTexture(GL_TEXTURE_RECTANGLE, 0);

		
		this.data = new IOSurfaceImageData(number, size, ioSurfaceID);
	}
	
	@Override
	public void release() {
		MacOS.CFRelease(ioSurface);
		glDeleteTexture(glTexture);
	}
	
	@Override
	public void onAcquire() {
		
	}
	
	@Override
	public void onPresent() {
		// this somehow ensures that the io surface is really written to
		// without it we get empty textures on the fx side on some systems
//		glBindFramebuffer(GL_FRAMEBUFFER, 0);
//		glBindTexture(GL_TEXTURE_RECTANGLE, 0);
		glFlush();
		
//		System.err.println("Dump iosurface on present");
//		IOSurfaceFxImage.dumpIOSurface(data.ioSurfaceID, data.size);
	}
	
	@Override
	public String toString() {
		return TYPE+"Image("+number+")";
	}
}
