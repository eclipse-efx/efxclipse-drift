package org.eclipse.fx.drift.internal;

import java.util.concurrent.Executor;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadFactory;
import java.util.concurrent.atomic.AtomicReference;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;
import java.util.function.Supplier;

import org.eclipse.fx.drift.internal.GPUSyncUtil.GPUSync;
import org.eclipse.fx.drift.internal.prism.PrismES2;

import com.sun.prism.ResourceFactory;

public class QuantumRendererHelper {
	
	public static class WithFence<T> {
		
		private GPUSync sync;
		private T result;
		
		public WithFence(T result, GPUSync sync) {
			this.sync = sync;
			this.result = result;
		}
		
		public T getResult() {
			return result;
		}
		public GPUSync getFence() {
			return sync;
		}
	}
	
	public static void initialize(long es2ContextHandle) {
		if (!initialized) {
			context = syncExecute(() -> {
				// TODO context version should be same as fx!!
				System.out.println("QuantumRendererHelper: creating shared context for " + es2ContextHandle);
				long es2Context = GL.wrapContext(es2ContextHandle);
				long context = GL.createSharedCompatContext(es2Context);
				boolean result = GL.makeContextCurrent(context);
				System.out.println("=> " + result);
				return context;
			});
			initialized = true;
		}
	}

	static boolean initialized = false;
	
	static Executor executor = Executors.newSingleThreadExecutor(new ThreadFactory() {
		@Override
		public Thread newThread(Runnable r) {
			Thread t = new Thread(r);
			t.setName("QuantumRenderer-DriftFX-Helper");
			t.setDaemon(true);
			return t;
		}
	});

	public static long context;
	
	public static <T> T syncExecute(Supplier<T> r) {
//		if (!initialized) {
//			internalSyncExecute(() -> {
//				// TODO
//			});
//			initialized = true;
//		}
		return internalSyncExecute(r);
	}
	
	public static <T> WithFence<T> syncExecuteWithFence(Supplier<T> r) {
		T result = syncExecute(r);
		GPUSync fence = GPUSyncUtil.createFence();
		return new WithFence<>(result, fence);
	}
	
	
	public static void syncExecute(Runnable r) {
//		if (!initialized) {
//			internalSyncExecute(() -> {
//				// TODO
//			});
//			initialized = true;
//		}
		internalSyncExecute(r);
	}
	
	public static GPUSync syncExecuteWithFence(Runnable r) {
		syncExecute(r);
		return GPUSyncUtil.createFence();
	}
	
	static void internalSyncExecute(Runnable r) {
		ReentrantLock lock = new ReentrantLock();
		Condition done = lock.newCondition();
		lock.lock();
		executor.execute(() -> {
			lock.lock();
			System.out.println(" ==>");
			r.run();
			System.out.println(" ***");
			done.signal();
			lock.unlock();
		});
		try {
			done.await();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

	static <T> T internalSyncExecute(Supplier<T> r) {
		ReentrantLock lock = new ReentrantLock();
		AtomicReference<T> result = new AtomicReference<>();
		Condition done = lock.newCondition();
		lock.lock();
		executor.execute(() -> {
			lock.lock();
			result.set(r.get());
			done.signal();
			lock.unlock();
		});
		try {
			done.await();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		return result.get();
	}
	
}
