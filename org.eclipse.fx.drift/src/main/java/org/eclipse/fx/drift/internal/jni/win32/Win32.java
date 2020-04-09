package org.eclipse.fx.drift.internal.jni.win32;

import org.eclipse.fx.drift.internal.jni.IMemoryStack.IScopedMemeoryStack;
import org.eclipse.fx.drift.internal.ResourceLogger;
import org.eclipse.fx.drift.internal.jni.MemoryStack;

public class Win32 {

	public static class HRESULT {
		public final long value;
		public HRESULT(long value) {
			this.value = value;
		}
		
		public boolean isOk() {
			return 0 == value;
		}
	}
	
	public static class Pointer {
		public final long address;
		public Pointer(long address) {
			this.address = address;
		}
		@Override
		public String toString() {
			return getClass().getSimpleName() +"[" + Long.toHexString(address) + "]";
		}
	}
	
	public static class NativeLong {
		public long value;
	}
	
	public static class HANDLE extends Pointer {
		public HANDLE(long address) {
			super(address);
		}
	}
	
	public static class IUnknown extends Pointer {
		public IUnknown(long address) {
			super(address);
		}
		public long AddRef() {
			return nIUnknownAddRef(address);
		}
		public long Release() {
			return nIUnknownRelease(address);
		}
	}
	private static native long nIUnknownAddRef(long address);
	private static native long nIUnknownRelease(long address);
	
	
	public final static int D3DUSAGE_NONSECURE =         (0x00800000);
	public final static int D3DUSAGE_DYNAMIC =            (0x00000200);
	
	public final static int D3DFMT_A8R8G8B8             = 21;
	public final static int D3DPOOL_DEFAULT                 = 0;
	
	public static class IDirect3DDevice9 extends IUnknown {
		public IDirect3DDevice9(long address) {
			super(address);
		}
		
		public IDirect3DTexture9 CreateTexture(int width, int height, int levels, int usage, int format, int pool) throws WindowsError {
			try (IScopedMemeoryStack memoryStack = MemoryStack.scoped()) {
				MemoryStack.Long texture = memoryStack.allocateLong(0); // it seems createTexture produces an INVALID_CALL if texture is not set to 0
				MemoryStack.Long shareHandle = memoryStack.allocateLong(0); // shareHandle value needs to be NULL to get one allocated

				long hresult = nIDirect3DDevice9CreateTexture(this.address, width, height, levels, usage, format, pool, texture.getAddress(), shareHandle.getAddress());
				
				WindowsError.checkHResult(hresult);
				
				ResourceLogger.resourceAllocated(texture.get(), "DXTex", "shareHandle="+Long.toHexString(shareHandle.get()));
				
				return new IDirect3DTexture9(texture.get(), new Win32.HANDLE(shareHandle.get()));
			}
		}
		
		public IDirect3DTexture9 CreateTexture(int width, int height, int levels, int usage, int format, int pool, HANDLE shareHandle) throws WindowsError {
			try (IScopedMemeoryStack memoryStack = MemoryStack.scoped()) {
				MemoryStack.Long texture = memoryStack.allocateLong(0);
				MemoryStack.Long shareHandlev = memoryStack.allocateLong(shareHandle.address);
				
				long hresult = nIDirect3DDevice9CreateTexture(this.address, width, height, levels, usage, format, pool, texture.getAddress(), shareHandlev.getAddress());
				
				WindowsError.checkHResult(hresult);
				
				ResourceLogger.resourceAllocated(texture.get(), "DXTex", "shareHandle="+Long.toHexString(shareHandlev.get()));
				
				return new IDirect3DTexture9(texture.get(), new Win32.HANDLE(shareHandlev.get()));
			}
		}
	}
	private static native long nIDirect3DDevice9CreateTexture(long d3d9DeviceEx, int width, int height, int levels, int usage, int format, int pool, long texture, long shareHandle);
	
	public static class IDirect3DDevice9Ex extends IDirect3DDevice9 {
		public IDirect3DDevice9Ex(long address) {
			super(address);
		}
	}
	
	public static class IDirect3DResource9 extends IUnknown {
		public IDirect3DResource9(long address) {
			super(address);
		}
	}
	
	public static class IDirect3DBaseTexture9 extends IDirect3DResource9 {
		public IDirect3DBaseTexture9(long address) {
			super(address);
		}
	}
	
	public static class IDirect3DTexture9 extends IDirect3DBaseTexture9 {
		public final HANDLE shareHandle;
		
		public IDirect3DTexture9(long address, HANDLE shareHandle) {
			super(address);
			this.shareHandle = shareHandle;
		}
		
		public IDirect3DTexture9(long address) {
			this(address, null);
		}
		
		@Override
		public long Release() {
			long res = super.Release();
			if (res == 0) {
				ResourceLogger.resourceDisposed(address);
			}
			return res;
		}
	}
	
}
