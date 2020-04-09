package org.eclipse.fx.drift.internal;

import com.sun.javafx.font.PGFont;
import com.sun.javafx.scene.text.FontHelper;

import javafx.scene.text.Font;
import javafx.stage.Screen;

public class DriftUtil {
	
	public static PGFont getFont(Font font) {
		return (PGFont) FontHelper.getNativeFont(font);
	}
	
	public static double getRenderScale(Screen screen) {
		return screen.getOutputScaleX();
	}
}