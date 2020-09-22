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
