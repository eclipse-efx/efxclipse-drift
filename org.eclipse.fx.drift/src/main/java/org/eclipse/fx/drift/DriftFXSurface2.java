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

import com.sun.javafx.geom.BaseBounds;
import com.sun.javafx.geom.RectBounds;
import com.sun.javafx.geom.transform.BaseTransform;
import com.sun.javafx.jmx.MXNodeAlgorithm;
import com.sun.javafx.jmx.MXNodeAlgorithmContext;
import com.sun.javafx.scene.DirtyBits;
import com.sun.javafx.sg.prism.NGNode;

import org.eclipse.fx.drift.impl.DriftDebug;
import org.eclipse.fx.drift.impl.NGDriftFXSurface2;
import org.eclipse.fx.drift.internal.ScreenObserver;
import org.eclipse.fx.drift.internal.SurfaceData;
import org.eclipse.fx.drift.internal.frontend.FrontSwapChain;

import javafx.application.Platform;
import javafx.beans.property.DoubleProperty;
import javafx.beans.property.ReadOnlyDoubleProperty;
import javafx.beans.property.ReadOnlyDoubleWrapper;
import javafx.beans.property.ReadOnlyStringProperty;
import javafx.beans.property.ReadOnlyStringWrapper;
import javafx.beans.property.SimpleDoubleProperty;
import javafx.scene.Node;

//Note: this implementation is against internal JavafX API
@SuppressWarnings({"restriction", "deprecation"})
public class DriftFXSurface2 extends Node {
	
	
	private AtomicReference<SurfaceData> surfaceData = new AtomicReference<>(null);
	
	private final ReadOnlyDoubleWrapper screenScaleFactor = new ReadOnlyDoubleWrapper(this, "screenScaleFactor", 1.0);
	private final DoubleProperty userScaleFactor = new SimpleDoubleProperty(this, "userScaleFactor", 1.0);
	
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
	
	public long getNativeSurfaceHandle() {
		return nativeSurfaceId;
	}
	
	private long nativeSurfaceId;
	
	private ScreenObserver screenObserver = new ScreenObserver(this);
	
	
	private ReadOnlyStringWrapper stats = new ReadOnlyStringWrapper(this, "stats", "");
	
	public ReadOnlyStringProperty statsProperty() {
		return stats;
	}
	
	public DriftFXSurface2() {

		
		// observe current screen render factor
		screenScaleFactor.bind(screenObserver.currentRenderScaleProperty());
		screenScaleFactor.addListener((x, o, n) -> updateSurfaceData());
		
		
	}

	@Override
	protected NGNode impl_createPeer() {
		DriftDebug.outputThread();
		NGDriftFXSurface2 peer = new NGDriftFXSurface2(this, nativeSurfaceId, stats);
		return peer;
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

	
	@Override
	public BaseBounds impl_computeGeomBounds(BaseBounds bounds, BaseTransform tx) {
		DriftDebug.outputThread();
		bounds = new RectBounds(0f, 0f, (float) getWidth(), (float) getHeight());
		bounds = tx.transform(bounds, bounds);
		return bounds;
	}

	@Override
	protected boolean impl_computeContains(double localX, double localY) {
		double w = getWidth();
		double h = getHeight();
		return (w > 0 && h > 0 && localX >= 0 && localY >= 0 && localX < w && localY < h);
	}

	@Override
	public Object impl_processMXNode(MXNodeAlgorithm alg, MXNodeAlgorithmContext ctx) {
		throw new UnsupportedOperationException("Not supported yet.");
	}

	private void widthChanged(double value) {
        if (value != _width) {
            _width = value;
            
            impl_layoutBoundsChanged();
            impl_geomChanged();
            updateSurfaceData();
            impl_markDirty(DirtyBits.NODE_GEOMETRY);
        }
	}
	
	private double _width;
	private ReadOnlyDoubleWrapper width;
	public final double getWidth() { return width == null ? _width : width.get(); }
	public final ReadOnlyDoubleProperty widthProperty() {
        if (width == null) {
            width = new ReadOnlyDoubleWrapper(_width) {
                @Override protected void invalidated() { widthChanged(get()); }
                @Override public Object getBean() { return DriftFXSurface2.this; }
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
	            
	            impl_geomChanged();
	            impl_layoutBoundsChanged();
	            updateSurfaceData();
	            impl_markDirty(DirtyBits.NODE_GEOMETRY);
	        }
	    }
	private double _height;
	private ReadOnlyDoubleWrapper height;
	public final double getHeight() { return height == null ? _height : height.get(); }
	public final ReadOnlyDoubleProperty heightProperty() {
       if (height == null) {
           height = new ReadOnlyDoubleWrapper(_height) {
               @Override protected void invalidated() { heightChanged(get()); }
               @Override public Object getBean() { return DriftFXSurface2.this; }
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
   
	@Deprecated
	@Override
	public void impl_updatePeer() {
		DriftDebug.outputThread();
		super.impl_updatePeer();
		NGDriftFXSurface2 peer = impl_getPeer();
		
		if (impl_isDirty(DirtyBits.NODE_GEOMETRY)) {
			SurfaceData data = surfaceData.get();
			peer.updateSurface(data);
			peer.markDirty();
		}
		
		if (impl_isDirty(DirtyBits.NODE_CONTENTS)) {
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
		   impl_markDirty(DirtyBits.NODE_GEOMETRY);
	   }
   }
   
   @Override
	public void relocate(double x, double y) {
	   DriftDebug.outputThread();
		super.relocate(x, y);
	}
   
	public void dirty() {
		DriftDebug.outputThread();
		Platform.runLater(() ->  impl_markDirty(DirtyBits.NODE_CONTENTS));
	}
	
	@Override
	protected void impl_markDirty(DirtyBits dirtyBit) {
		DriftDebug.assertJavaFXApplicationThread();
		super.impl_markDirty(dirtyBit);
	}

	private AtomicReference<FrontSwapChain> swapChainBuf = new AtomicReference<>();
	
	public void setSwapChain(FrontSwapChain swapChain) {
		DriftDebug.outputThread();
		FrontSwapChain leftover = swapChainBuf.getAndSet(swapChain);
		System.err.println("Leftover swapchain!!! This is not good! " + leftover);
		Platform.runLater(() ->  impl_markDirty(DirtyBits.NODE_CONTENTS));
	}
	
}
