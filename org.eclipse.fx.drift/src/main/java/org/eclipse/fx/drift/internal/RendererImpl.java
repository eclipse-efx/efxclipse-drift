package org.eclipse.fx.drift.internal;

import java.util.HashMap;
import java.util.Map;

import org.eclipse.fx.drift.DriftFXSurface;
import org.eclipse.fx.drift.PresentationMode;
import org.eclipse.fx.drift.Renderer;
import org.eclipse.fx.drift.Swapchain;
import org.eclipse.fx.drift.SwapchainConfig;
import org.eclipse.fx.drift.TransferType;
import org.eclipse.fx.drift.Vec2i;
import org.eclipse.fx.drift.internal.backend.Backend;
import org.eclipse.fx.drift.internal.backend.BackendImpl;
import org.eclipse.fx.drift.internal.frontend.Frontend;
import org.eclipse.fx.drift.internal.frontend.FrontendImpl;
import org.eclipse.fx.drift.internal.transport.VMTransport;

public class RendererImpl implements Renderer {

	private static Map<DriftFXSurface, Renderer> renderers = new HashMap<>();
	
	public static Renderer getRenderer(DriftFXSurface surface) {
		return renderers.computeIfAbsent(surface, surf -> new RendererImpl(surf));
		
	}

	private DriftFXSurface surface;
	private Backend backend;
	private Frontend frontend;
	private VMTransport transport;
	
	public RendererImpl(DriftFXSurface surface) {
		this.surface = surface;
		
		backend = new BackendImpl();
		frontend = new FrontendImpl(surface);
		transport = new VMTransport(frontend, backend);
		transport.start();
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
	
	@Override
	public Swapchain createSwapChain(Vec2i size, int imageCount, PresentationMode presentationMode, TransferType type) {
		if (presentationMode == null) {
			presentationMode = PresentationMode.MAILBOX;
		}
		System.out.println("java createSwapChain(" + size + ", " + imageCount + ", " + presentationMode + ", " + type +")");
		return backend.createSwapChain(size, imageCount, presentationMode, type);
	}

	@Override
	public Swapchain createSwapchain(SwapchainConfig config) {
		return createSwapChain(config.size, config.imageCount, config.presentationMode, config.transferType);
	}
}
