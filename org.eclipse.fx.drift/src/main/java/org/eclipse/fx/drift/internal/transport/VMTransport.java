package org.eclipse.fx.drift.internal.transport;

import org.eclipse.fx.drift.internal.backend.Backend;
import org.eclipse.fx.drift.internal.frontend.Frontend;

public class VMTransport {

	private Frontend frontend;
	private Backend backend;
	
	public VMTransport(Frontend frontend, Backend backend) {
		this.frontend = frontend;
		this.backend = backend;
	}
	
	public void start() {
//		frontend.setOnRelease(backend::release);
//		backend.setOnPresent(frontend::present);
//		backend.setOnCreateSwapchain(frontend::createSwapchain);
		
		
		frontend.setCommandChannel(backend::receiveCommand);
		backend.setCommandChannel(frontend::receiveCommand);
	}
}
