package org.eclipse.fx.drift.internal;

import org.eclipse.fx.drift.util.NativeUtil;
import org.osgi.framework.BundleActivator;
import org.osgi.framework.BundleContext;
import org.osgi.framework.wiring.BundleWiring;

public class OSGiActivator implements BundleActivator {

	@Override
	public void start(BundleContext context) throws Exception {
		Log.info("DriftFX OSGi Mode");
		NativeUtil.useOsgiEnvironment();
		
		
		ClassLoader classLoader = context.getBundle().adapt(BundleWiring.class).getClassLoader();
		DriftCPP.init(classLoader);
	}

	@Override
	public void stop(BundleContext context) throws Exception {
		
		DriftCPP.dispose();
	}

}
