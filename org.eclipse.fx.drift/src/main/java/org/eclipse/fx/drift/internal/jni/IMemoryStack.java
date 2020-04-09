package org.eclipse.fx.drift.internal.jni;

import org.eclipse.fx.drift.internal.jni.MemoryStack.Long;

public interface IMemoryStack {
	/** the allocated memory will be uninitialized! */
	Long allocateLong();
	Long allocateLong(long initialValue);
	
	interface IScopedMemeoryStack extends IMemoryStack, AutoCloseable {
		@Override
		void close();
	}

}