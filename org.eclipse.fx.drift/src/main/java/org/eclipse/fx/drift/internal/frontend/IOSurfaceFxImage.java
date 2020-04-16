package org.eclipse.fx.drift.internal.frontend;

import static org.eclipse.fx.drift.internal.GL.GL_BGRA;
import static org.eclipse.fx.drift.internal.GL.GL_COLOR_ATTACHMENT0;
import static org.eclipse.fx.drift.internal.GL.GL_COLOR_BUFFER_BIT;
import static org.eclipse.fx.drift.internal.GL.GL_DRAW_FRAMEBUFFER;
import static org.eclipse.fx.drift.internal.GL.GL_LINEAR;
import static org.eclipse.fx.drift.internal.GL.GL_PIXEL_PACK_BUFFER;
import static org.eclipse.fx.drift.internal.GL.GL_READ_FRAMEBUFFER;
import static org.eclipse.fx.drift.internal.GL.GL_READ_ONLY;
import static org.eclipse.fx.drift.internal.GL.GL_RGBA;
import static org.eclipse.fx.drift.internal.GL.GL_STATIC_READ;
import static org.eclipse.fx.drift.internal.GL.GL_TEXTURE_2D;
import static org.eclipse.fx.drift.internal.GL.GL_TEXTURE_RECTANGLE;
import static org.eclipse.fx.drift.internal.GL.GL_UNSIGNED_INT_8_8_8_8_REV;
import static org.eclipse.fx.drift.internal.GL.glBindBuffer;
import static org.eclipse.fx.drift.internal.GL.glBindFramebuffer;
import static org.eclipse.fx.drift.internal.GL.glBindTexture;
import static org.eclipse.fx.drift.internal.GL.glBlitFramebuffer;
import static org.eclipse.fx.drift.internal.GL.glBufferData;
import static org.eclipse.fx.drift.internal.GL.glClear;
import static org.eclipse.fx.drift.internal.GL.glClearColor;
import static org.eclipse.fx.drift.internal.GL.glDeleteBuffer;
import static org.eclipse.fx.drift.internal.GL.glDeleteFramebuffer;
import static org.eclipse.fx.drift.internal.GL.glDeleteTexture;
import static org.eclipse.fx.drift.internal.GL.glFinish;
import static org.eclipse.fx.drift.internal.GL.glFramebufferTexture;
import static org.eclipse.fx.drift.internal.GL.glGenBuffer;
import static org.eclipse.fx.drift.internal.GL.glGenFramebuffer;
import static org.eclipse.fx.drift.internal.GL.glGenTexture;
import static org.eclipse.fx.drift.internal.GL.glGetTexImage;
import static org.eclipse.fx.drift.internal.GL.glMapBuffer;
import static org.eclipse.fx.drift.internal.GL.glUnmapBuffer;
import static org.eclipse.fx.drift.internal.SYS.malloc;
import static org.eclipse.fx.drift.internal.SYS.memcpy;
import static org.eclipse.fx.drift.internal.jni.macos.MacOS.CFRelease;
import static org.eclipse.fx.drift.internal.jni.macos.MacOS.CGLGetCurrentContext;
import static org.eclipse.fx.drift.internal.jni.macos.MacOS.CGLTexImageIOSurface2D;
import static org.eclipse.fx.drift.internal.jni.macos.MacOS.IOSurfaceLookup;

import java.nio.ByteBuffer;

import org.eclipse.fx.drift.Vec2i;
import org.eclipse.fx.drift.internal.GL;
import org.eclipse.fx.drift.internal.QuantumHelper;
import org.eclipse.fx.drift.internal.SYS;
import org.eclipse.fx.drift.internal.common.IOSurfaceImageData;
import org.eclipse.fx.drift.internal.jni.MemoryStack;
import org.eclipse.fx.drift.internal.jni.macos.MacOS;
import org.eclipse.fx.drift.internal.jni.macos.MacOS.CGLContextObj;
import org.eclipse.fx.drift.internal.jni.macos.MacOS.CGLError;
import org.eclipse.fx.drift.internal.jni.macos.MacOS.IOSurfaceRef;
import org.eclipse.fx.drift.internal.prism.Prism;
import org.eclipse.fx.drift.internal.prism.PrismES2;

