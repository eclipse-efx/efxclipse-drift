package org.eclipse.fx.drift.impl;

import org.eclipse.fx.drift.internal.DriftUtil;
import org.eclipse.fx.drift.internal.FPSCounter2;

import com.sun.javafx.font.FontStrike;
import com.sun.javafx.font.PGFont;
import com.sun.javafx.geom.Point2D;
import com.sun.javafx.geom.transform.BaseTransform;
import com.sun.javafx.scene.text.GlyphList;
import com.sun.javafx.scene.text.TextLayout;
import com.sun.javafx.scene.text.TextLayoutFactory;
import com.sun.javafx.tk.Toolkit;
import com.sun.prism.Graphics;
import com.sun.prism.paint.Color;

import javafx.scene.text.Font;
import javafx.scene.text.TextAlignment;

@SuppressWarnings("restriction")
public class NGRenderUtil {
	public static void drawFPSGraph(Graphics g, float x, float y, float width, float height, String label, FPSCounter2 c) {
		int count = 30;
		Color bg = new Color(0, 0, 0, 0.5f);
		Color fg = new Color(1, 1, 1, 1);
		float padding = 3;
		
		g.setPaint(bg);
		g.fillRect(x, y, width, height);
		
		float graphWidth = width - 2 * padding;
		float graphHeight = height - 2* padding;
		
		float lineAvail = (graphWidth) / count;
		float lineWidth = lineAvail * 8/10f;
		
		for (int i = 0; i < count; i++) {
			double fps = c.fpsHistory[i];
			double hue = Math.min(1, fps / 60d);
			javafx.scene.paint.Color hsb = javafx.scene.paint.Color.hsb(hue * 100, .7, .7);
			g.setPaint(new Color((float)hsb.getRed(), (float)hsb.getGreen(), (float)hsb.getBlue(), 0.5f));
			int norm = (int) Math.round(Math.min(graphHeight, fps / 100 * graphHeight));
			g.fillRect(x + padding + graphWidth - i * lineAvail - lineAvail, y + padding + graphHeight - norm, lineWidth, norm);
		}
		writeText(g, x, y, 12, String.format("%s", label), fg, false);
		writeText(g, x - width + 100 , y + height / 2 - 15, 24, String.format("%5.1ffps", c.fps), fg, true);
	}
	
	public static void writeText(Graphics g, float x, float y, int fontSize, String text, Color color, boolean rightAligned) {
		Font font = Font.font(fontSize);
		PGFont pgFont = (PGFont) DriftUtil.getFont(font);
		
		FontStrike strike = pgFont.getStrike(BaseTransform.IDENTITY_TRANSFORM);
		
		TextLayoutFactory factory = Toolkit.getToolkit().getTextLayoutFactory();
		TextLayout layout = factory.createLayout();
		
		layout.setContent(text, pgFont);
		layout.setAlignment(rightAligned ? TextAlignment.RIGHT.ordinal() : TextAlignment.LEFT.ordinal());
		layout.setLineSpacing(0);
		layout.setWrapWidth(0);
		
		
		GlyphList[] runs = layout.getRuns();
		
		float layoutX = x;
		float layoutY = -pgFont.getSize() - y;
		
		g.setPaint(color);
		for (int i = 0; i < runs.length; i++) {
			GlyphList run = runs[i];
			Point2D pt = run.getLocation();
            float gx = pt.x- layoutX;
            float gy = pt.y - layoutY;
			BaseTransform t = BaseTransform.getTranslateInstance(gx, gy);
			g.fill(strike.getOutline(run,  t));
		}
	}
}
