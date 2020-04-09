package org.eclipse.fx.drift.internal.frontend;

import java.util.function.Consumer;

import org.eclipse.fx.drift.Vec2i;
import org.eclipse.fx.drift.internal.transport.Command;

public interface Frontend {

	Vec2i getSize();
	
	// transport api
	void setCommandChannel(Consumer<Command> commandChannel);
	void receiveCommand(Command command); 
}
