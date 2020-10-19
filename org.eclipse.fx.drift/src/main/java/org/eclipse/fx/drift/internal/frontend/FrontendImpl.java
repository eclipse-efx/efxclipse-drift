/* ******************************************************************************
 * Copyright (c) 2019, 2020 BestSolution.at and others.
 * All rights reserved. This program and the accompanying materials 
 * are made available under the terms of the Eclipse Public License 2.0 
 * which is available at http://www.eclipse.org/legal/epl-2.0
 *
 * SPDX-License-Identifier: EPL-2.0
 * 
 * Contributors:
 *     Christoph Caks <ccaks@bestsolution.at> - initial API and implementation
 * ******************************************************************************/
package org.eclipse.fx.drift.internal.frontend;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.UUID;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;
import java.util.function.Consumer;
import java.util.function.Supplier;

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
import org.eclipse.fx.drift.internal.transport.command.SwapchainCreatedCommand;
import org.eclipse.fx.drift.internal.transport.command.SwapchainDisposedCommand;

import com.sun.javafx.tk.RenderJob;
import com.sun.javafx.tk.Toolkit;

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
	
	public <T> CompletableFuture<T> syncCallQuantumRenderer(Supplier<T> job) {
		Toolkit toolkit = Toolkit.getToolkit();
		return CompletableFuture.supplyAsync(job, command ->  {
				Future future = toolkit.addRenderJob(new RenderJob(command));
					try {
						future.get();
					} catch (InterruptedException | ExecutionException e) {
						LOGGER.error(() -> "Exception during quantum renderer job execution", e);
					}
			});
	}
	
	public <T> CompletableFuture<T> asyncCallQuantumRenderer(Supplier<T> job) {
		Toolkit toolkit = Toolkit.getToolkit();
		return CompletableFuture.supplyAsync(job, (command) -> {
			CompletableFuture.runAsync(() -> {
					Future future = toolkit.addRenderJob(new RenderJob(command));
					try {
						future.get();
					} catch (InterruptedException | ExecutionException e) {
						LOGGER.error(() -> "Exception during quantum renderer job execution", e);
					}
				});
			});
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
		swapChain = new SimpleFrontSwapChain(this, id, images, presentationMode, this::sendRelease);
		swapChains.put(id, swapChain);
		commandChannel.accept(new SwapchainCreatedCommand(id));
		
		surface.setSwapChain(swapChain);
	}
	
	public void doDisposeSwapchain(UUID id) {
		FrontSwapChain toDispose = swapChains.remove(id);
		toDispose.dispose().join();
		Platform.runLater(surface::dirty);
	}

	public void doPresent(ImageData image) {
		swapChain.present(image);
		surface.dirty();
	}
	
	private void sendRelease(UUID id, ImageData image) {
		commandChannel.accept(new ReleaseCommand(id, image));
	}
	
	void sendSwapchainDisposed(UUID id) {
		commandChannel.accept(new SwapchainDisposedCommand(id));
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
