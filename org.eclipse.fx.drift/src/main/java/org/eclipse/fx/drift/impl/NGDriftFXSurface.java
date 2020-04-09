/*******************************************************************************
 * Copyright (c) 2019 BestSolution.at and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Christoph Caks <ccaks@bestsolution.at> - initial API and implementation
 *******************************************************************************/
package org.eclipse.fx.drift.impl;

import java.util.Optional;

import org.eclipse.fx.drift.BaseDriftFXSurface;
import org.eclipse.fx.drift.internal.FPSCounter2;
import org.eclipse.fx.drift.internal.Log;
import org.eclipse.fx.drift.internal.Placement;
import org.eclipse.fx.drift.internal.SurfaceData;
import org.eclipse.fx.drift.internal.frontend.FrontSwapChain;
import org.eclipse.fx.drift.internal.frontend.FxImage;
import org.eclipse.fx.drift.internal.frontend.SimpleFrontSwapChain;

import com.sun.javafx.geom.transform.BaseTransform;
import com.sun.javafx.sg.prism.NGNode;
import com.sun.prism.Graphics;
import com.sun.prism.Texture;
import com.sun.prism.paint.Color;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.util.Duration;

// Note: this implementation is against internal JavafX API
@SuppressWarnings("restriction")
public class NGDriftFXSurface extends NGNode {

	private final static boolean showFPS = Boolean.getBoolean("driftfx.showfps");
	private final static boolean profile = Boolean.getBoolean("driftfx.profile");

	private SurfaceData surfaceData;
	private FrontSwapChain nextSwapChain;
	private FrontSwapChain swapChain;
	
	private BaseDriftFXSurface node;
	
	/** image currently in use by javafx renderer - we may not dispose it */
	private FxImage<?> curImage;
	
	private FPSCounter2 fxFpsCounter = new FPSCounter2(100);
	
	public void setSwapChain(FrontSwapChain swapChain) {
		this.nextSwapChain = swapChain;
	}
	
