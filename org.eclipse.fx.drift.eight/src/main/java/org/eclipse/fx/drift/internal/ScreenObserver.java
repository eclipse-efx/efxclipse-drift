package org.eclipse.fx.drift.internal;

import com.sun.javafx.stage.ScreenHelper;

import javafx.scene.Node;
import javafx.stage.Screen;

public class ScreenObserver extends BaseScreenObserver {

	public ScreenObserver(Node node) {
		super(node);
	}

	@Override
	protected double getRenderScale(Screen screen) {
		return ScreenHelper.getScreenAccessor().getRenderScale(getCurrentScreen());
	}

}
