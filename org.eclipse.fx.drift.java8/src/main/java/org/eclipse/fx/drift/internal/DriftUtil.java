package org.eclipse.fx.drift.internal;

import com.sun.javafx.font.PGFont;
import com.sun.javafx.stage.ScreenHelper;

import javafx.scene.text.Font;
import javafx.stage.Screen;

public class DriftUtil {
	public static PGFont getFont(Font font) {
		return (PGFont) font.impl_getNativeFont();
	}
	
	public static double getRenderScale(Screen screen) {
		return ScreenHelper.getScreenAccessor().getRenderScale(screen);
	}
}