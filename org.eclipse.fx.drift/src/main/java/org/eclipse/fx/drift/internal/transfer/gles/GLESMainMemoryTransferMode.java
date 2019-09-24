package org.eclipse.fx.drift.internal.transfer.gles;

import org.eclipse.fx.drift.internal.transfer.ShareData;
import org.eclipse.fx.drift.internal.transfer.SharedTexture;
import org.eclipse.fx.drift.internal.transfer.TransferMode;

import com.sun.prism.Texture;

public class GLESMainMemoryTransferMode implements TransferMode {

	@Override
	public String getName() {
		return "MainMemory";
	}

	@Override
	public SharedTexture createSharedTexture() {
		
		return null;
	}

	@Override
	public ShareData createShareData(SharedTexture tx) {
		
		return null;
	}

	@Override
	public void connectTexture(Texture texture, ShareData shareData) {
		
	}

}
