package org.eclipse.fx.drift.internal.prism;

import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import org.eclipse.fx.drift.internal.jni.macos.MacOS;

import com.sun.prism.Texture;

@SuppressWarnings("restriction")
public class PrismES2 {

	private static boolean isMac;
	private static boolean isX11;
	
	private static Class<?> cES2ResourceFactory;
	private static Field fES2ResourceFactory_context;
	
	private static Class<?> cES2Context;
	private static Method mES2Context_getGLContext;
	
	private static Class<?> cGLContext;
	
	// mac version
	private static Class<?> cMacGLContext;
	private static Method mMacGLContext_getNativeHandle;
	
	// x11 version
	private static Class<?> cX11GLContext;
	private static Method mX11GLContext_getNativeHandle;
	
	private static Class<?> cBaseTexture;
	private static Field fBaseTexture_resource;
	
	private static Class<?> cManagedResource;
	private static Method mManagedResource_getResource;
	
	private static Class<?> cES2TextureData;
	private static Method mES2TextureData_getTexID;
	
	private static Field fES2TextureData_texID;
	
	
	static void initialize() throws ClassNotFoundException, NoSuchMethodException, SecurityException, NoSuchFieldException  {
		cES2ResourceFactory = Class.forName("com.sun.prism.es2.ES2ResourceFactory");
		fES2ResourceFactory_context = cES2ResourceFactory.getDeclaredField("context");
		fES2ResourceFactory_context.setAccessible(true);
		
		cES2Context = Class.forName("com.sun.prism.es2.ES2Context");
		mES2Context_getGLContext = cES2Context.getDeclaredMethod("getGLContext");
		mES2Context_getGLContext.setAccessible(true);
		
		try {
			cMacGLContext = Class.forName("com.sun.prism.es2.MacGLContext");
			mMacGLContext_getNativeHandle = cMacGLContext.getDeclaredMethod("getNativeHandle");
			mMacGLContext_getNativeHandle.setAccessible(true);
			isMac = true;
		}
		catch (ClassNotFoundException e) {
			isMac = false;
		}
		
		try {
			cX11GLContext = Class.forName("com.sun.prism.es2.X11GLContext");
			mX11GLContext_getNativeHandle = cX11GLContext.getDeclaredMethod("getNativeHandle");
			mX11GLContext_getNativeHandle.setAccessible(true);
			isX11 = true;
		}
		catch (ClassNotFoundException e) {
			isX11 = false;
		}
		cBaseTexture = Class.forName("com.sun.prism.impl.BaseTexture");
		fBaseTexture_resource = cBaseTexture.getDeclaredField("resource");
		fBaseTexture_resource.setAccessible(true);
		
		cManagedResource = Class.forName("com.sun.prism.impl.ManagedResource");
		mManagedResource_getResource = cManagedResource.getDeclaredMethod("getResource");
		mManagedResource_getResource.setAccessible(true);
		
		cES2TextureData = Class.forName("com.sun.prism.es2.ES2TextureData");
		mES2TextureData_getTexID = cES2TextureData.getDeclaredMethod("getTexID");
		mES2TextureData_getTexID.setAccessible(true);
		
		fES2TextureData_texID = cES2TextureData.getDeclaredField("texID");
		fES2TextureData_texID.setAccessible(true);
	}
	
	public static Object getES2Context(Object iES2ResourceFactory) throws IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		return fES2ResourceFactory_context.get(iES2ResourceFactory);
	}
	
	public static Object getGLContext(Object iES2Context) throws IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		return  mES2Context_getGLContext.invoke(iES2Context);
	}
	
	static long getNativeHandle(Object iGLContext) throws IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		if (isMac) {
			long nsJContextHandle =  (long) mMacGLContext_getNativeHandle.invoke(iGLContext);
			return MacOS.callGetCGLContextObjFromNSJContext(nsJContextHandle);
		}
		else if (isX11) {
			return (long) mX11GLContext_getNativeHandle.invoke(iGLContext);
		}
		else {
			throw new RuntimeException("this is neither Mac nor X11 - don't know how to handle this!");
		}
	}
	
	static Object getTextureResource(Object iTexture) throws IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		return fBaseTexture_resource.get(iTexture);
	}
	
	static Object getResourceResource(Object iManagedResource) throws IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		return mManagedResource_getResource.invoke(iManagedResource);
	}
	
	static int getTexID(Object iES2TextureData) throws IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		return (int) mES2TextureData_getTexID.invoke(iES2TextureData);
	}
	
	static void setTexID(Object iES2TextureData, int texID) throws IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		fES2TextureData_texID.set(iES2TextureData, texID);
	}

	public static int getTextureName(Texture texture) {
		try {
			return getTexID(getResourceResource(getTextureResource(texture)));
		}
		catch (Exception e) {
			return 0;
		}
	}
	
	public static void updateTextureName(Texture texture, int texID) {
		try {
			setTexID(getResourceResource(getTextureResource(texture)), texID);
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
}
