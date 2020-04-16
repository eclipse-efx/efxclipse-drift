package org.eclipse.fx.drift.internal.jni.macos;

import java.util.Arrays;

public class MacOS {

	private MacOS() {}
	
	public static class CFTypeRef {
		public final long address;
		public CFTypeRef(long address) {
			this.address = address;
		}
	}
	
	public static class IOSurfaceRef extends CFTypeRef {
		public IOSurfaceRef(long address) {
			super(address);
		}
		@Override
		public String toString() {
			return getClass().getSimpleName()+"["+address+"]";
		}
	}

	// TODO this is the only native implemented call since it needs some more CF functions and types to be wrapped
	public static IOSurfaceRef createIOSurface(int width, int height) {
		long address = callCreateIOSurface(width, height);
		if (address == 0) {
			return null;
		}
		return new IOSurfaceRef(address);
	}
	
	private static native long callCreateIOSurface(int width, int height);
	
	public static void CFRelease(CFTypeRef typeRef) {
		callCFRelease(typeRef.address);
	}
	private static native void callCFRelease(long typeRef);
	
	public static long IOSurfaceGetID(IOSurfaceRef ioSurface) {
		return callIOSurfaceGetID(ioSurface.address);
	}
	private static native long callIOSurfaceGetID(long ioSurface);
	
	public static IOSurfaceRef IOSurfaceLookup(long ioSurfaceID) {
		long address = callIOSurfaceLookup(ioSurfaceID);
		if (address == 0) {
			return null;
		}
		return new IOSurfaceRef(address);
		
	}
	private static native long callIOSurfaceLookup(long ioSurfaceID);
	
	
	public static enum CGLError {
		/** no error */
			kCGLNoError            (0),     
			/** invalid pixel format attribute  */
			kCGLBadAttribute       (10000),	
			/** invalid renderer property       */
			kCGLBadProperty        (10001),	
			/** invalid pixel format            */
			kCGLBadPixelFormat     (10002),
			/** invalid renderer info           */
			kCGLBadRendererInfo    (10003),
			/** invalid context                 */
			kCGLBadContext         (10004),
			/** invalid drawable                */
			kCGLBadDrawable        (10005),	
			/** invalid graphics device         */
			kCGLBadDisplay         (10006),	
			/** invalid context state           */
			kCGLBadState           (10007),	
			/** invalid numerical value         */
			kCGLBadValue           (10008),	
			/** invalid share context           */
			kCGLBadMatch           (10009),	
			/** invalid enumerant               */
			kCGLBadEnumeration     (10010),	
			/** invalid offscreen drawable      */
			kCGLBadOffScreen       (10011),	
			/** invalid fullscreen drawable     */
			kCGLBadFullScreen      (10012),	
			/** invalid window                  */
			kCGLBadWindow          (10013),	
			/** invalid pointer                 */
			kCGLBadAddress         (10014),	
			/** invalid code module             */
			kCGLBadCodeModule      (10015),
			/** invalid memory allocation       */
			kCGLBadAlloc           (10016),
			/** invalid CoreGraphics connection */
			kCGLBadConnection      (10017); 
		
		public final int code;
		private CGLError(int code) {
			this.code = code;
		}
		
		public static CGLError fromCode(int code) {
			return Arrays.stream(values()).filter(v -> v.code == code).findFirst().orElseThrow(() -> new RuntimeException("Unknown CGLError code: " + code));
		}

	}
	
	public static class CGLContextObj {
		public final long address;
		public CGLContextObj(long address) {
			this.address = address;
		}
		@Override
		public String toString() {
			return "CGLContextObj["+address+"]";
		}
	}
	
	public static CGLContextObj CGLGetCurrentContext() {
		long address = callCGLGetCurrentContext();
		if (address == 0) {
			return null;
		}
		return new CGLContextObj(address);
	}
	private static native long callCGLGetCurrentContext();
	
	public static CGLError CGLTexImageIOSurface2D(CGLContextObj ctx, int target, int internal_format, int width, int height, int format, int type, IOSurfaceRef ioSurface, int plane) {
		int error = callCGLTexImageIOSurface2D(ctx.address, target, internal_format, width, height, format, type, ioSurface.address, plane);
		return CGLError.fromCode(error);
	}
	private static native int callCGLTexImageIOSurface2D(long ctx, int target, int internal_format, int width, int height, int format, int type, long ioSurface, int plane);
	
	public static native long callGetCGLContextObjFromNSJContext(long nsJContext);
	
	
	public static void IOSurfaceLock(IOSurfaceRef ioSurface) {
		callIOSurfaceLock(ioSurface.address);
	}
	private static native void callIOSurfaceLock(long ioSurface);
	
	public static void IOSurfaceUnlock(IOSurfaceRef ioSurface) {
		callIOSurfaceUnlock(ioSurface.address);
	}
	private static native void callIOSurfaceUnlock(long ioSurface);
	
}
