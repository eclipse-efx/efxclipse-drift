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

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadFactory;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

import org.eclipse.fx.drift.DriftFXSurface;
import org.eclipse.fx.drift.internal.FrameData;
import org.eclipse.fx.drift.internal.GraphicsPipelineUtil;
import org.eclipse.fx.drift.internal.Log;
import org.eclipse.fx.drift.internal.NativeAPI;
import org.eclipse.fx.drift.internal.Placement;
import org.eclipse.fx.drift.internal.QuantumRendererHelper;
import org.eclipse.fx.drift.internal.SurfaceData;

import com.sun.javafx.sg.prism.NGNode;
import com.sun.javafx.tk.Toolkit;
import com.sun.prism.Graphics;
import com.sun.prism.PixelFormat;
import com.sun.prism.ResourceFactory;
import com.sun.prism.Texture;
import com.sun.prism.paint.Paint;

// Note: this implementation is against internal JavafX API
@SuppressWarnings("restriction")
public class NGDriftFXSurface extends NGNode {

	private long nativeSurfaceHandle;
	
	private SurfaceData surfaceData;
	
	private ResourceFactory resourceFactory;
	private DriftFXSurface node;
	
	private FrameData currentFrameData;
	private int currentFrameDataHash;
	private Texture currentTexture;
	
	public void present(FrameData frame) {
		FrameData oldData = currentFrameData;
		currentFrameData = frame;
		if (oldData != null) {
			dispose(oldData);
		}
	}
	
	private void dispose(FrameData frame) {
		NativeAPI.disposeFrameData(nativeSurfaceHandle, frame);
	}
	
	public NGDriftFXSurface(DriftFXSurface node, long nativeSurfaceId) {
		this.node = node;
		this.nativeSurfaceHandle = nativeSurfaceId;
		Log.debug("NGNativeSurface got handle: " + this.nativeSurfaceHandle);
		this.resourceFactory = GraphicsPipelineUtil.getResourceFactory();
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

	private Texture createTexture(Graphics g, FrameData data) {
		int w = currentFrameData.width;
		int h = currentFrameData.height;
		
		// create fx texture
		Texture texture = resourceFactory.createTexture(PixelFormat.BYTE_BGRA_PRE, Texture.Usage.DYNAMIC, Texture.WrapMode.CLAMP_NOT_NEEDED, w, h);
		if (texture == null) {
			Log.error("[J] Allocation of requested texture failed! This is FATAL! requested size was " + w + "x" + h);
			System.out.flush();
			System.exit(1);
		}
		texture.makePermanent();
		Log.debug("Created Texture @ " + texture.getContentWidth() + " x " + texture.getContentHeight());
		
		// to protect the javafx gl context we change threads here
		// recreate shared texture
		int result = QuantumRendererHelper.syncExecute(() -> GraphicsPipelineUtil.onTextureCreated(texture, currentFrameData));
		
		if (result == 0) {
			return texture;
		}
		else {
			System.err.println("Result was " + result);
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
	
	@Override
	protected void renderContent(Graphics g) {
		
		//renderPlaceholder(g);
				
		// TODO add signal & check it here!
		if (currentFrameData != null && currentFrameData.width != 0 && currentFrameData.height != 0) {
			int hash = currentFrameData.hashCode();
			if (hash != currentFrameDataHash) {
				currentFrameDataHash = hash;
				Texture texture = createTexture(g, currentFrameData);
				if (texture != null) {
					if (currentTexture != null) {
						currentTexture.dispose();
					}
					currentTexture = texture;
				}
				else {
					System.err.println("[J] [WARNING] Surface# \"+nativeSurfaceHandle+\": Could not recreate texture, keeping old one.");
				}
			}
		}
		
		// nothing to render!
		if (currentFrameData == null || currentFrameData.surfaceData == null) return;
		
		float frameWidth = currentFrameData.surfaceData.width;
		float frameHeight = currentFrameData.surfaceData.height;

		
		// TODO we need to transport the effective scale here, because the client could use any scale
		float renderScaleX = this.surfaceData.renderScaleX * this.surfaceData.userScaleX;
		float renderScaleY = this.surfaceData.renderScaleY * this.surfaceData.userScaleY;
		
		float frameScaleX = this.surfaceData.renderScaleX * this.surfaceData.userScaleX;
		float frameScaleY = this.surfaceData.renderScaleY * this.surfaceData.userScaleY;
		
		
		if (currentTexture != null) {
			float frameContainerWidth = currentFrameData.surfaceData.width;
			float frameContainerHeight = currentFrameData.surfaceData.height;
			
			Placement placement = toPlacement(currentFrameData.placementHint);
			
			float textureRatio = currentTexture.getContentWidth() / (float) currentTexture.getContentHeight();
			float frameRatio = currentFrameData.surfaceData.width / currentFrameData.surfaceData.height;
			
			Pos framePos = new Pos(0, frameContainerWidth, 0, frameContainerHeight);
			
			if (Math.abs(textureRatio - frameRatio) > 0.001f) {
				// aspect ratio is not matching, we need to do compute the position within the frame container
				framePos = computeContain(frameContainerWidth, frameContainerHeight, currentTexture.getContentWidth(), currentTexture.getContentHeight());
//				System.err.println("frame: " + frameContainerWidth + " / " + frameContainerHeight);
//				System.err.println("framePos = " + framePos.width + " / " + framePos.height);
			}
			
			
			int frameTextureWidth = currentTexture.getContentWidth();
			int frameTextureHeight = currentTexture.getContentHeight();
			
			float currentContainerWidth = surfaceData.width;
			float currentContainerHeight = surfaceData.height;	

			Pos pos = computePlacement(placement, currentContainerWidth, currentContainerHeight, framePos.width, framePos.height);

			// flip it vertically
			g.scale(1, -1);
			g.translate(0, -currentContainerHeight);		
				
			pos.y = currentContainerHeight - pos.y - pos.height;

			g.drawTexture(currentTexture, pos.x, pos.y, 
					pos.x + pos.width, pos.y + pos.height, 0, 0, frameTextureWidth, frameTextureHeight);
			
		}
		else {
			Log.debug("current Texture == null");
		}
		
		
	}
	
	public void updateSurface(SurfaceData surfaceData)  {
		Log.debug("[J] NativeSurface updateSurface("+surfaceData+")");
		if (isValid(surfaceData)) {
			this.surfaceData = surfaceData;
			CompletableFuture.runAsync(() -> {
				NativeAPI.updateSurface(nativeSurfaceHandle, surfaceData);
			});
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
