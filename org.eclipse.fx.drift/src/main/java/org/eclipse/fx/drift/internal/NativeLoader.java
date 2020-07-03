package org.eclipse.fx.drift.internal;

import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class NativeLoader {

	 private static String OS = null;
	   public static String getOsName()
	   {
	      if(OS == null) { OS = System.getProperty("os.name"); }
	      return OS;
	   }
	   public static boolean isWindows()
	   {
	      return getOsName().startsWith("Windows");
	   }

	   public static boolean isLinux() {
		   return getOsName().contains("linux");
	   }
	   
	   public static boolean isMacOs() {
		   return getOsName().contains("MACOS");
	   }
	
	
	/*package*/ static boolean osgi = false;
	
	private static boolean useJavaLibraryPath = Boolean.getBoolean("driftfx.use.java.library.path");
	
	public static void loadLibrary(Class<?> context, String libname) {
		if (useJavaLibraryPath || osgi) {
			// osgi will take care of it
			System.loadLibrary(libname);
		}
		else {
			// we need to make it happen
			
			String filename = getFilename(libname);
			Path tmpDir = Paths.get(System.getProperty("java.io.tmpdir"));
			Path extractPath = tmpDir.resolve("driftfx").resolve(filename);
			
			String resourceName = "/native/" + filename;
			URL url = context.getResource(resourceName);
			System.err.println("Resource Lookup: name: " + resourceName + ", context: " + context + " => " + url);
			
			try (InputStream in = context.getResourceAsStream("/native/" + filename)) {
				extract(in, extractPath);
			} catch (IOException e) {
				e.printStackTrace();
			}
			
			System.load(extractPath.toString());
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
