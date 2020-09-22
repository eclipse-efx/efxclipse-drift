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
package org.eclipse.fx.drift.util;

import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.function.Consumer;

import org.eclipse.fx.drift.DriftFXConfig;
import org.eclipse.fx.drift.internal.DriftFX;
import org.eclipse.fx.drift.internal.DriftLogger;

public class NativeUtil {
	private static final DriftLogger LOGGER = DriftFX.createLogger(NativeUtil.class);
	
	private NativeUtil() {}
	
	private static String OS = System.getProperty("os.name");
	private static boolean isWindows = getOsName().toLowerCase().contains("windows");
	private static boolean isLinux = getOsName().toLowerCase().contains("linux");
	private static boolean isMacOs = getOsName().toLowerCase().contains("mac") || getOsName().toLowerCase().contains("darwin");
	
	
	static boolean osgi = false;
	
	public static void useOsgiEnvironment() {
		osgi = true;
	}

	public static String getOsName() {
		return OS;
	}
	
	public static boolean isWindows() {
		return isWindows;
	}

	public static boolean isLinux() {
		return isLinux;
	}

	public static boolean isMacOs() {
		return isMacOs;
	}
	
	public static void loadLibrary(Class<?> context, String libname, Consumer<String> loadLibrary, Consumer<String> load) {
		if (DriftFXConfig.isUseJavaLibraryPath() || osgi) {
			// osgi will take care of it
			LOGGER.info(() -> "loading " + libname + " via system call");
			loadLibrary.accept(libname);
		}
		else {
			// we need to make it happen
			try {
				String filename = getFilename(libname);
				Path tmpDir = Files.createTempDirectory("driftfx");
				Path extractPath = tmpDir.resolve(filename);
				
				String resourceName = "/native/" + filename;
				URL url = context.getResource(resourceName);
				LOGGER.debug(() -> "Resource Lookup: name: " + resourceName + ", context: " + context + " => " + url);
				
				try (InputStream in = context.getResourceAsStream("/native/" + filename)) {
					extract(in, extractPath);
				}
				
				LOGGER.info(() -> "loading " + libname + " from extracted location (" + extractPath + ")");
				load.accept(extractPath.toString());
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	
    private static Path extract(InputStream in, Path extractPath) throws IOException {
        Files.createDirectories(extractPath.getParent());
        if (!Files.exists(extractPath)) {
            long bytes = Files.copy(in, extractPath);
            if (bytes == 0) {
                throw new IOException("library has no size!");
            }
        }
        return extractPath;
    }
	
	private static String getFilename(String libname) {
		if (isWindows()) {
			return libname + ".dll";
		}
		if (isLinux()) {
			return "lib" + libname + ".so";
		}
		if (isMacOs()) {
			return "lib" + libname + ".dylib";
		}
		throw new RuntimeException("os not supported: " + getOsName());
	}
}
