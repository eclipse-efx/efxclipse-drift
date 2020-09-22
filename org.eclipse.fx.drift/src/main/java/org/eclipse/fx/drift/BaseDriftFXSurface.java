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
package org.eclipse.fx.drift; 

import java.util.Arrays;
import java.util.List;
import java.util.concurrent.atomic.AtomicReference;

import org.eclipse.fx.drift.impl.DriftDebug;
import org.eclipse.fx.drift.impl.NGDriftFXSurface;
import org.eclipse.fx.drift.internal.DriftFX;
import org.eclipse.fx.drift.internal.DriftLogger;
import org.eclipse.fx.drift.internal.ScreenObserver;
import org.eclipse.fx.drift.internal.SurfaceData;
import org.eclipse.fx.drift.internal.frontend.FrontSwapChain;
import org.eclipse.fx.drift.internal.prism.Prism;

import com.sun.javafx.scene.DirtyBits;

import javafx.application.Platform;
import javafx.beans.property.DoubleProperty;
import javafx.beans.property.ObjectProperty;
import javafx.beans.property.ReadOnlyDoubleProperty;
import javafx.beans.property.ReadOnlyDoubleWrapper;
import javafx.beans.property.SimpleDoubleProperty;
import javafx.beans.property.SimpleObjectProperty;
import javafx.css.CssMetaData;
import javafx.css.StyleConverter;
import javafx.css.Styleable;
import javafx.css.StyleableDoubleProperty;
import javafx.css.StyleableProperty;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.layout.Region;

//Note: this implementation is against internal JavafX API
@SuppressWarnings({"restriction"})
public abstract class BaseDriftFXSurface extends Node {
	private static final DriftLogger LOGGER = DriftFX.createLogger(BaseDriftFXSurface.class);
	
	static {
		try {
			Prism.initialize();
		} catch (Throwable e) {
			LOGGER.error(() -> "Error initializing Prism!", e);
		}
	}
	
	private AtomicReference<SurfaceData> surfaceData = new AtomicReference<>(null);
	
	private final ReadOnlyDoubleWrapper screenScaleFactor = new ReadOnlyDoubleWrapper(this, "screenScaleFactor", 1.0);
	private final DoubleProperty userScaleFactor = new SimpleDoubleProperty(this, "userScaleFactor", 1.0);
	
	private final ObjectProperty<Placement> placementStrategy = new SimpleObjectProperty<>(this, "placementStrategy", Placement.CONTAIN);
	
	private ScreenObserver screenObserver;
	
	public BaseDriftFXSurface() {
	}
	
	protected void init() {
		// observe current screen render factor
		screenObserver = new ScreenObserver(this);
		screenScaleFactor.bind(screenObserver.currentRenderScaleProperty());
		screenScaleFactor.addListener((x, o, n) -> updateSurfaceData());
		placementStrategy.addListener((x, o, n) -> updateSurfaceData());
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
        final double override = getMinHeight();
        if (override == Region.USE_COMPUTED_SIZE) {
            return super.minHeight(width);
        } else if (override == Region.USE_PREF_SIZE) {
            return prefHeight(width);
        }
        return Double.isNaN(override) || override < 0 ? 0 : override;
	}

	@Override
	public double minWidth(double height) {
        final double override = getMinWidth();
        if (override == Region.USE_COMPUTED_SIZE) {
            return super.minWidth(height);
        } else if (override == Region.USE_PREF_SIZE) {
            return prefWidth(height);
        }
        return Double.isNaN(override) || override < 0 ? 0 : override;
	}
	
	@Override
	public double prefWidth(double height) {
        final double override = getPrefWidth();
        if (override == Region.USE_COMPUTED_SIZE) {
            return super.prefWidth(height);
        }
        return Double.isNaN(override) || override < 0 ? 0 : override;
	}
	