	public NGDriftFXSurface(BaseDriftFXSurface node) {
		this.node = node;
		
		Timeline historyTick = new Timeline(new KeyFrame(Duration.millis(100), new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent arg0) {
				fxFpsCounter.historyTick();
				if (swapChain != null) ((SimpleFrontSwapChain)swapChain).fpsCounter.historyTick();
			}
		}));
		historyTick.setCycleCount(Timeline.INDEFINITE);
		historyTick.play();
			
	}
	
	public void destroy() {
		
	}
	
	@Override
	protected void finalize() throws Throwable {
		super.finalize();
		destroy();
	}
	
	private float center(float dst, float src) {
		return (dst - src) / 2f;
	}
	private float end(float dst, float src) {
		return dst - src;
	}
	
	static class Pos {
		float x;
		float width;
		float y;
		float height;
		Pos(float x, float width, float y, float height) {
			this.x = x;
			this.width = width;
			this.y = y;
			this.height = height;
		}
	}
	
	private Pos computeCover(float dstWidth, float dstHeight, float srcWidth, float srcHeight) {
		float dstRatio = dstWidth / dstHeight;
		float srcRatio = srcWidth / srcHeight;
		float width, height;
		if (dstRatio > srcRatio) {
			width = dstWidth;
			height = width / srcRatio;
		}
		else {
			height = dstHeight;
			width = height * srcRatio;
		}
		return new Pos(center(dstWidth, width), width, center(dstHeight, height), height);
		
	}
	private Pos computeContain(float dstWidth, float dstHeight, float srcWidth, float srcHeight)  {
		float dstRatio = dstWidth / dstHeight;
		float srcRatio = srcWidth / srcHeight;
		float width, height;
		if (srcRatio <= dstRatio) {
			height = dstHeight;
			width = height * srcRatio;
		}
		else {
			width = dstWidth;
			height = width / srcRatio;
		}
		return new Pos(center(dstWidth, width), width, center(dstHeight, height), height);
	}
	private Pos computeCenter(float dstWidth, float dstHeight, float srcWidth, float srcHeight) {
		return new Pos(center(dstWidth, srcWidth), srcWidth, center(dstHeight, srcHeight), srcHeight);
	}
	private Pos computeTopLeft(float dstWidth, float dstHeight, float srcWidth, float srcHeight) {
		return new Pos(0, srcWidth, 0, srcHeight);
	}
	private Pos computeTopCenter(float dstWidth, float dstHeight, float srcWidth, float srcHeight) {
		return new Pos(center(dstWidth, srcWidth), srcWidth, 0, srcHeight);
	}
	private Pos computeTopRight(float dstWidth, float dstHeight, float srcWidth, float srcHeight) {
		return new Pos(end(dstWidth, srcWidth), srcWidth, 0, srcHeight);
	}
	private Pos computeCenterLeft(float dstWidth, float dstHeight, float srcWidth, float srcHeight) {
		return new Pos(0, srcWidth, center(dstHeight, srcHeight), srcHeight);
	}
	private Pos computeCenterRight(float dstWidth, float dstHeight, float srcWidth, float srcHeight) {
		return new Pos(end (dstWidth, srcWidth), srcWidth, center(dstHeight, srcHeight), srcHeight);
	}
	private Pos computeBottomLeft(float dstWidth, float dstHeight, float srcWidth, float srcHeight) {
		return new Pos(0, srcWidth, end(dstHeight, srcHeight), srcHeight);
	}
	private Pos computeBottomCenter(float dstWidth, float dstHeight, float srcWidth, float srcHeight) {
		return new Pos(center(dstWidth, srcWidth), srcWidth, end(dstHeight, srcHeight), srcHeight);
	}
	private Pos computeBottomRight(float dstWidth, float dstHeight, float srcWidth, float srcHeight) {
		return new Pos(end(dstWidth, srcWidth), srcWidth, end(dstHeight, srcHeight), srcHeight);
	}
	
	private Pos computePlacement(Placement placement, float dstWidth, float dstHeight, float srcWidth, float srcHeight) {
		switch (placement) {
		case COVER: return computeCover(dstWidth, dstHeight, srcWidth, srcHeight);
		case CONTAIN: return computeContain(dstWidth, dstHeight, srcWidth, srcHeight);
		case TOP_LEFT: return computeTopLeft(dstWidth, dstHeight, srcWidth, srcHeight);
		case TOP_CENTER: return computeTopCenter(dstWidth, dstHeight, srcWidth, srcHeight);
		case TOP_RIGHT: return computeTopRight(dstWidth, dstHeight, srcWidth, srcHeight);
		case CENTER_LEFT: return computeCenterLeft(dstWidth, dstHeight, srcWidth, srcHeight);
		case CENTER_RIGHT: return computeCenterRight(dstWidth, dstHeight, srcWidth, srcHeight);
		case BOTTOM_LEFT: return computeBottomLeft(dstWidth, dstHeight, srcWidth, srcHeight);
		case BOTTOM_CENTER: return computeBottomCenter(dstWidth, dstHeight, srcWidth, srcHeight);
		case BOTTOM_RIGHT: return computeBottomRight(dstWidth, dstHeight, srcWidth, srcHeight);
		case CENTER:
			default:
				return computeCenter(dstWidth, dstHeight, srcWidth, srcHeight);
		}
	}
	
	private Placement toPlacement(int placement) {
		if (placement < 0 || placement >= Placement.values().length) {
			return Placement.CENTER;
		}
		return Placement.values()[placement];
	}
	
	private void drawStats(Graphics g) {
		DriftDebug.assertQuantumRenderer();
		if (swapChain != null) {
			g.setPaint(new Color(0,0,0,0.5f));
			g.fillRect(155, 0, 150, 85);
			String info = "Texture: " + swapChain.getSize().x + "x" + swapChain.getSize().y;
			info += "\nTransfer: " + swapChain.getTransferType().id;
			NGRenderUtil.writeText(g, -155, 0, 12, info, Color.WHITE, false);
		}
		NGRenderUtil.drawFPSGraph(g, 0, 0, 150, 40, "JavaFX", fxFpsCounter);
		if (swapChain != null) {
			FPSCounter2 c = ((SimpleFrontSwapChain)swapChain).fpsCounter;
			NGRenderUtil.drawFPSGraph(g, 0, 45, 150, 40, "Renderer", c);
		}
	}
	
	private void drawTexture(Graphics g, Texture t) {
		float frameContainerWidth = surfaceData.width;
		float frameContainerHeight = surfaceData.height;
		
		// TODO
		//Placement placement = toPlacement(swapChain.presentationHint);
		Placement placement = Placement.CENTER;
		
		float textureRatio = t.getContentWidth() / (float) t.getContentHeight();
		float frameRatio = surfaceData.width / surfaceData.height;
		
		Pos framePos = new Pos(0, frameContainerWidth, 0, frameContainerHeight);
		
		if (Math.abs(textureRatio - frameRatio) > 0.001f) {
			// aspect ratio is not matching, we need to do compute the position within the frame container
			framePos = computeContain(frameContainerWidth, frameContainerHeight, t.getContentWidth(), t.getContentHeight());
		}
		
		int frameTextureWidth = t.getContentWidth();
		int frameTextureHeight = t.getContentHeight();
		
		float currentContainerWidth = this.surfaceData.width;
		float currentContainerHeight = this.surfaceData.height;	

		Pos pos = computePlacement(placement, currentContainerWidth, currentContainerHeight, framePos.width, framePos.height);

		// flip it vertically
		g.scale(1, -1);
		g.translate(0, -currentContainerHeight);		
			
		pos.y = currentContainerHeight - pos.y - pos.height;

		g.drawTexture(t, pos.x, pos.y, 
				pos.x + pos.width, pos.y + pos.height, 0, 0, frameTextureWidth, frameTextureHeight);
	}
	
