package org.eclipse.fx.drift.internal.transfer;

import com.sun.prism.Texture;

@SuppressWarnings("restriction")
public interface TransferMode {

	String getName();
	
	SharedTexture createSharedTexture();
	ShareData createShareData(SharedTexture tx);
	
	void connectTexture(Texture texture, ShareData shareData);
	
}
