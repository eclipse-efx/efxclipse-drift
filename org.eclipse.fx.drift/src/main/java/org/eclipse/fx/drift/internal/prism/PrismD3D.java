package org.eclipse.fx.drift.internal.prism;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import com.sun.prism.Texture;

@SuppressWarnings("restriction")
public class PrismD3D {

	private static Class<?> cD3DResourceFactory;
	private static Method mD3DResourceFactoryGetContext;
	
	private static Class<?> cD3DContext;
	private static Method mD3DContextGetContextHandle;
	
	
	static void initialize() throws ClassNotFoundException, NoSuchMethodException, SecurityException {
		cD3DResourceFactory = Class.forName("com.sun.prism.d3d.D3DResourceFactory");
		mD3DResourceFactoryGetContext = cD3DResourceFactory.getDeclaredMethod("getContext");
		mD3DResourceFactoryGetContext.setAccessible(true);
		
		cD3DContext = Class.forName("com.sun.prism.d3d.D3DContext");
		mD3DContextGetContextHandle = cD3DContext.getDeclaredMethod("getContextHandle");
		mD3DContextGetContextHandle.setAccessible(true);
	}
	
	static Object getD3DContext(Object iResourceFactory) throws IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		return mD3DResourceFactoryGetContext.invoke(iResourceFactory);
	}
	
	static long getContextHandle(Object iD3DContext) throws IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		return (Long) mD3DContextGetContextHandle.invoke(iD3DContext);
	}
	
	static long getTextureHandle(Texture texture) {
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
	
	
}
