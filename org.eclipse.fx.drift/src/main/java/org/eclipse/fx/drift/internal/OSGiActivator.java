package org.eclipse.fx.drift.internal;

import org.eclipse.fx.drift.util.NativeUtil;
import org.osgi.framework.BundleActivator;
import org.osgi.framework.BundleContext;

public class OSGiActivator implements BundleActivator {
	private static final DriftLogger LOGGER = DriftFX.createLogger(OSGiActivator.class);
	
	@Override
	public void start(BundleContext context) throws Exception {
		LOGGER.info(() -> "DriftFX OSGi Mode");
		NativeUtil.useOsgiEnvironment();
		
		//DriftCPP.classLoader = context.getBundle().adapt(BundleWiring.class).getClassLoader();
	}

	@Override
	public void stop(BundleContext context) throws Exception {
	}

}
