package org.eclipse.fx.drift.internal;

import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;
import java.util.concurrent.atomic.AtomicReference;

public class SwapChain {

	private final long pSwapChain;
	
	public final int transferMode;
	public final int presentationMode;
	public final int presentationHint;
	
	public final int width;
	public final int height;
	
	private AtomicReference<SwapChainImage> mailbox = new AtomicReference<>();
	private Queue<SwapChainImage> fifo = new ConcurrentLinkedQueue<>();
	
	private Runnable onAvail;
	
	public SwapChain(long pSwapChain, int width, int height, int transferMode, int presentationMode, int presentationHint) {
		this.pSwapChain = pSwapChain;
		this.width = width;
		this.height = height;
		this.transferMode = transferMode;
		this.presentationMode = presentationMode;
		this.presentationHint = presentationHint;
	}
	
	public void setOnAvail(Runnable onAvail) {
		this.onAvail = onAvail;
	}
	
	public SwapChainImage getNextImage() {
		if (presentationMode == 0) {
			// FIFO
			return fifo.poll();
		}
		else if (presentationMode == 1) {
			// MAILBOX
			return mailbox.getAndSet(null);
		}
		throw new IllegalStateException("unkown presentation mode! " + presentationMode);
	}
	
	// called from native
	public void present(SwapChainImage image) {
		if (presentationMode == 0) {
			System.out.println("java present fifo " + image);
			// FIFO
			fifo.offer(image);
			
			if (onAvail != null) {
				onAvail.run();
			}
		}
		else if (presentationMode == 1) {
			System.out.println("java present mailbox " + image);
			// MAILBOX
			SwapChainImage discared = mailbox.getAndSet(image);
			if (discared != null) {
				System.out.println("MAILBOX: discarding image " + discared);
				Release(discared);
			}
			
			if (onAvail != null) {
				onAvail.run();
			}
		}
		else {
			throw new IllegalStateException("unkown presentation mode! " + presentationMode);
		}
	}
	
	public void Release(SwapChainImage image) {
		Log.debug("Release " + image);
		nRelease(pSwapChain, image.pSwapChainImage);
	}
	
	private native void nRelease(long pointer, long pSwapChainImage);
	
	
	
}
