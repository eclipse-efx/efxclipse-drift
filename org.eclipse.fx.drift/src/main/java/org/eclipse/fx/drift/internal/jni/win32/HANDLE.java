package org.eclipse.fx.drift.internal.jni.win32;

public class HANDLE {
	
	public static final HANDLE NULL = new HANDLE(0);
	
	public final long pointer;
	private HANDLE(long pointer) {
		this.pointer = pointer;
	}
	public static HANDLE fromPointer(long pointer) {
		return new HANDLE(pointer);
	}
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + (int) (pointer ^ (pointer >>> 32));
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
		HANDLE other = (HANDLE) obj;
		if (pointer != other.pointer)
			return false;
		return true;
	}
	
}
