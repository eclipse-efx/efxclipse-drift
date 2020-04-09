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
package org.eclipse.fx.drift; 

import java.util.concurrent.atomic.AtomicReference;

import org.eclipse.fx.drift.impl.DriftDebug;
import org.eclipse.fx.drift.impl.NGDriftFXSurface;
import org.eclipse.fx.drift.internal.ScreenObserver;
import org.eclipse.fx.drift.internal.SurfaceData;
import org.eclipse.fx.drift.internal.frontend.FrontSwapChain;
import org.eclipse.fx.drift.internal.prism.Prism;

import com.sun.javafx.scene.DirtyBits;

import javafx.application.Platform;
import javafx.beans.property.DoubleProperty;
import javafx.beans.property.ReadOnlyDoubleProperty;
import javafx.beans.property.ReadOnlyDoubleWrapper;
import javafx.beans.property.SimpleDoubleProperty;
import javafx.scene.Node;

//Note: this implementation is against internal JavafX API
@SuppressWarnings({"restriction"})
public abstract class BaseDriftFXSurface extends Node {
	static {
		try {
			Prism.initialize();
		} catch (Throwable e) {
			e.printStackTrace();
		}
	}
	
	private AtomicReference<SurfaceData> surfaceData = new AtomicReference<>(null);
	
	private final ReadOnlyDoubleWrapper screenScaleFactor = new ReadOnlyDoubleWrapper(this, "screenScaleFactor", 1.0);
	private final DoubleProperty userScaleFactor = new SimpleDoubleProperty(this, "userScaleFactor", 1.0);
	
	private ScreenObserver screenObserver;
	
	public BaseDriftFXSurface() {
	}
	
	protected void init() {
		// observe current screen render factor
		screenObserver = new ScreenObserver(this);
		screenScaleFactor.bind(screenObserver.currentRenderScaleProperty());
		screenScaleFactor.addListener((x, o, n) -> updateSurfaceData());
	}
	
	
	public ReadOnlyDoubleProperty screenScaleFactorProperty() {
		return screenScaleFactor.getReadOnlyProperty();
	}
	
	public double getScreenScaleFactor() {
		return screenScaleFactorProperty().get();
	}
	
	public DoubleProperty userScaleFactorProperty() {
		return userScaleFactor;
	}
	
	public double getUserScaleFactor() {
		return userScaleFactorProperty().get();
	}
	
	public void setUserScaleFactor(double value) {
		userScaleFactorProperty().set(value);
	}

	@Override
	public double minHeight(double width) {
		return 0;
	}

	@Override
	public double minWidth(double height) {
		return 0;
	}
	
	@Override
	public double prefWidth(double height) {
		return 100;
	}
	
	@Override
	public double prefHeight(double width) {
		return 100;
	}
	
	@Override
	public double maxWidth(double height) {
		return Double.MAX_VALUE;
	}
	
	@Override
	public double maxHeight(double width) {
		return Double.MAX_VALUE;
	}

	private void widthChanged(double value) {
        if (value != _width) {
            _width = value;
            
            getHelper().geomChanged();
            getHelper().layoutBoundsChanged();
            updateSurfaceData();
            getHelper().markDirty(DirtyBits.NODE_GEOMETRY);
        }
	}
	
	private double _width;
	private ReadOnlyDoubleWrapper width;
	public final double getWidth() { return width == null ? _width : width.get(); }
	public final ReadOnlyDoubleProperty widthProperty() {
        if (width == null) {
            width = new ReadOnlyDoubleWrapper(_width) {
                @Override protected void invalidated() { widthChanged(get()); }
                @Override public Object getBean() { return BaseDriftFXSurface.this; }
                @Override public String getName() { return "width"; }
            };
        }
        return width.getReadOnlyProperty();
    }
	protected void setWidth(double value) {
        if(width == null) {
            widthChanged(value);
        } else {
            width.set(value);
        }
    }
	
