package org.eclipse.fx.drift.internal;

import org.junit.Test;

import org.junit.Assert;

public class TestVersioning {

	@Test
	public void readManifest() {
		Assert.assertEquals("999.0.0", Versioning.getVersion());
		Assert.assertEquals("qualifier", Versioning.getQualifier());
		Assert.assertEquals("timestamp", Versioning.getTimestamp());
		Assert.assertEquals("sha", Versioning.getSha());
	}
	
}
