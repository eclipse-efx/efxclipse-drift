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
import java.util.Queue;
import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.ConcurrentLinkedQueue;
import java.util.concurrent.Executor;

import org.eclipse.fx.drift.DriftFXSurface2;
import org.eclipse.fx.drift.internal.FPSCounter;
import org.eclipse.fx.drift.internal.FPSCounter2;
import org.eclipse.fx.drift.internal.Frame;
import org.eclipse.fx.drift.internal.FrameProfiler;
import org.eclipse.fx.drift.internal.GraphicsPipelineUtil;
import org.eclipse.fx.drift.internal.Log;
import org.eclipse.fx.drift.internal.NativeAPI;
import org.eclipse.fx.drift.internal.Placement;
import org.eclipse.fx.drift.internal.QuantumRendererHelper;
import org.eclipse.fx.drift.internal.QuantumRendererHelper.WithFence;
import org.eclipse.fx.drift.internal.SurfaceData;
import org.eclipse.fx.drift.internal.SwapChainImage;
import org.eclipse.fx.drift.internal.frontend.FrontSwapChain;
import org.eclipse.fx.drift.internal.frontend.FxImage;
import org.eclipse.fx.drift.internal.frontend.SimpleFrontSwapChain;

import com.sun.javafx.font.FontStrike;
import com.sun.javafx.font.PGFont;
import com.sun.javafx.geom.Point2D;
import com.sun.javafx.geom.transform.BaseTransform;
import com.sun.javafx.scene.text.GlyphList;
import com.sun.javafx.scene.text.TextLayout;
import com.sun.javafx.scene.text.TextLayoutFactory;
import com.sun.javafx.sg.prism.NGNode;
import com.sun.javafx.tk.Toolkit;
import com.sun.prism.Graphics;
import com.sun.prism.PixelFormat;
import com.sun.prism.ResourceFactory;
import com.sun.prism.Texture;
import com.sun.prism.paint.Color;
import com.sun.prism.paint.Paint;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Platform;
import javafx.beans.property.ReadOnlyStringWrapper;
import javafx.scene.text.Font;
import javafx.scene.text.TextAlignment;
import javafx.util.Duration;
import javafx.event.*;

// Note: this implementation is against internal JavafX API
@SuppressWarnings("restriction")
public class NGDriftFXSurface2 extends NGNode {

	private final ReadOnlyStringWrapper stats;
	
	private long nativeSurfaceHandle;
	
	private SurfaceData surfaceData;
	
	private ResourceFactory resourceFactory;
	private DriftFXSurface2 node;
	
	
	private FrontSwapChain nextSwapChain;
	private FrontSwapChain swapChain;
	
	private Texture currentTexture;
	
	
	private int renderedHash;
	
	private Texture renderedTexture;
	
	private SwapChainImage renderedImage;
	
	private Queue<Frame> nextFrame = new ConcurrentLinkedQueue<>();
	
	private final static boolean showFPS = Boolean.getBoolean("driftfx.showfps");
	FPSCounter renderContent = new FPSCounter();
	FPSCounter renderTexture = new FPSCounter();
	
	FPSCounter2 surfaceCounter = new FPSCounter2(100);
	
	public void present(Frame frame) {
		nextFrame.offer(frame);
	}
	
	public void setSwapChain(FrontSwapChain swapChain) {
		this.nextSwapChain = swapChain;
	}
	
	private static boolean profile = Boolean.getBoolean("driftfx.profile");
	
	private void dispose(Frame frame) {
		if (profile) FrameProfiler.addFrame(frame);
		NativeAPI.disposeFrame(frame);
	}
	
