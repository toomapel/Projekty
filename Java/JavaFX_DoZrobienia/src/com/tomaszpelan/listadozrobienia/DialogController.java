package com.tomaszpelan.listadozrobienia;

import javafx.fxml.FXML;
import javafx.scene.control.DatePicker;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

import java.time.LocalDate;

public class DialogController {
    @FXML
        private TextField krotkiOpisTextField;
    @FXML
        private TextArea detaleTextField;
    @FXML
        private DatePicker dataPicker;

    public DoZrobieniaItem przetworzRezultaty()
    {
        String krotkiOpis = krotkiOpisTextField.getText();
        String detale = detaleTextField.getText();
        LocalDate data = dataPicker.getValue();
        DoZrobieniaItem nowy = new DoZrobieniaItem(krotkiOpis,detale,data);
        DoZrobieniaDane.getInstance().dodajDoListy(nowy);

        return nowy;
    }
}
