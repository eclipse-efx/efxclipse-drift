package org.eclipse.fx.drift.internal.jni;

import java.nio.ByteBuffer;
import java.util.Stack;


public class MemoryStack {

	public class StackData implements Pointer {
		public final int offset;
		public final int size;
		public StackData(int offset, int size) {
			this.offset = offset;
			this.size = size;
		}
		public void allocate() {
			beginOffset += size;
		}
		@Override
		public long getAddress() {
			return address + offset;
		}
	}
	
	public class Long extends StackData {
		public Long(int offset) {
			super(offset, java.lang.Long.SIZE);
		}
		public long get() {
			buffer.position(offset);
			byte[] data = new byte[size / 8];
			buffer.get(data);
			return bytesToLong(data, 0);
		}
		
		public void set(long value) {
			nSetLong(address + offset, value);
		}
		
		public long bytesToLong(final byte[] bytes, final int offset) {
		    long result = 0;
		    for (int i = 7; i >= 0 + offset; i--) {
		        result <<= 8;
		        result |= (bytes[i] & 0xFF);
		    }
		    return result;
		}
	}
	
	private long address;
	private ByteBuffer buffer;
	
	private int beginOffset;
	
	private Stack<java.lang.Integer> stack = new Stack<>();
	
	private static ThreadLocal<MemoryStack> localStack = new ThreadLocal<MemoryStack>();
	
	public static MemoryStack get() {
		if (localStack.get() == null) {
			localStack.set(new MemoryStack());
		}
		return localStack.get();
	}
	
	public MemoryStack() {
		buffer = ByteBuffer.allocateDirect(1024 * 1024);
		address = nGetBufferAddress(buffer);
		beginOffset = 0;
	}
	
	private native long nGetBufferAddress(ByteBuffer buffer);
	
	public long getAddress() {
		return address;
	}
	
	public Long allocateLong() {
		Long value = new Long(beginOffset);
		value.allocate();
		return value;
	}
	
	public void push() {
		stack.push(beginOffset);
	}
	
	public void pop() {
		beginOffset = stack.pop();
	}
	
	private static native void nSetLong(long target, long value);
	private static native void nOutputLong(long target);
	
	public static void output(MemoryStack stack, Long t) {
		System.err.println("J 0x" + java.lang.Long.toHexString(t.get()) + " (" + t.get() + ")");
		nOutputLong(t.getAddress());
	}
	public static void main(String[] args) {
		System.loadLibrary("DriftGL");
		System.loadLibrary("driftfx");
		MemoryStack stack = new MemoryStack();
		
		
		Long l1 = stack.allocateLong();
		//l1.set(java.lang.Long.MIN_VALUE);
		
		output(stack, l1);
		
		nSetLong(stack.getAddress(), java.lang.Long.MAX_VALUE);
		
		output(stack, l1);
		
		Long l2 = stack.allocateLong();
		l2.set(2 + 256);
		
		stack.push();
		{
			Long l3 = stack.allocateLong();
			l3.set(3);
			Long l4 = stack.allocateLong();
			l4.set(4);
			
			output(stack, l4);
		}
		stack.pop();
		
		Long l3 = stack.allocateLong();
		output(stack, l3);
	}
}
