package org.eclipse.fx.drift.util;

import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.function.Consumer;

import org.eclipse.fx.drift.internal.Log;

public class NativeUtil {
	
	private NativeUtil() {}
	
	private static final boolean USE_JAVA_LIBRARY_PATH = Boolean.getBoolean("driftfx.use.java.library.path");
	
	private static String OS = null;
	
	static boolean osgi = false;
	
	public static void useOsgiEnvironment() {
		osgi = true;
	}

	public static String getOsName() {
		if (OS == null) {
			OS = System.getProperty("os.name");
		}
		return OS;
	}
	
	public static boolean isWindows() {
		return getOsName().toLowerCase().contains("windows");
	}

	public static boolean isLinux() {
		return getOsName().toLowerCase().contains("linux");
	}

	public static boolean isMacOs() {
		return getOsName().toLowerCase().contains("mac");
	}
	
	public static void loadLibrary(Class<?> context, String libname, Consumer<String> loadLibrary, Consumer<String> load) {
		if (USE_JAVA_LIBRARY_PATH || osgi) {
			// osgi will take care of it
			Log.info("loading " + libname + " via system call");
//			System.loadLibrary(libname);
			loadLibrary.accept(libname);
		}
		else {
			
			// we need to make it happen
			
			String filename = getFilename(libname);
			Path tmpDir = Paths.get(System.getProperty("java.io.tmpdir"));
			Path extractPath = tmpDir.resolve("driftfx").resolve(ManifestUtil.getManifestEntry(context, "Bundle-Version")).resolve(filename);
			
			String resourceName = "/native/" + filename;
			URL url = context.getResource(resourceName);
			Log.debug("Resource Lookup: name: " + resourceName + ", context: " + context + " => " + url);
			
			
			try (InputStream in = context.getResourceAsStream("/native/" + filename)) {
				extract(in, extractPath);
			} catch (IOException e) {
				e.printStackTrace();
			}
			
			Log.info("loading " + libname + " from extracted location (" + extractPath + ")");
//			System.load(extractPath.toString());
			load.accept(extractPath.toString());
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
