package org.eclipse.fx.drift.internal.transport.command;

import java.util.UUID;

import org.eclipse.fx.drift.internal.transport.Command;

public class DisposeSwapchainCommand implements Command {
	public final static String NAME = "DisposeSwapchain";
	private UUID id;
	
	public DisposeSwapchainCommand(UUID id) {
		this.id = id;
	}
	
	public UUID getId() {
		return id;
	}
	
	@Override
	public String getName() {
		return NAME;
	}
	
	@Override
	public String toString() {
		return NAME + " " + id;
	}
}
