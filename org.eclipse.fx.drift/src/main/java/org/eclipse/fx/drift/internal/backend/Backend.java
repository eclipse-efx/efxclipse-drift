package org.eclipse.fx.drift.internal.backend;

import java.util.function.Consumer;

import org.eclipse.fx.drift.SwapchainConfig;
import org.eclipse.fx.drift.internal.transport.Command;

public interface Backend {

	BackendSwapchain createSwapchain(SwapchainConfig config);
	
	// transport api
	void setCommandChannel(Consumer<Command> commandChannel);
	void receiveCommand(Command command); 
	void sendCommand(Command command);
}
