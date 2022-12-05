package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.layout.*;       //Panel
import javafx.scene.shape.*;        //Shape
import javafx.scene.text.*;         //Text and Font
import javafx.scene.paint.Color;    //Color
import javafx.geometry.*;           //Insets, Pos

public class BasicJavaFX extends Application {
    @Override
    public void start(Stage primaryStage) {
        Pane root = new Pane();
        root.setStyle("-fx-background-color: lightgray");
        Scene scene = new Scene(root,800,600);
        primaryStage.setTitle("Basic Java FX");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
