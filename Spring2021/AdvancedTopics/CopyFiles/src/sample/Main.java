package sample;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.layout.*;
import javafx.scene.shape.*;
import javafx.scene.paint.Color;
import javafx.scene.*;
import javafx.scene.control.*;
import java.io.*;

class ErrorStage extends Stage
{
    Label lb;
    Button bn;
    Scene scene;
    Pane pane;
    ErrorStage(String err)
    {
        lb = new Label(err);
        bn = new Button("Ok");
        pane = new Pane();
        pane.getChildren().addAll(lb, bn);
        scene = new Scene(pane, 200, 150);
        bn.setLayoutX(85);
        bn.setLayoutY(60);
        lb.setTranslateX(65);
        lb.setTranslateY(30);
        setTitle("Error");
        setScene(scene);
        bn.setOnAction(e->close());
        show();
    }

}

class ResultsStage extends Stage
{
    Label lb;
    Button bn;
    Scene scene;
    Pane pane;
    ResultsStage(double results)
    {
        String res = Double.toString(results);
        lb = new Label("Number of bytes copied: "+res);
        bn = new Button("Ok");
        pane = new Pane();
        pane.getChildren().addAll(lb, bn);
        scene = new Scene(pane, 225, 150);
        bn.setLayoutX(85);
        bn.setLayoutY(60);
        lb.setTranslateX(40);
        lb.setTranslateY(30);
        setTitle("Success");
        setScene(scene);
        bn.setOnAction(e->close());
        show();
    }

}

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{

        GridPane root = new GridPane();
        Label lb1 = new Label("Source File: ");
        Label lb2 = new Label("Target File: ");
        TextField tf1 = new TextField("");
        TextField tf2 = new TextField("");
        Button bn1 = new Button("Copy");

        root.add(lb1, 0,0);
        root.add(lb2, 0,1);
        root.add(tf1, 1,0);
        root.add(tf2, 1,1);
        root.add(bn1, 1,2);

        root.setStyle("-fx-background-color: white");
        Scene scene = new Scene(root, 250, 150);
        primaryStage.setTitle("Copy File");
        primaryStage.setScene(scene);
        primaryStage.show();

        bn1.setOnAction(e->
                {
                    String sfile = tf1.getText();
                    String tfile = tf2.getText();
                    File sourceFile = new File(sfile);
                    File targetFile = new File(tfile);
                    if (!sourceFile.exists())
                    {
                        String err = "Source file " +sfile+" does not exist";
                        new ErrorStage(err);
                    }
                    if (!targetFile.exists())
                    {
                        String err = "Target file " +tfile+" does not exist";
                        new ErrorStage(err);
                    }
                    try (BufferedInputStream input = new BufferedInputStream(new FileInputStream(sourceFile));
                         BufferedOutputStream output = new BufferedOutputStream(new FileOutputStream(targetFile));)
                    {
                        int r, numberOfBytesCopied = 0;
                        while((r=input.read()) != -1){
                            output.write((byte) r);
                            numberOfBytesCopied++;
                        }
                        new ResultsStage(numberOfBytesCopied);
                    }
                    catch (IOException err){
                        System.out.println(err);
                    }
                });
    }
    public static void main(String[] args) {
        launch(args);
    }
}
