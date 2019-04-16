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
import org.eclipse.fx.drift.internal.GraphicsPipelineUtil;
import org.eclipse.fx.drift.internal.JNINativeSurface.FrameData;
import org.eclipse.fx.drift.internal.NativeAPI;

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
	
	private float width;
	private float height;
	
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
		System.out.println("[J] NGNativeSurface got handle: " + this.nativeSurfaceHandle);
		
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
		Paint white = (Paint)Toolkit.getPaintAccessor().getPlatformPaint(javafx.scene.paint.Color.WHITE);
		g.setPaint(white);
		g.fillQuad(0, 0, this.width, this.height);

		Paint red = (Paint)Toolkit.getPaintAccessor().getPlatformPaint(javafx.scene.paint.Color.RED);
		g.setPaint(red);
		g.drawRect(0, 0, this.width - 1, this.height - 1);
	}
	
	private int getWidth() {
		return Math.max(1, (int) Math.ceil(width));
	}
	private int getHeight() {
		return Math.max(1, (int) Math.ceil(height));
	}

	private Texture createTexture(Graphics g, FrameData data) {
		int w = currentFrameData.width;
		int h = currentFrameData.height;
		
		// create fx texture
		Texture texture = resourceFactory.createTexture(PixelFormat.BYTE_BGRA_PRE, Texture.Usage.DYNAMIC, Texture.WrapMode.CLAMP_NOT_NEEDED, w, h);
		if (texture == null) {
			System.err.println("[J] Allocation of requested texture failed! This is FATAL! requested size was " + w + "x" + h);
			System.err.flush();
			System.exit(1);
		}
		texture.makePermanent();
		
		// to protect the javafx gl context we change threads here
		ReentrantLock lock = new ReentrantLock();
		Condition done = lock.newCondition();
		lock.lock();
		fixer.execute(() -> {
			lock.lock();
			GraphicsPipelineUtil.onTextureCreated(texture, currentFrameData);
			done.signal();
			lock.unlock();
		});
		try {
			done.await();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		
		
		// recreate shared texture
		//int result = GraphicsPipelineUtil.onTextureCreated(texture, currentFrameData);
		int result = 0;
		
		if (result == 0) {
			return texture;
		}
		else {
			System.err.println("Result was " + result);
			texture.dispose();
			return null;
		}
	}
	
	static Executor fixer = Executors.newSingleThreadExecutor(new ThreadFactory() {
		@Override
		public Thread newThread(Runnable r) {
			Thread t = new Thread(r);
			t.setDaemon(true);
			return t;
		}
	});
	
	@Override
	protected void renderContent(Graphics g) {
		int width = getWidth();
		int height = getHeight();
	
		// flip it vertically
		g.scale(1, -1);
		g.translate(0, -height);
		
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
//		renderPlaceholder(g);
		if (currentTexture != null) {
			
			// TODO support for different positioning algorithms
			// COVER, CONTAIN, 
			// TOP_LEFT,    TOP_CENTER,    TOP_RIGHT,
			// CENTER_LEFT, CENTER,        CENTER_RIGHT,
			// BOTTOM_LEFT, BOTTOM_CENTER, BOTTOM_RIGHT
			
			int textureWidth = currentTexture.getContentWidth();
			int textureHeight = currentTexture.getContentHeight();
			
			
			int containerWidth = width;
			int containerHeight = height;
			
			
			float textureRatio = textureWidth / (float) textureHeight;
			float containerRatio = containerWidth / (float) containerHeight;
			
			int finalWidth = textureWidth;
			int finalHeight = textureHeight;
			
			// cover algorithm
			//if (containerRatio > textureRatio) {
			//	finalHeight = containerHeight;
			//	finalWidth = Math.round(containerHeight / textureRatio);
			//}
			//else {
			//	finalWidth = containerWidth;
			//	finalHeight = Math.round(containerWidth * textureRatio);
			//}
			
			// contain alogrithm
			if (textureRatio <= containerRatio) {
				finalWidth = Math.round(containerHeight * textureRatio);
				finalHeight = containerHeight;
			}
			else {
				finalWidth = containerWidth;
				finalHeight = Math.round(containerWidth / textureRatio);
			}
			
			
			// just center
			
			int x = 0;
			int y = 0;
			
				x = Math.round((width - finalWidth) / 2f);
				y = Math.round((height - finalHeight) / 2f);
		
			System.out.println("[J] [Info ] Surface# "+nativeSurfaceHandle+": Drawing texture " + Long.toHexString(GraphicsPipelineUtil.getTextureHandle(currentTexture)));
				
			//System.err.println("## " + textureWidth + "x" + textureHeight + " -> " + x + ", " + y + " @ " + finalWidth + "x" + finalHeight);
			g.drawTexture(currentTexture, x, y, x + finalWidth, y + finalHeight, 0, 0, textureWidth, textureHeight);
			
			
		}
		else {
			System.err.println("[J][Info ] current Texture == null");
		}
		
		
	}
	
	public void updateSize(float width, float height)  {
		//System.out.println("[J] NativeSurface updateSize " + width + " " + height);
		if (width != -1) this.width = width;
		if (height != -1) this.height = height;
		CompletableFuture.runAsync(() ->
		NativeAPI.updateSize(nativeSurfaceHandle, getWidth(), getHeight()));
	}
	
	

	@Override
	protected boolean hasOverlappingContents() {
		return false;
	}

}
