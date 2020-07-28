package org.eclipse.fx.drift.internal;

import org.eclipse.fx.drift.util.ManifestUtil;

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
		version = ManifestUtil.getManifestEntry(Versioning.class, "Drift-Version");
		qualifier = ManifestUtil.getManifestEntry(Versioning.class, "Drift-Qualifier");
		timestamp = ManifestUtil.getManifestEntry(Versioning.class, "Drift-Timestamp");
		sha = ManifestUtil.getManifestEntry(Versioning.class, "Drift-SHA");
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
