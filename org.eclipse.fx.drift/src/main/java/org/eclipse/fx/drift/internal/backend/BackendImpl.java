package org.eclipse.fx.drift.internal.backend;

import java.util.HashMap;
import java.util.Map;
import java.util.UUID;
import java.util.function.Consumer;

import org.eclipse.fx.drift.TransferType;
import org.eclipse.fx.drift.Vec2i;
import org.eclipse.fx.drift.PresentationMode;
import org.eclipse.fx.drift.SwapchainConfig;
import org.eclipse.fx.drift.internal.transport.Command;
import org.eclipse.fx.drift.internal.transport.command.CreateSwapchainCommand;
import org.eclipse.fx.drift.internal.transport.command.PresentCommand;
import org.eclipse.fx.drift.internal.transport.command.ReleaseCommand;

public class BackendImpl implements Backend {

	private Map<UUID, BackendSwapchain> swapChains = new HashMap<>();
	private BackendSwapchain swapChain;
	
	private Consumer<Command> commandChannel;
	
	@Override
	public BackendSwapchain createSwapchain(SwapchainConfig config) {
		UUID id = UUID.randomUUID();
		swapChain = new SimpleSwapchain(this, id, config);
		swapChain.allocate();
		
		swapChains.put(id, swapChain);
		
		sendCommand(new CreateSwapchainCommand(id, swapChain.getImages(), config.presentationMode));
		
		return swapChain;
	}
	
	@Override
	public void setCommandChannel(Consumer<Command> commandChannel){
		this.commandChannel = commandChannel;
	}
	@Override
	public void receiveCommand(Command command) {
//		System.err.println("Backend recceived " + command);
		
		if (command instanceof ReleaseCommand) {
			ReleaseCommand cmd = (ReleaseCommand) command;
			swapChains.get(cmd.getSwapChainId()).release(cmd.getImageData());
		}
	}
	@Override
	public void sendCommand(Command command) {
		this.commandChannel.accept(command);
	}

}
