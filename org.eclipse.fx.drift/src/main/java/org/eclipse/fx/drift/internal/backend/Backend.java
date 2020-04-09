package org.eclipse.fx.drift.internal.backend;

import java.util.function.Consumer;

import org.eclipse.fx.drift.TransferType;
import org.eclipse.fx.drift.Vec2i;
import org.eclipse.fx.drift.PresentationMode;
import org.eclipse.fx.drift.internal.transport.Command;

public interface Backend {

	BackSwapChain createSwapChain(Vec2i size, int imageCount, PresentationMode presentationMode, TransferType type);
	
	// transport api
	void setCommandChannel(Consumer<Command> commandChannel);
	void receiveCommand(Command command); 
	void sendCommand(Command command);
}