import com.sun.prism.ResourceFactory;

@SuppressWarnings("restriction")
public class IOSurfaceFxImage extends AFxImage<IOSurfaceImageData> {
	
	private ResourceFactory rf;
	
	IOSurfaceRef ioSurface;
	int ioSurfaceTexture;

	private int readFbo;

	private int drawFbo;
	
	
	
	public IOSurfaceFxImage(IOSurfaceImageData data) {
		super(data);
	}
	
	@Override
	public void allocate(ResourceFactory rf) throws Exception {
		this.rf = rf;
		super.allocate(rf);
		// connect to the io surface
		QuantumHelper.syncExecute(rf, () -> {
			ioSurface = IOSurfaceLookup(data.ioSurfaceID);
			ioSurfaceTexture = GL.glGenTexture();
			
			glBindTexture(GL_TEXTURE_RECTANGLE, ioSurfaceTexture);
			CGLContextObj cglContext = CGLGetCurrentContext();
			CGLError error = CGLTexImageIOSurface2D(cglContext, GL_TEXTURE_RECTANGLE, GL_RGBA, data.size.x, data.size.y, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, ioSurface, 0);
			if (error != CGLError.kCGLNoError) {
				throw new RuntimeException("Could not connect to IOSurface " + data.ioSurfaceID);
			}
			glBindTexture(GL_TEXTURE_RECTANGLE, 0);
			
			readFbo = glGenFramebuffer();
			drawFbo = glGenFramebuffer();
			
			glBindFramebuffer(GL_READ_FRAMEBUFFER, readFbo);
			glFramebufferTexture(GL_READ_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, ioSurfaceTexture, 0);
			glBindFramebuffer(GL_READ_FRAMEBUFFER, 0);
			
			glBindFramebuffer(GL_DRAW_FRAMEBUFFER, drawFbo);
			glFramebufferTexture(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, PrismES2.getTextureName(getTexture()), 0);
			glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
			
		});
	}
	
	@Override
	public void release() {
		super.release();
		QuantumHelper.syncExecute(rf, () -> {
			glDeleteTexture(ioSurfaceTexture);
			CFRelease(ioSurface);
			
			glDeleteFramebuffer(readFbo);
			glDeleteFramebuffer(drawFbo);
		});
	}

