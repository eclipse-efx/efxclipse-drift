package org.eclipse.fx.drift.internal;

import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.util.jar.Attributes;
import java.util.jar.Manifest;

public final class Versioning {

	private static String version;
	private static String qualifier;
	private static String timestamp;
	private static String sha;
	
	static {
		readManifest();
	}
	
	private Versioning() {}
	
	private static void readManifest() {
		URL manifestUrl = Versioning.class.getResource("/META-INF/MANIFEST.MF");
		try (InputStream in = manifestUrl.openStream()) {
			Manifest manifest = new Manifest(in);
			Attributes attrs = manifest.getMainAttributes();
			version = attrs.getValue("Drift-Version");
			qualifier = attrs.getValue("Drift-Qualifier");
			timestamp = attrs.getValue("Drift-Timestamp");
			sha = attrs.getValue("Drift-SHA");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static String getVersion() {
		return version;
	}
	
	public static String getQualifier() {
		return qualifier;
	}
	
	public static String getTimestamp() {
		return timestamp;
	}
	
	public static String getSha() {
		return sha;
	}
	
	
}
