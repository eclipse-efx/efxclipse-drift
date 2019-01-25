/*******************************************************************************
 * Copyright (c) 2019 BestSolution.at and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Christoph Caks <ccaks@bestsolution.at> - initial API and implementation
 *******************************************************************************/
package org.eclipse.fx.drift.samples;

import org.eclipse.fx.drift.DriftFXSurface;

import javafx.application.Application;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.ListCell;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import javafx.scene.layout.Region;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

public class Demo extends Application {

	Node create() {
		DriftFXSurface surface0 = new DriftFXSurface();
		Rectangle clip = new Rectangle();
		clip.widthProperty().bind(surface0.widthProperty());
		clip.heightProperty().bind(surface0.heightProperty());
		surface0.setClip(clip);

		BorderPane dummy = new BorderPane();
		dummy.setStyle("-fx-padding: 20");
		dummy.setCenter(surface0);

		ComboBox<ARenderer> renderers = new ComboBox<>();
		renderers.setButtonCell(new CellImpl());
		renderers.setCellFactory(v -> new CellImpl());
		renderers.getItems().add(new SimpleColorRenderer(surface0));
		renderers.getItems().add(new SimpleTriangleRenderer(surface0));

		Button stop = new Button("Stop");
		stop.setMinWidth(Region.USE_PREF_SIZE);
		Button start = new Button("Start");
		start.setMinWidth(Region.USE_PREF_SIZE);
		stop.setOnAction(a -> {
			renderers.getSelectionModel().getSelectedItem().stop();
			start.setDisable(false);
			stop.setDisable(true);
			renderers.setDisable(false);
		});
		start.setOnAction(a -> {
			if (renderers.getSelectionModel().getSelectedItem() == null)
				return;
			renderers.setDisable(true);
			start.setDisable(true);
			stop.setDisable(false);
			renderers.getSelectionModel().getSelectedItem().start();
		});
		stop.setDisable(true);

		dummy.setBottom(new HBox(renderers, start, stop));

		return dummy;
	}

	@Override
	public void start(Stage primaryStage) throws Exception {
		DriftFXSurface.initialize();

		BorderPane root = new BorderPane();
		root.setPrefSize(400, 300);
		Scene scene = new Scene(root);

		primaryStage.setScene(scene);

		Node a = create();
		Node b = create();
		HBox hbox = new HBox();
		hbox.getChildren().setAll(a, b);
		HBox.setHgrow(a, Priority.ALWAYS);
		HBox.setHgrow(b, Priority.ALWAYS);

		root.setCenter(hbox);

		primaryStage.show();
	}

	public static void main(String[] args) {
		launch(args);
	}

	static class CellImpl extends ListCell<ARenderer> {
		@Override
		protected void updateItem(ARenderer item, boolean empty) {
			super.updateItem(item, empty);
			if (item == null || empty) {
				setText(null);
			} else {
				setText(item.getClass().getSimpleName());
			}
		}
	}
}
