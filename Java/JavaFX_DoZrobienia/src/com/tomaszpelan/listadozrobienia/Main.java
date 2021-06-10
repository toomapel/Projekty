package com.tomaszpelan.listadozrobienia;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class Main extends Application {

    @Override
    public void stop() throws Exception {
        try{
            DoZrobieniaDane.getInstance().przechowajRzeczy();
        }catch (IOException e)
        {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void init() throws Exception {
        try{
           DoZrobieniaDane.getInstance().zaladujDoListy();
        }catch (IOException e)
        {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("OknoGlowne.fxml"));
        primaryStage.setTitle("Co jest do zrobienia?");
        primaryStage.setScene(new Scene(root, 900, 500));
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}
