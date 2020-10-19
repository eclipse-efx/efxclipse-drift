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
package org.eclipse.fx.drift.internal.backend;

import java.util.HashMap;
import java.util.Map;
import java.util.UUID;
import java.util.concurrent.CompletableFuture;
import java.util.function.Consumer;
import java.util.function.Predicate;

import org.eclipse.fx.drift.SwapchainConfig;
import org.eclipse.fx.drift.internal.transport.Command;
import org.eclipse.fx.drift.internal.transport.command.CreateSwapchainCommand;
import org.eclipse.fx.drift.internal.transport.command.ReleaseCommand;
import org.eclipse.fx.drift.internal.transport.command.SwapchainCreatedCommand;

public class BackendImpl implements Backend {

	private Map<UUID, BackendSwapchain> swapChains = new HashMap<>();
	private BackendSwapchain swapChain;
	
	private Consumer<Command> commandChannel;
	
	private Map<Predicate<Command>, CompletableFuture<?>> await = new HashMap<>();
	
	@Override
	public BackendSwapchain createSwapchain(SwapchainConfig config) {
		UUID id = UUID.randomUUID();
		swapChain = new SimpleSwapchain(this, id, config);
		swapChain.allocate();
		
		swapChains.put(id, swapChain);
		
		CompletableFuture<SwapchainCreatedCommand> waitForCreated = waitForCommand(SwapchainCreatedCommand.class, c -> id.equals(c.getId()));
		sendCommand(new CreateSwapchainCommand(id, swapChain.getImages(), config.presentationMode));
		waitForCreated.join();
		
		return swapChain;
	}
	
	@Override
	public void setCommandChannel(Consumer<Command> commandChannel){
		this.commandChannel = commandChannel;
	}
	
	@Override
	public <C extends Command> CompletableFuture<C> waitForCommand(Class<C> type, Predicate<C> filter) {
		CompletableFuture<C> result = new CompletableFuture<>();
		synchronized (await) {
			await.put(command -> type.isAssignableFrom(command.getClass()) && filter.test((C) command), result);
		}
		return result;
	}
	
	@Override
	public void receiveCommand(Command command) {
//		System.err.println("Backend recceived " + command);
		
		synchronized (await) {
			for (Predicate<Command> test : await.keySet()) {
				if (test.test(command)) {
					CompletableFuture f = await.remove(test);
					f.complete(command);
				}
			}
		}
		
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
