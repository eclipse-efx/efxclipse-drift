package org.eclipse.fx.drift.internal;

public class GL {
	
	static {
		System.loadLibrary("driftfx");
		initialize();
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
	
	public static native int glGenBuffer();
	public static native void glDeleteBuffer(int buffer);
	public static native void glBufferData(int target, int size, long pData, int usage);
	public static native void glBindBuffer(int target, int buffer);
	public static native long glMapBuffer(int target, int access);
	public static native void glUnmapBuffer(int target);
	
	
	public static native void initialize();
	public static native long createContext(long sharedContext);
	public static native void destroyContext(long context);
	public static native void makeContextCurrent(long context);
	
	public static native void glewInit();
	
}