	private void blitFramebuffer() {
		glBindFramebuffer(GL_READ_FRAMEBUFFER, readFbo);
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, drawFbo);
		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		glBlitFramebuffer(0, 0, data.size.x, data.size.y, 0, 0, data.size.x, data.size.y, GL_COLOR_BUFFER_BIT, GL_LINEAR);
		glBindFramebuffer(GL_READ_FRAMEBUFFER, 0);
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
	}
	
	private void copyTextureFramebuffer(int sourceTex, int targetTex, Vec2i size) {
		int sourceFbo = glGenFramebuffer();
		int targetFbo = glGenFramebuffer();
				

		glBindFramebuffer(GL_READ_FRAMEBUFFER, sourceFbo);
		glFramebufferTexture(GL_READ_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, sourceTex, 0);

		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, targetFbo);;
		glFramebufferTexture(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, targetTex, 0);

		glClearColor(0, 0f, 0, 0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBlitFramebuffer(0, 0, size.x, size.y, 0, 0, size.x, size.y, GL_COLOR_BUFFER_BIT, GL_LINEAR);
		
		// We need to wait here for the blit operation to finish to prevent copying an empty texture in FX context
		glFinish(); // TODO replace with fence

		glDeleteFramebuffer(sourceFbo);
		glDeleteFramebuffer(targetFbo);
	}
	
	public static void dumpIOSurface(long ioSurfaceID, Vec2i size) {
		System.err.println("dumpIOSurface " + ioSurfaceID);
		int tempTexture = glGenTexture();
		CGLContextObj cglContext = CGLGetCurrentContext();
		System.err.println("GOT CONTEXT " + cglContext);
		IOSurfaceRef ioSurface = IOSurfaceLookup(ioSurfaceID);
		System.err.println("GOT IOSURFACE " + ioSurface);
		//System.err.println("Got cglContext=" + cglContext + " and ioSurface=" + ioSurface);
		GL.glBindTexture(GL_TEXTURE_RECTANGLE, tempTexture);
		CGLError success = CGLTexImageIOSurface2D(cglContext, GL_TEXTURE_RECTANGLE, GL_RGBA, size.x, size.y, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, ioSurface, 0);
		GL.glBindTexture(GL_TEXTURE_RECTANGLE, 0);
		System.err.println("mount success_: " + success);
		
		MacOS.IOSurfaceLock(ioSurface);
		
		int memSize = size.x * size.y * 4;
//		long memPointer = malloc(memSize);
		
		ByteBuffer buf = ByteBuffer.allocateDirect(memSize);
		buf.put((byte)1);
		buf.put((byte)1);
		buf.put((byte)1);
		buf.put((byte)1);
		buf.clear();
		long memPointer = MemoryStack.getBufferAddress(buf);
		
		downloadToMemorySimple(GL_TEXTURE_RECTANGLE, tempTexture, memPointer);
		
		byte r = buf.get();
		byte g = buf.get();
		byte b = buf.get();
		byte a = buf.get();
		System.err.println("First Pixel: " + r + " / " + g + " / " + b + " / " + a);

		
//		SYS.free(memPointer);
		
		
		MacOS.IOSurfaceUnlock(ioSurface);
		
		
		glDeleteTexture(tempTexture);
		CFRelease(ioSurface);
		
		
	}
	
	public static void dumpGLTexture(int name, Vec2i size) {
		System.err.println("dumpGLTexture " + name);
		
		int memSize = size.x * size.y * 4;
		
		ByteBuffer buf = ByteBuffer.allocateDirect(memSize);
		buf.put((byte)1);
		buf.put((byte)1);
		buf.put((byte)1);
		buf.put((byte)1);
		buf.clear();
		long memPointer = MemoryStack.getBufferAddress(buf);
		
		downloadToMemorySimple(GL_TEXTURE_2D, name, memPointer);
		
		byte r = buf.get();
		byte g = buf.get();
		byte b = buf.get();
		byte a = buf.get();
		System.err.println("First Pixel: " + r + " / " + g + " / " + b + " / " + a);
		
		
	}
	
	
	@Override
	public void update() {
		// we need to use our QuantumHelper here because if we setup the blit operation on the quantum thread we destroy some gl state which leads to black surfaces in javafx
		QuantumHelper.syncExecute(rf, () -> {
		
			// we need to copy the io surface content over to the fx texture since the targets are incompatible

			// sync io surface
			GL.glBindTexture(GL.GL_TEXTURE_RECTANGLE, 0);
			GL.glBindFramebuffer(GL.GL_FRAMEBUFFER, 0);
			
			blitFramebuffer();
			
			glFinish(); // The quantum renderer needs to wait for this to be done
			// TODO replace with a fence
		});
	}
	
	
private static void downloadToMemorySimple(int target, int tex, long pPixels) {
		
//		int format = GL_RGBA; // TODO need GL_BGRA on windows
//		int format = GL_BGRA;
		
		// we change the colors here for directx upload
		int format = Prism.isD3D() ? GL_BGRA : GL_RGBA;
		
		glBindTexture(target, tex);
		glGetTexImage(target, 0, format, GL_UNSIGNED_INT_8_8_8_8_REV, pPixels);
		glBindTexture(target, 0);
		System.out.println("*downloaded " + tex + " => 0x" + Long.toHexString(pPixels));
		System.out.flush();
	}
	
	private static void downloadToMemoryBuf(int tex, int size, long pPixels) {
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
	
}
