package org.eclipse.fx.drift.internal.prism;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.Optional;

import com.sun.prism.Texture;

import org.eclipse.fx.drift.internal.Log;
import org.eclipse.fx.drift.internal.NativeLoader;
import org.eclipse.fx.drift.internal.QuantumRendererHelper;
import org.eclipse.fx.drift.internal.jni.MemoryStack;
import org.eclipse.fx.drift.internal.jni.win32.Win32;
import org.eclipse.fx.drift.internal.jni.win32.Win32.IDirect3DDevice9Ex;

@SuppressWarnings("restriction")
public class Prism {

	static {
		NativeLoader.loadLibrary(Prism.class, "DriftGL");
		NativeLoader.loadLibrary(Prism.class, "driftfx");
	}
	
	private static Class<?> cGraphicsPipeline;
	private static Method mGraphicsPipelineGetDefaultResourceFactory;

	private static Class<?> cResourceFactory;
	
	private static Object iDefaultResourceFactory;

	private static Optional<Class<?>> getClass(String className) {
		try {
			return Optional.of(Class.forName(className));
		} catch (Exception e) {
			return Optional.empty();
		}
	}
	
	private static boolean isD3D;
	private static boolean isSW;
	private static boolean isES2;
	
	private static Object iD3DContext;
	private static long contextHandleD3D;
	
	private static Win32.IDirect3DDevice9Ex d3dDevice;
	
	private static Object iES2Context;
	private static Object iGLContext;
	private static long contextHandleES2;

	public static void initialize() throws ClassNotFoundException, NoSuchMethodException, InvocationTargetException,
			IllegalAccessException, IllegalArgumentException, NoSuchFieldException {

		cGraphicsPipeline = Class.forName("com.sun.prism.GraphicsPipeline");
		mGraphicsPipelineGetDefaultResourceFactory = cGraphicsPipeline.getMethod("getDefaultResourceFactory");
		cResourceFactory = Class.forName("com.sun.prism.ResourceFactory");
		iDefaultResourceFactory = mGraphicsPipelineGetDefaultResourceFactory.invoke(null);

		String name = iDefaultResourceFactory.getClass().getName();
		isD3D = "com.sun.prism.d3d.D3DResourceFactory".equals(name);
		isES2 = "com.sun.prism.es2.ES2ResourceFactory".equals(name);
		isSW = "com.sun.prism.sw.SWResourceFactory".equals(name);

		if (isD3D) {
			PrismD3D.initialize();
			iD3DContext = PrismD3D.getD3DContext(iDefaultResourceFactory);
			contextHandleD3D = PrismD3D.getContextHandle(iD3DContext);
			Log.debug(" * D3D Context handle = " + contextHandleD3D);
			d3dDevice = org.eclipse.fx.drift.internal.jni.win32.Prism.getPrismIDirect3DDevice9Ex(contextHandleD3D);
			Log.debug(" * D3D Context direct3D device = " + d3dDevice);
			//NativeAPI.initializeD3DPipeline(contextHandleD3D);
		} else if (isES2) {
			PrismES2.initialize();
			iES2Context = PrismES2.getES2Context(iDefaultResourceFactory);
			iGLContext = PrismES2.getGLContext(iES2Context);
			contextHandleES2 = PrismES2.getNativeHandle(iGLContext);

	//		QuantumRendererHelper.initialize(contextHandleES2);
			
			//NativeAPI.initializeES2Pipeline(contextHandleES2);
		} else if (isSW) {
			throw new UnsupportedOperationException("SW Support not yet implemented!");
		} else {
			throw new UnsupportedOperationException("Unknown JavaFX pipeline!");
		}

	}
	
	public static boolean isD3D() {
		return isD3D;
	}
	
	public static boolean isSW() {
		return isSW;
	}
	
	public static boolean isES2() {
		return isES2;
	}
	
	public static long getES2ContextHandle() {
		return contextHandleES2;
	}
	
	public static long getTextureHandle(Texture texture) {
		if (isD3D()) {
			try {
				// TODO move class and method to members
				Class<?> d3dTexture = Class.forName("com.sun.prism.d3d.D3DTexture");
				Method mD3DTextureGetNativeSourceHandle = d3dTexture.getMethod("getNativeSourceHandle");
				mD3DTextureGetNativeSourceHandle.setAccessible(true);
				return (long) mD3DTextureGetNativeSourceHandle.invoke(texture);
			}
			catch (Exception e) {
				throw new RuntimeException(e);
			}
		}
		if (isES2()) {
			return PrismES2.getTextureName(texture);
		}
		throw new UnsupportedOperationException("Not implemented");
	}
	
	public static IDirect3DDevice9Ex getD3DDevice() {
		return d3dDevice;
	}

}
