package org.eclipse.fx.drift.samples;

import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.stream.Collectors;

import org.eclipse.fx.core.ServiceUtils;
import org.eclipse.fx.core.SystemUtils;
import org.eclipse.fx.core.URLResolver;

public abstract class ARenderer {

	private volatile boolean alive = true;
	private Thread t;
	
	public void start() {
		if (t == null) {
			t = new Thread(this::run);
			t.setDaemon(true);
			t.setName(getClass().getSimpleName());
			alive = true;
			t.start();
		}
	}
	
	public void stop() {
		alive = false;
		try {
			t.join();
			t = null;
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
	
	public boolean isAlive() {
		return alive;
	}

	protected abstract void run();
	
	public static String loadTextResource(String resource) {
		Path path = null;
		try {
			if( SystemUtils.isOsgiEnv() ) {
				URL res = ARenderer.class.getResource(resource);
				if( res != null ) {
					path = ServiceUtils.getService(URLResolver.class).get().resolveToLocalPath(res);	
				}
			} else {
				path = Paths.get(ARenderer.class.getResource(resource).toURI());
			}
			
			if( path != null ) {
				return Files.readAllLines(path).stream().collect(Collectors.joining("\n"));	
			}
		}
		catch (Exception e) {
			System.err.println("Error accessing Resource " + resource + "! THis will most likely result in a crash!");
			e.printStackTrace();
		}
		return null;
	}
	
	public static void main(String[] args) {
		System.err.println(loadTextResource("/SimpleTriangleRenderer/Triangle.fragmentshader"));
	}

}
