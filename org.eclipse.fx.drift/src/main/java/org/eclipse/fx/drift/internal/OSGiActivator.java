package org.eclipse.fx.drift.internal;

import org.eclipse.fx.drift.util.NativeUtil;
import org.osgi.framework.BundleActivator;
import org.osgi.framework.BundleContext;

public class OSGiActivator implements BundleActivator {

	@Override
	public void start(BundleContext context) throws Exception {
		NativeUtil.useOsgiEnvironment();
	}

	@Override
	public void stop(BundleContext context) throws Exception {
		
	}

}
