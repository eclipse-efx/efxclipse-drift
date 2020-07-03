package org.eclipse.fx.drift.internal;

import org.osgi.framework.BundleActivator;
import org.osgi.framework.BundleContext;

public class OSGiActivator implements BundleActivator {

	@Override
	public void start(BundleContext context) throws Exception {
		NativeLoader.osgi = true;
	}

	@Override
	public void stop(BundleContext context) throws Exception {
		
	}

}