	private void heightChanged(double value) {
	        if (_height != value) {
	            _height = value;
	            
	            getHelper().geomChanged();
	            getHelper().layoutBoundsChanged();
	            updateSurfaceData();
	            getHelper().markDirty(DirtyBits.NODE_GEOMETRY);
	        }
	    }
	private double _height;
	private ReadOnlyDoubleWrapper height;
	public final double getHeight() { return height == null ? _height : height.get(); }
	public final ReadOnlyDoubleProperty heightProperty() {
       if (height == null) {
           height = new ReadOnlyDoubleWrapper(_height) {
               @Override protected void invalidated() { heightChanged(get()); }
               @Override public Object getBean() { return BaseDriftFXSurface.this; }
               @Override public String getName() { return "height"; }
           };
       }
       return height.getReadOnlyProperty();
   }
   protected void setHeight(double value) {
       if (height == null) {
           heightChanged(value);
       } else {
           height.set(value);
       }
   }


   private SurfaceData computeSurfaceData() {
	   DriftDebug.outputThread();
	   return new SurfaceData(
			   (float) getWidth(), (float) getHeight(), 
			   (float) getScreenScaleFactor(), (float) getScreenScaleFactor(), 
			   (float) getUserScaleFactor(), (float) getUserScaleFactor(), 0);
	   
   }
   
   protected static interface InnerHelper {
	   NGDriftFXSurface getPeer();
	   boolean isDirty(DirtyBits bit);
	   void markDirty(DirtyBits bit);
	   void geomChanged();
	   void layoutBoundsChanged();
	   void beginPeerAccess();
	   void endPeerAccess();
   }
   protected abstract InnerHelper getHelper();
   
   public void drift_updatePeer() {
	   NGDriftFXSurface peer = getHelper().getPeer();
	   
	   if (getHelper().isDirty(DirtyBits.NODE_GEOMETRY)) {
			SurfaceData data = surfaceData.get();
			peer.updateSurface(data);
			peer.markDirty();
	   }
	   
	   if (getHelper().isDirty(DirtyBits.NODE_CONTENTS)) {
		   FrontSwapChain swapChain = swapChainBuf.getAndSet(null);
			if (swapChain != null) {
				peer.setSwapChain(swapChain);
			}
			peer.markDirty();
	   }
   }
   
   @Override
	public boolean isResizable() {
		return true;
	}
   
   @Override
	public void resize(double width, double height) {
	   	DriftDebug.outputThread();
		setWidth(width);
		setHeight(height);
		updateSurfaceData();
	}
   
   private void updateSurfaceData() {
	   DriftDebug.outputThread();
	   SurfaceData data = computeSurfaceData();
	   if (!data.equals(surfaceData.get())) {
		   surfaceData.set(data);
		   getHelper().markDirty(DirtyBits.NODE_GEOMETRY);
	   }
   }
   
	public void dirty() {
		DriftDebug.outputThread();
		Platform.runLater(() ->  getHelper().markDirty(DirtyBits.NODE_CONTENTS));
	}

	private AtomicReference<FrontSwapChain> swapChainBuf = new AtomicReference<>();
	
	public void setSwapChain(FrontSwapChain swapChain) {
		DriftDebug.outputThread();
		FrontSwapChain leftover = swapChainBuf.getAndSet(swapChain);
		if (leftover != null) System.err.println("Leftover swapchain!!! This is not good! " + leftover);
		Platform.runLater(() ->  getHelper().markDirty(DirtyBits.NODE_CONTENTS));
	}
	
	
	
	
	// Internal Type access
	
	@SuppressWarnings("restriction")
	private static void drift_addShutdownHook(Runnable hook) {
		com.sun.javafx.tk.Toolkit.getToolkit().addShutdownHook(hook);
	}

	// JDK-Version specific methods
	
	@SuppressWarnings("restriction")
	protected com.sun.javafx.geom.BaseBounds drift_computeGeomBounds(com.sun.javafx.geom.BaseBounds bounds, com.sun.javafx.geom.transform.BaseTransform tx) {
		com.sun.javafx.geom.BaseBounds rv = new com.sun.javafx.geom.RectBounds(0f, 0f, (float) getWidth(), (float) getHeight());
		rv = tx.transform(rv, rv);
		return rv;
	}

	protected boolean drift_computeContains(double localX, double localY) {
		double w = getWidth();
		double h = getHeight();
		return (w > 0 && h > 0 && localX >= 0 && localY >= 0 && localX < w && localY < h);
	}
	
	@SuppressWarnings("restriction")
	protected com.sun.javafx.sg.prism.NGNode drift_createPeer() {
		NGDriftFXSurface peer = new NGDriftFXSurface(this);
		return peer;
	}
	
}