	public NGDriftFXSurface2(DriftFXSurface2 node, long nativeSurfaceId, ReadOnlyStringWrapper stats) {
		this.stats = stats;
		this.node = node;
		this.nativeSurfaceHandle = nativeSurfaceId;
		Log.debug("NGNativeSurface got handle: " + this.nativeSurfaceHandle);
		this.resourceFactory = GraphicsPipelineUtil.getResourceFactory();
		
//		Timer t = new Timer();
//		TimerTask historyTick = new TimerTask() {
//			@Override
//			public void run() {
//				surfaceCounter.historyTick();
//				if (swapChain != null) ((SimpleFrontSwapChain)swapChain).fpsCounter.historyTick();
//			}
//		};
//		t.scheduleAtFixedRate(historyTick, 0, 100);
		Timeline historyTick = new Timeline(new KeyFrame(Duration.millis(100), new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent arg0) {
				surfaceCounter.historyTick();
				if (swapChain != null) ((SimpleFrontSwapChain)swapChain).fpsCounter.historyTick();
			}
		}));
		historyTick.setCycleCount(Timeline.INDEFINITE);
		historyTick.play();
			
	}
	
	public void destroy() {
		NativeAPI.destroyNativeSurface(this.nativeSurfaceHandle);
	}
	
	@Override
	protected void finalize() throws Throwable {
		super.finalize();
		destroy();
	}
	
	// TODO output some kind of placeholder info
	private void renderPlaceholder(Graphics g)
	{
		float width = (float) surfaceData.width;
		float height = (float) surfaceData.height;
		
//		Paint white = (Paint)Toolkit.getPaintAccessor().getPlatformPaint(javafx.scene.paint.Color.WHITE);
//		g.setPaint(white);
//		g.fillQuad(0, 0, width, height);

		Paint red = (Paint)Toolkit.getPaintAccessor().getPlatformPaint(javafx.scene.paint.Color.RED);
		g.setPaint(red);
		g.drawRect(0, 0, width - 1, height - 1);
	}

	private Texture createTexture(Graphics g, Frame frame) {
		if (showFPS) renderTexture.frame();
		frame.begin("NGDriftFXSurface#renderTexture");

		int w = frame.textureWidth;
		int h = frame.textureHeight;
		
		Texture texture = resourceFactory.createTexture(PixelFormat.BYTE_BGRA_PRE, Texture.Usage.DYNAMIC, Texture.WrapMode.CLAMP_NOT_NEEDED, w, h);
		if (texture == null) {
			Log.error("[J] Allocation of requested texture failed! This is FATAL! requested size was " + w + "x" + h);
			return null;
		}
		texture.makePermanent();
		Log.debug("Created Texture @ " + texture.getContentWidth() + " x " + texture.getContentHeight());
		
		//int result = QuantumRendererHelper.syncExecute(() -> GraphicsPipelineUtil.onTextureCreated(texture, frame));
		
		WithFence<Integer> exec = QuantumRendererHelper.syncExecuteWithFence(() -> GraphicsPipelineUtil.onTextureCreated(texture, frame) );
		
		//exec.getFence().ClientWaitSync(Duration.ZERO);
		exec.getFence().WaitSync();
		exec.getFence().Delete();
		
		int result = exec.getResult();
		
		frame.end("NGDriftFXSurface#renderTexture");
		if (result == 0) {
			// once the texture is ready we want to dispose the frame
			dispose(frame);
			return texture;
		}
		else {
			Log.error("[J] Could not connect the texture to actual data.");
			texture.dispose();
			return null;
		}
	}
	
	
	private int toPixels(double value) {
		return (int) Math.ceil(value);
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
		String stats0;
//		if (currentFrame != null) {
//			stats0 = String.format("%d.%d (%d x %d)", nativeSurfaceHandle, currentFrame.frameId, currentFrame.textureWidth, currentFrame.textureHeight);
//		}
//		else {
			stats0 = "" + nativeSurfaceHandle;
//		}
			if (swapChain != null)
		stats0 = swapChain.getSize().x + "x" + swapChain.getSize().y;
		String stats = String.format("%s\nfx:  %5.1ffps\ntex: %5.1ffps", stats0, renderContent.avgFps(), renderTexture.avgFps());
		Platform.runLater(() -> {
			this.stats.set(stats);
		});
		
		if (swapChain != null) {
			String info = "Texture: " + swapChain.getSize().x + "x" + swapChain.getSize().y;
			info += "\nTransfer: MainMemory (TODO)";
			writeText(g, -150, 0, 12, info, Color.RED);
		}
		{
			int count = 30;
			float x = 0;
			float y = 0;
			float width = 150;
			float height = 40;
			float padding = 2;
			
			g.setPaint(new Color(1,0,0,0.3f));
			g.fillRect(x, y, width, height);
			
			float lineAvail = width / count;
			float lineWidth = lineAvail * 8/10f;
			
			for (int i = 0; i < count; i++) {
				double fps = surfaceCounter.fpsHistory[i];
				int norm = (int) Math.round(Math.min(height, fps / 60 * height));
				g.fillRect(x + width - i * lineAvail - lineAvail, y + height - norm, lineWidth, norm);
			}
			writeText(g, x, y, 12, String.format("JavaFX - %5.1ffps", surfaceCounter.fps), new Color(1, 0, 0, 1));
		}
		if (swapChain != null) {
			FPSCounter2 c = ((SimpleFrontSwapChain)swapChain).fpsCounter;
			int count = 30;
			float x = 0;
			float y = 40;
			float width = 150;
			float height = 40;
			float padding = 2;
			
			g.setPaint(new Color(0,1,0,0.3f));
			g.fillRect(x, y, width, height);
			
			float lineAvail = width / count;
			float lineWidth = lineAvail * 8/10f;
			
			for (int i = 0; i < count; i++) {
				double fps = c.fpsHistory[i];
				int norm = (int) Math.round(Math.min(height, fps / 100 * height));
				g.fillRect(x + width - i * lineAvail - lineAvail, y + height - norm, lineWidth, norm);
			}
			writeText(g, x, y, 12, String.format("Renderer - %5.1ffps", c.fps), new Color(0, 1, 0, 1));
		}

	}
	private void writeText(Graphics g, float x, float y, int fontSize, String text, Color color) {
		Font font = Font.font(fontSize);
		PGFont pgFont = (PGFont) font.impl_getNativeFont();
		
		FontStrike strike = pgFont.getStrike(BaseTransform.IDENTITY_TRANSFORM);
		
		TextLayoutFactory factory = Toolkit.getToolkit().getTextLayoutFactory();
		TextLayout layout = factory.createLayout();
		
		layout.setContent(text, pgFont);
		layout.setAlignment(TextAlignment.LEFT.ordinal());
		layout.setLineSpacing(0);
		layout.setWrapWidth(0);
		
		GlyphList[] runs = layout.getRuns();
		
		float layoutX = x;
		float layoutY = -pgFont.getSize() - y;
		
		g.setPaint(color);
		for (int i = 0; i < runs.length; i++) {
			GlyphList run = runs[i];
			Point2D pt = run.getLocation();
            float gx = pt.x- layoutX;
            float gy = pt.y - layoutY;
			BaseTransform t = BaseTransform.getTranslateInstance(gx, gy);
			g.fill(strike.getOutline(run,  t));
		}
	}
	
	private void drawTexture(Graphics g, Frame frame, Texture t) {
		float frameContainerWidth = frame.surfaceData.width;
		float frameContainerHeight = frame.surfaceData.height;
		
		Placement placement = toPlacement(frame.presentationHint);
		
		float textureRatio = t.getContentWidth() / (float) t.getContentHeight();
		float frameRatio = frame.surfaceData.width / frame.surfaceData.height;
		
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
	
	Executor quantumHelper;
	
	void initQuantumHelper() {
		
	}
	
	FxImage curImage;
	
	@Override
	protected void renderContent(Graphics g) {
		DriftDebug.assertQuantumRenderer();
		surfaceCounter.tickStart();
		if (showFPS) renderContent.frame();
		
		if (nextSwapChain != null) {
			if (swapChain != null) {
				if (curImage != null) {
					System.err.println("Surface -> releasing curImage because swapchain recreation");
					swapChain.release(curImage);
					curImage = null;
				}
				swapChain.release();
			}
			nextSwapChain.allocate(g.getResourceFactory());
			swapChain = nextSwapChain;
			nextSwapChain = null;
		}
		
		
		BaseTransform saved = g.getTransformNoClone().copy();
		
		if (swapChain != null) {
			Optional<FxImage> nextImage = swapChain.getNext();
			if (nextImage.isPresent()) {
				if (curImage != null) {
					System.err.println("Surface -> releasing curImage");
					swapChain.release(curImage);
				}
				curImage = nextImage.get();
				System.err.println("DriftFX Surface: Showing " + curImage.getData().number + " " + curImage.getTexture().getContentWidth() + " x " + curImage.getTexture().getContentHeight());
				
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
				
				if (showFPS) renderTexture.frame();
			}
			
			if (curImage != null) {
				drawTexture(g, curImage.getTexture());
			}
		}
		
		g.setTransform(saved);

		
		surfaceCounter.tick();
		
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
