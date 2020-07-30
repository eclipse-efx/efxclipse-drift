package org.eclipse.fx.drift.util;

import java.io.IOException;
import java.io.InputStream;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.jar.Attributes;
import java.util.jar.Manifest;

public class ManifestUtil {
	
	private ManifestUtil() {}
	
	private static URL getManifestUrl(Class<?> cls) {
		try {
			String shortName = cls.getSimpleName() + ".class";
			String fullPath = cls.getName().replace('.', '/') + ".class";
			URL clsUrl = cls.getResource(shortName);
			return new URL(clsUrl.toString().replace(fullPath, "META-INF/MANIFEST.MF"));
		}
		catch (MalformedURLException e) {
			throw new RuntimeException(e);
		}
	}
	
	public static String getManifestEntry(Class<?> context, String name) {
		URL manifestUrl = getManifestUrl(context);
		try (InputStream in = manifestUrl.openStream()) {
			Manifest manifest = new Manifest(in);
			Attributes attrs = manifest.getMainAttributes();
			return attrs.getValue(name);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
	
}