//	@Override
	protected void renderContent(Graphics g) {
		DriftDebug.assertQuantumRenderer();
		fxFpsCounter.tickStart();
		
		if (nextSwapChain != null) {
			try {
				if (swapChain != null) {
					if (curImage != null) {
//						System.err.println("Surface -> releasing curImage because swapchain recreation");
						swapChain.release(curImage);
						curImage = null;
					}
					swapChain.release();
				}
				nextSwapChain.allocate(g.getResourceFactory());
				swapChain = nextSwapChain;
				nextSwapChain = null;
			}
			catch (Exception e) {
				System.err.println("ERROR during swapchain recreation");
			}
		}
		
		if (swapChain != null) {
			if (swapChain.isDisposeScheduled()) {
				if (curImage != null) {
					swapChain.release(curImage);
					curImage = null;
				}
				Optional<FxImage<?>> next = swapChain.getNext();
				if (next.isPresent()) {
					swapChain.release(next.get());
				}
				swapChain.release();
				swapChain = null;
			}
		}
		
		BaseTransform saved = g.getTransformNoClone().copy();
		
		if (swapChain != null) {
			Optional<FxImage<?>> nextImage = swapChain.getNext();
			if (nextImage.isPresent()) {
				if (curImage != null) {
//					System.err.println("Surface -> releasing curImage");
					swapChain.release(curImage);
				}
				curImage = nextImage.get();
//				System.err.println("DriftFX Surface: Showing " + curImage.getData().number + " " + curImage.getTexture().getContentWidth() + " x " + curImage.getTexture().getContentHeight());
				
				curImage.update();
				
//				QuantumRendererHelper.syncExecute(() -> {
//					boolean isCtx = GL.isContextCurrent(QuantumRendererHelper.context);
//					if (!isCtx) throw new RuntimeException("QuantumRendererHelper has no context!");
//					curImage.update();
//				});
//				GL.glFinish();
				
//				GPUSync sync = QuantumRendererHelper.syncExecuteWithFence(curImage::update);
//				WaitSyncResult r = sync.ClientWaitSync(Duration.ZERO);
//				System.err.println("=> " + r);
//				sync.Delete();
				
			}
			
			if (curImage != null) {
				drawTexture(g, curImage.getTexture());
			}
		}
		
		// restore transform
		g.setTransform(saved);

		
		fxFpsCounter.tick();
		
		if (showFPS) {
			drawStats(g);
		}
		
	}
	
	public void updateSurface(SurfaceData surfaceData)  {
		Log.debug("[J] NativeSurface updateSurface("+surfaceData+")");
		if (isValid(surfaceData)) {
			this.surfaceData = surfaceData;
		}
	}
	
	private boolean isValid(SurfaceData data) {
		return true;
	}

	@Override
	protected boolean hasOverlappingContents() {
		return false;
	}


}
