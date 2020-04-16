package org.eclipse.fx.drift;

import org.eclipse.fx.drift.internal.common.IOSurfaceImageData;
import org.eclipse.fx.drift.internal.common.MainMemoryImageData;
import org.eclipse.fx.drift.internal.common.NVDXInteropImageData;

public class StandardTransferTypes {

	public static final TransferType MainMemory = MainMemoryImageData.TYPE;
	public static final TransferType NVDXInterop = NVDXInteropImageData.TYPE;
	public static final TransferType IOSurface = IOSurfaceImageData.TYPE;
	
}