	@Override
	public double prefHeight(double width) {
        final double override = getPrefHeight();
        if (override == Region.USE_COMPUTED_SIZE) {
            return super.prefHeight(width);
        }
        return Double.isNaN(override) || override < 0 ? 0 : override;
	}
	
	@Override
	public double maxWidth(double height) {
        final double override = getMaxWidth();
        if (override == Region.USE_COMPUTED_SIZE) {
            return computeMaxWidth(height);
        } else if (override == Region.USE_PREF_SIZE) {
            return prefWidth(height);
        }
        return Double.isNaN(override) || override < 0 ? 0 : override;
	}
	
	@Override
	public double maxHeight(double width) {
        final double override = getMaxHeight();
        if (override == Region.USE_COMPUTED_SIZE) {
            return computeMaxHeight(width);
        } else if (override == Region.USE_PREF_SIZE) {
            return prefHeight(width);
        }
        return Double.isNaN(override) || override < 0 ? 0 : override;
	}
	
    protected double computeMaxWidth(double height) {
        return Double.MAX_VALUE;
    }
	
    protected double computeMaxHeight(double width) {
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
			   (float) getUserScaleFactor(), (float) getUserScaleFactor(), 0, getPlacementStrategy());
	   
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
		if (leftover != null) LOGGER.warn(() -> "Leftover swapchain!!! This is not good! " + leftover);
		Platform.runLater(() ->  getHelper().markDirty(DirtyBits.NODE_CONTENTS));
	}
	
	
	// Internal Type access
	private static void drift_addShutdownHook(Runnable hook) {
		com.sun.javafx.tk.Toolkit.getToolkit().addShutdownHook(hook);
	}

	// JDK-Version specific methods
	
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
	
	protected com.sun.javafx.sg.prism.NGNode drift_createPeer() {
		NGDriftFXSurface peer = new NGDriftFXSurface();
		return peer;
	}

	public final ObjectProperty<Placement> placementStrategyProperty() {
		return this.placementStrategy;
	}
	

	public final Placement getPlacementStrategy() {
		return this.placementStrategyProperty().get();
	}
	

	public final void setPlacementStrategy(final Placement placementStrategy) {
		this.placementStrategyProperty().set(placementStrategy);
	}
	
	
	// min/pref/max from Region
	
    /**
     * This class is reused for the min, pref, and max properties since
     * they all performed the same function (to call requestParentLayout).
     */
    private final class MinPrefMaxProperty extends StyleableDoubleProperty {
        private final String name;
        private final CssMetaData<? extends Styleable, Number> cssMetaData;

        MinPrefMaxProperty(String name, double initialValue, CssMetaData<? extends Styleable, Number> cssMetaData) {
            super(initialValue);
            this.name = name;
            this.cssMetaData = cssMetaData;
        }

        @Override public void invalidated() { requestParentLayout(); }
        @Override public Object getBean() { return BaseDriftFXSurface.this; }
        @Override public String getName() { return name; }

        @Override
        public CssMetaData<? extends Styleable, Number> getCssMetaData() {
            return cssMetaData;
        }
    }

    /**
     * Property for overriding the region's computed minimum width.
     * This should only be set if the region's internally computed minimum width
     * doesn't meet the application's layout needs.
     * <p>
     * Defaults to the <code>USE_COMPUTED_SIZE</code> flag, which means that
     * <code>minWidth(forHeight)</code> will return the region's internally
     * computed minimum width.
     * <p>
     * Setting this value to the <code>USE_PREF_SIZE</code> flag will cause
     * <code>minWidth(forHeight)</code> to return the region's preferred width,
     * enabling applications to easily restrict the resizability of the region.
     */
    private DoubleProperty minWidth;
    private double _minWidth = Region.USE_COMPUTED_SIZE;
    public final void setMinWidth(double value) {
        if (minWidth == null) {
            _minWidth = value;
            requestParentLayout();
        } else {
            minWidth.set(value);
        }
    }
    public final double getMinWidth() { return minWidth == null ? _minWidth : minWidth.get(); }
    public final DoubleProperty minWidthProperty() {
        if (minWidth == null) minWidth = new MinPrefMaxProperty("minWidth", _minWidth, MIN_WIDTH);
        return minWidth;
    }

    /**
     * Property for overriding the region's computed minimum height.
     * This should only be set if the region's internally computed minimum height
     * doesn't meet the application's layout needs.
     * <p>
     * Defaults to the <code>USE_COMPUTED_SIZE</code> flag, which means that
     * <code>minHeight(forWidth)</code> will return the region's internally
     * computed minimum height.
     * <p>
     * Setting this value to the <code>USE_PREF_SIZE</code> flag will cause
     * <code>minHeight(forWidth)</code> to return the region's preferred height,
     * enabling applications to easily restrict the resizability of the region.
     *
     */
    private DoubleProperty minHeight;
    private double _minHeight = Region.USE_COMPUTED_SIZE;
    public final void setMinHeight(double value) {
        if (minHeight == null) {
            _minHeight = value;
            requestParentLayout();
        } else {
            minHeight.set(value);
        }
    }
    public final double getMinHeight() { return minHeight == null ? _minHeight : minHeight.get(); }
    public final DoubleProperty minHeightProperty() {
        if (minHeight == null) minHeight = new MinPrefMaxProperty("minHeight", _minHeight, MIN_HEIGHT);
        return minHeight;
    }

    /**
     * Convenience method for overriding the region's computed minimum width and height.
     * This should only be called if the region's internally computed minimum size
     * doesn't meet the application's layout needs.
     *
     * @see #setMinWidth
     * @see #setMinHeight
     * @param minWidth  the override value for minimum width
     * @param minHeight the override value for minimum height
     */
    public void setMinSize(double minWidth, double minHeight) {
        setMinWidth(minWidth);
        setMinHeight(minHeight);
    }

    /**
     * Property for overriding the region's computed preferred width.
     * This should only be set if the region's internally computed preferred width
     * doesn't meet the application's layout needs.
     * <p>
     * Defaults to the <code>USE_COMPUTED_SIZE</code> flag, which means that
     * <code>getPrefWidth(forHeight)</code> will return the region's internally
     * computed preferred width.
     */
    private DoubleProperty prefWidth;
    private double _prefWidth = Region.USE_COMPUTED_SIZE;
    public final void setPrefWidth(double value) {
        if (prefWidth == null) {
            _prefWidth = value;
            requestParentLayout();
        } else {
            prefWidth.set(value);
        }
    }
    public final double getPrefWidth() { return prefWidth == null ? _prefWidth : prefWidth.get(); }
    public final DoubleProperty prefWidthProperty() {
        if (prefWidth == null) prefWidth = new MinPrefMaxProperty("prefWidth", _prefWidth, PREF_WIDTH);
        return prefWidth;
    }

    /**
     * Property for overriding the region's computed preferred height.
     * This should only be set if the region's internally computed preferred height
     * doesn't meet the application's layout needs.
     * <p>
     * Defaults to the <code>USE_COMPUTED_SIZE</code> flag, which means that
     * <code>getPrefHeight(forWidth)</code> will return the region's internally
     * computed preferred width.
     */
    private DoubleProperty prefHeight;
    private double _prefHeight = Region.USE_COMPUTED_SIZE;
    public final void setPrefHeight(double value) {
        if (prefHeight == null) {
            _prefHeight = value;
            requestParentLayout();
        } else {
            prefHeight.set(value);
        }
    }
    public final double getPrefHeight() { return prefHeight == null ? _prefHeight : prefHeight.get(); }
    public final DoubleProperty prefHeightProperty() {
        if (prefHeight == null) prefHeight = new MinPrefMaxProperty("prefHeight", _prefHeight, PREF_HEIGHT);
        return prefHeight;
    }

    /**
     * Convenience method for overriding the region's computed preferred width and height.
     * This should only be called if the region's internally computed preferred size
     * doesn't meet the application's layout needs.
     *
     * @see #setPrefWidth
     * @see #setPrefHeight
     * @param prefWidth the override value for preferred width
     * @param prefHeight the override value for preferred height
     */
    public void setPrefSize(double prefWidth, double prefHeight) {
        setPrefWidth(prefWidth);
        setPrefHeight(prefHeight);
    }

    /**
     * Property for overriding the region's computed maximum width.
     * This should only be set if the region's internally computed maximum width
     * doesn't meet the application's layout needs.
     * <p>
     * Defaults to the <code>USE_COMPUTED_SIZE</code> flag, which means that
     * <code>getMaxWidth(forHeight)</code> will return the region's internally
     * computed maximum width.
     * <p>
     * Setting this value to the <code>USE_PREF_SIZE</code> flag will cause
     * <code>getMaxWidth(forHeight)</code> to return the region's preferred width,
     * enabling applications to easily restrict the resizability of the region.
     */
    private DoubleProperty maxWidth;
    private double _maxWidth = Region.USE_COMPUTED_SIZE;
    public final void setMaxWidth(double value) {
        if (maxWidth == null) {
            _maxWidth = value;
            requestParentLayout();
        } else {
            maxWidth.set(value);
        }
    }
    public final double getMaxWidth() { return maxWidth == null ? _maxWidth : maxWidth.get(); }
    public final DoubleProperty maxWidthProperty() {
        if (maxWidth == null) maxWidth = new MinPrefMaxProperty("maxWidth", _maxWidth, MAX_WIDTH);
        return maxWidth;
    }

    /**
     * Property for overriding the region's computed maximum height.
     * This should only be set if the region's internally computed maximum height
     * doesn't meet the application's layout needs.
     * <p>
     * Defaults to the <code>USE_COMPUTED_SIZE</code> flag, which means that
     * <code>getMaxHeight(forWidth)</code> will return the region's internally
     * computed maximum height.
     * <p>
     * Setting this value to the <code>USE_PREF_SIZE</code> flag will cause
     * <code>getMaxHeight(forWidth)</code> to return the region's preferred height,
     * enabling applications to easily restrict the resizability of the region.
     */
    private DoubleProperty maxHeight;
    private double _maxHeight = Region.USE_COMPUTED_SIZE;
    public final void setMaxHeight(double value) {
        if (maxHeight == null) {
            _maxHeight = value;
            requestParentLayout();
        } else {
            maxHeight.set(value);
        }
    }
    public final double getMaxHeight() { return maxHeight == null ? _maxHeight : maxHeight.get(); }
    public final DoubleProperty maxHeightProperty() {
        if (maxHeight == null) maxHeight = new MinPrefMaxProperty("maxHeight", _maxHeight, MAX_HEIGHT);
        return maxHeight;
    }

    /**
     * Convenience method for overriding the region's computed maximum width and height.
     * This should only be called if the region's internally computed maximum size
     * doesn't meet the application's layout needs.
     *
     * @see #setMaxWidth
     * @see #setMaxHeight
     * @param maxWidth  the override value for maximum width
     * @param maxHeight the override value for maximum height
     */
    public void setMaxSize(double maxWidth, double maxHeight) {
        setMaxWidth(maxWidth);
        setMaxHeight(maxHeight);
    }
    
    /**    
    * Requests a layout pass of the parent to be performed before the next scene is
    * rendered. This is batched up asynchronously to happen once per
    * "pulse", or frame of animation.
    * <p>
    * This may be used when the current parent have changed it's min/max/preferred width/height,
    * but doesn't know yet if the change will lead to it's actual size change. This will be determined
    * when it's parent recomputes the layout with the new hints.
    */
   protected final void requestParentLayout() {
	   final Parent p = getParent();
	   if (p != null) {
           p.requestLayout();
       }
   }

   private static final CssMetaData<BaseDriftFXSurface, Number> MIN_HEIGHT =
           new CssMetaData<BaseDriftFXSurface,Number>("-fx-min-height",
               StyleConverter.getSizeConverter(), Region.USE_COMPUTED_SIZE){

          @Override public boolean isSettable(BaseDriftFXSurface node) {
              return node.minHeight == null ||
                      !node.minHeight.isBound();
          }

          @Override public StyleableProperty<Number> getStyleableProperty(BaseDriftFXSurface node) {
              return (StyleableProperty<Number>)node.minHeightProperty();
          }
      };

       private static final CssMetaData<BaseDriftFXSurface, Number> PREF_HEIGHT =
           new CssMetaData<BaseDriftFXSurface,Number>("-fx-pref-height",
        		   StyleConverter.getSizeConverter(), Region.USE_COMPUTED_SIZE){

          @Override public boolean isSettable(BaseDriftFXSurface node) {
              return node.prefHeight == null ||
                      !node.prefHeight.isBound();
          }

          @Override public StyleableProperty<Number> getStyleableProperty(BaseDriftFXSurface node) {
              return (StyleableProperty<Number>)node.prefHeightProperty();
          }
      };

       private static final CssMetaData<BaseDriftFXSurface, Number> MAX_HEIGHT =
           new CssMetaData<BaseDriftFXSurface,Number>("-fx-max-height",
        		   StyleConverter.getSizeConverter(), Region.USE_COMPUTED_SIZE){

          @Override public boolean isSettable(BaseDriftFXSurface node) {
              return node.maxHeight == null ||
                      !node.maxHeight.isBound();
          }

          @Override public StyleableProperty<Number> getStyleableProperty(BaseDriftFXSurface node) {
              return (StyleableProperty<Number>)node.maxHeightProperty();
          }
      };

       private static final CssMetaData<BaseDriftFXSurface, Number> MIN_WIDTH =
           new CssMetaData<BaseDriftFXSurface,Number>("-fx-min-width",
        		   StyleConverter.getSizeConverter(), Region.USE_COMPUTED_SIZE){

          @Override public boolean isSettable(BaseDriftFXSurface node) {
              return node.minWidth == null ||
                      !node.minWidth.isBound();
          }

          @Override public StyleableProperty<Number> getStyleableProperty(BaseDriftFXSurface node) {
              return (StyleableProperty<Number>)node.minWidthProperty();
          }
      };

       private static final CssMetaData<BaseDriftFXSurface, Number> PREF_WIDTH =
           new CssMetaData<BaseDriftFXSurface,Number>("-fx-pref-width",
        		   StyleConverter.getSizeConverter(), Region.USE_COMPUTED_SIZE){

          @Override public boolean isSettable(BaseDriftFXSurface node) {
              return node.prefWidth == null ||
                      !node.prefWidth.isBound();
          }

          @Override public StyleableProperty<Number> getStyleableProperty(BaseDriftFXSurface node) {
              return (StyleableProperty<Number>)node.prefWidthProperty();
          }
      };

       private static final CssMetaData<BaseDriftFXSurface, Number> MAX_WIDTH =
           new CssMetaData<BaseDriftFXSurface,Number>("-fx-max-width",
        		   StyleConverter.getSizeConverter(), Region.USE_COMPUTED_SIZE){

          @Override public boolean isSettable(BaseDriftFXSurface node) {
              return node.maxWidth == null ||
                      !node.maxWidth.isBound();
          }

          @Override public StyleableProperty<Number> getStyleableProperty(BaseDriftFXSurface node) {
              return (StyleableProperty<Number>)node.maxWidthProperty();
          }
      };
      
      public static List<CssMetaData<? extends Styleable, ?>> getClassCssMetaData() {
          return Arrays.asList(MIN_WIDTH, MIN_HEIGHT, PREF_WIDTH, PREF_HEIGHT, MAX_WIDTH, MAX_HEIGHT);
      }
      
      public List<CssMetaData<? extends Styleable, ?>> getCssMetaData() {
          return getClassCssMetaData();
      }
}
