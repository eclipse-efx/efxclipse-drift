package org.eclipse.fx.drift.internal.common;

import org.eclipse.fx.drift.TransferType;
import org.eclipse.fx.drift.Vec2i;

public class MainMemoryImageData extends ImageData {

	public static final TransferType TYPE = new TransferType("MainMemory");
	
	public final long memPointer;
	public final int memSize;
	
	public MainMemoryImageData(int number, Vec2i size, long memPointer, int memSize) {
		super(number, TYPE, size);
		this.memPointer = memPointer;
		this.memSize = memSize;
	}
	
}
