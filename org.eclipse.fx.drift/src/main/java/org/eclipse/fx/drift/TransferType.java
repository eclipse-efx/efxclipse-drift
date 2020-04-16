package org.eclipse.fx.drift;

import java.util.function.BooleanSupplier;

public class TransferType {
	public final String id;
	private final BooleanSupplier available;
	public TransferType(String id, BooleanSupplier available) {
		this.id = id;
		this.available = available;
	}
	
	public boolean isAvailable() {
		return available.getAsBoolean();
	}
	
	@Override
	public String toString() {
		return "TransferType(" + id + ")["+(isAvailable()?"available":"not available")+"]";
	}
}