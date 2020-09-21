package org.eclipse.fx.drift.internal.frontend;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.UUID;
import java.util.function.Consumer;

import org.eclipse.fx.drift.DriftFXSurface;
import org.eclipse.fx.drift.PresentationMode;
import org.eclipse.fx.drift.Vec2i;
import org.eclipse.fx.drift.internal.DriftFX;
import org.eclipse.fx.drift.internal.DriftLogger;
import org.eclipse.fx.drift.internal.common.ImageData;
import org.eclipse.fx.drift.internal.transport.Command;
import org.eclipse.fx.drift.internal.transport.command.CreateSwapchainCommand;
import org.eclipse.fx.drift.internal.transport.command.DisposeSwapchainCommand;
import org.eclipse.fx.drift.internal.transport.command.PresentCommand;
import org.eclipse.fx.drift.internal.transport.command.ReleaseCommand;

import javafx.application.Platform;

public class FrontendImpl implements Frontend {
	private static final DriftLogger LOGGER = DriftFX.createLogger(FrontendImpl.class);
	
	private DriftFXSurface surface;
	
	private FrontSwapChain swapChain;
	private Map<UUID, FrontSwapChain> swapChains = new HashMap<>();
	
	private Consumer<Command> commandChannel;
	
	
	public FrontendImpl(DriftFXSurface surface) {
		this.surface = surface;
	}
	
	@Override
	public Vec2i getSize() {
		double w = surface.getWidth();
		double h = surface.getHeight();
		double userScale = surface.getUserScaleFactor();
		double screenScale = surface.getScreenScaleFactor();
		
		int x = (int) Math.ceil(w * userScale * screenScale);
		int y = (int) Math.ceil(h * userScale * screenScale);
		
		return new Vec2i(x, y);
	}

	public void doCreateSwapchain(UUID id, List<ImageData> images, PresentationMode presentationMode) {
		swapChain = new SimpleFrontSwapChain(id, images, presentationMode, this::sendRelease);
		swapChains.put(id, swapChain);
		surface.setSwapChain(swapChain);
	}
	
	public void doDisposeSwapchain(UUID id) {
		swapChains.get(id).scheduleDispose();
		// notify surface so that its renderContent gets invoked by the quantum renderer
		// the backend needs to wait until the frontend has finished disposing its part of the swap chain
		Platform.runLater(surface::dirty);
	}

	public void doPresent(ImageData image) {
		swapChain.present(image);
		surface.dirty();
	}
	
	private void sendRelease(UUID id, ImageData image) {
		commandChannel.accept(new ReleaseCommand(id, image));
	}

	@Override
	public void setCommandChannel(Consumer<Command> commandChannel) {
		this.commandChannel = commandChannel;
	}
	
	@Override
	public void receiveCommand(Command command) {
//		System.err.println("Frontend received " + command);
		
		if (command instanceof CreateSwapchainCommand) {
			LOGGER.debug(() -> "Frontend received " + command);
			CreateSwapchainCommand cmd = (CreateSwapchainCommand) command;
			doCreateSwapchain(cmd.getId(), cmd.getImages(), cmd.getPresentatioMode());
		}
		else if (command instanceof PresentCommand) {
			PresentCommand cmd = (PresentCommand) command;
			if (cmd.getSwapChainId().equals(swapChain.getId())) {
				doPresent(cmd.getImageData());
			}
			else {
				LOGGER.debug(() -> "!!! Instant release");
				sendRelease(cmd.getSwapChainId(), cmd.getImageData());
			}
		}
		else if (command instanceof DisposeSwapchainCommand) {
			LOGGER.debug(() -> "Frontend received " + command);
			DisposeSwapchainCommand cmd = (DisposeSwapchainCommand) command;
			doDisposeSwapchain(cmd.getId());
		}
	}

}
