package org.eclipse.fx.drift.internal;

public class GL {
	
	static {
		NativeLoader.loadLibrary(GL.class, "DriftGL");
		NativeLoader.loadLibrary(GL.class, "driftfx");
		if (!initialize()) {
			// TODO throw exception in native code ?
			throw new RuntimeException("Error during DriftGL initialization");
		}
	}
	
	
	
	public static final int GL_TEXTURE_2D = 0x0DE1;
	public static final int GL_TEXTURE_RECTANGLE = 0x84F5;
	
	public static final int GL_RGBA = 0x1908;
	public static final int GL_BGRA = 0x80E1;
	
	public static final int GL_UNSIGNED_BYTE = 0x1401;
	public static final int GL_UNSIGNED_INT_8_8_8_8_REV = 0x8367;
	
	public static final int GL_STATIC_READ = 0x88E5;
	public static final int GL_READ_ONLY = 0x88B8;
	public static final int GL_PIXEL_PACK_BUFFER = 0x88EB;
	public static final int GL_RGB8 = 0x8051;
	public static final int GL_RGBA8 = 0x8058;
	
	public static native int glGenTexture();
	public static native void glDeleteTexture(int texture);
	public static native void glBindTexture(int target, int texture);
	public static native void glTexImage2D(int target, int level, int internalformat, int width, int height, int border, int format, int type, long pPixels);
	public static native void glGetTexImage(int target, int level, int format, int type, long pPixels);
	public static native boolean glIsTexture(int texture);
	
	public static native int glGenBuffer();
	public static native void glDeleteBuffer(int buffer);
	public static native void glBufferData(int target, int size, long pData, int usage);
	public static native void glBindBuffer(int target, int buffer);
	public static native long glMapBuffer(int target, int access);
	public static native void glUnmapBuffer(int target);
	
	
	public static native boolean initialize();
	public static native boolean destroy();
	public static native long createContext(long sharedContext, int majorHint, int minorHint);
	public static native long createSharedCompatContext(long sharedContext);
	public static native long wrapContext(long nativeContextHandle);
	
	public static native long getNativeContextHandle(long context);
	public static native void destroyContext(long context);
	public static native boolean makeContextCurrent(long context);
	public static native boolean isContextCurrent(long context);
	public static native long getCurrentContext();
	
	public static final int GL_COLOR_BUFFER_BIT = 0x00004000;
	public static final int GL_FRAMEBUFFER = 0x8D40;
	public static final int GL_COLOR_ATTACHMENT0 = 0x8CE0;
	
	public static final int GL_LINEAR = 0x2601;
	public static final int GL_READ_FRAMEBUFFER = 0x8CA8;
	public static final int GL_DRAW_FRAMEBUFFER = 0x8CA9;
	
	public static native void glClearColor(float red, float green, float blue, float alpha);
	public static native void glClear(int mask);
	
	public static native int glGetError();
	
	public static native int glGenFramebuffer();
	public static native void glBindFramebuffer(int target, int framebuffer);
	public static native void glFramebufferTexture(int target, int attachment, int texture, int level);
	public static native void glDeleteFramebuffer(int framebuffer);
	public static native void glBlitFramebuffer(int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, int mask, int filter);
	
	
	public static native void glFlush();
	public static native void glFinish();
	
	
	public static native long glCreateFence();
	public static native void glDeleteSync(long sync);
	
	public static final int GL_AREADY_SIGNALED = 0x911A;
	public static final int GL_TIMEOUT_EXPIRED = 0x911B;
	public static final int GL_CONDITION_SATISFIED = 0x911C;
	public static final int GL_WAIT_FAILED = 0x911D;
	public static native int glClientWaitSync(long sync, long timeout);
	
	public static native void glWaitSync(long sync);
	
	
	public static final int GL_UNPACK_SWAP_BYTES = 0x0CF0;
	public static final int GL_UNPACK_LSB_FIRST = 0x0CF1;
	public static final int GL_UNPACK_ROW_LENGTH = 0x0CF2;
	public static final int GL_UNPACK_SKIP_ROWS = 0x0CF3;
	public static final int GL_UNPACK_SKIP_PIXELS = 0x0CF4;
	public static final int GL_UNPACK_ALIGNMENT = 0x0CF5;
	public static final int GL_PACK_SWAP_BYTES = 0x0D00;
	public static final int GL_PACK_LSB_FIRST = 0x0D01;
	public static final int GL_PACK_ROW_LENGTH = 0x0D02;
	public static final int GL_PACK_SKIP_ROWS = 0x0D03;
	public static final int GL_PACK_SKIP_PIXELS = 0x0D04;
	public static final int GL_PACK_ALIGNMENT = 0x0D05;
	
	public static final int GL_PACK_SKIP_IMAGES = 0x806B;
	public static final int GL_PACK_IMAGE_HEIGHT = 0x806C;
	public static final int GL_UNPACK_SKIP_IMAGES = 0x806D;
	public static final int GL_UNPACK_IMAGE_HEIGHT = 0x806E;
	
	public static final int GL_UNPACK_COMPRESSED_BLOCK_WIDTH = 0x9127;
	public static final int GL_UNPACK_COMPRESSED_BLOCK_HEIGHT = 0x9128;
	public static final int GL_UNPACK_COMPRESSED_BLOCK_DEPTH = 0x9129;
	public static final int GL_UNPACK_COMPRESSED_BLOCK_SIZE = 0x912A;
	public static final int GL_PACK_COMPRESSED_BLOCK_WIDTH = 0x912B;
	public static final int GL_PACK_COMPRESSED_BLOCK_HEIGHT = 0x912C;
	public static final int GL_PACK_COMPRESSED_BLOCK_DEPTH = 0x912D;
	public static final int GL_PACK_COMPRESSED_BLOCK_SIZE = 0x912E;

	
	public static native void glPixelStorei(int pname, int param);
	public static native void glPixelStoref(int pname, float param);
	
	public static native int glGetInteger(int pname);
	public static native float glGetFloat(int pname);
	
	
}
