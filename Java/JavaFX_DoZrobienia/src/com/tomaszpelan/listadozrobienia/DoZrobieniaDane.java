package com.tomaszpelan.listadozrobienia;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Iterator;

public class DoZrobieniaDane {
    private static DoZrobieniaDane instancja = new DoZrobieniaDane();
    private static String plik = "listaRzeczy.txt";

    private ObservableList<DoZrobieniaItem> rzeczyDoZrobienia;
    private DateTimeFormatter formater;

    public static DoZrobieniaDane getInstance()
    {
        return instancja;
    }
    private DoZrobieniaDane()
    {
        formater = DateTimeFormatter.ofPattern("dd-MM-yyyy");
    }

    public void setRzeczyDoZrobienia(ObservableList<DoZrobieniaItem> rzeczyDoZrobienia) {
        this.rzeczyDoZrobienia = rzeczyDoZrobienia;
    }

    public ObservableList<DoZrobieniaItem> getRzeczyDoZrobienia() {
        return rzeczyDoZrobienia;
    }

    public void zaladujDoListy() throws IOException
    {
        rzeczyDoZrobienia = FXCollections.observableArrayList();
        Path sciezka = Paths.get(plik);
        BufferedReader bf = Files.newBufferedReader(sciezka);

        String input;

        try
        {
            while((input = bf.readLine()) != null)
            {
                String[] itemPieces = input.split("\t");

                String krotkiOpis = itemPieces[0];
                String detale = itemPieces[1];
                String data_ = itemPieces[2];
                LocalDate data = LocalDate.parse(data_,formater);
                DoZrobieniaItem rzecz = new DoZrobieniaItem(krotkiOpis,detale,data);
                rzeczyDoZrobienia.add(rzecz);
            }
        }finally {
            if(bf!=null)
                bf.close();
        }
    }
    public void przechowajRzeczy() throws IOException
    {
        Path sciezka = Paths.get(plik);
        BufferedWriter bw = Files.newBufferedWriter(sciezka);
        try
        {
            Iterator<DoZrobieniaItem> iterator = rzeczyDoZrobienia.iterator();
            while(iterator.hasNext())
            {
                DoZrobieniaItem rzecz = iterator.next();
                bw.write(String.format("%s\t%s\t%s\t",
                        rzecz.getKrotkiOpis(),rzecz.getDetale(),rzecz.getDeadLine().format(formater)
                        ));
                bw.newLine(); //przechodzi do nowej linii
            }
        }finally {
            if(bw != null)
                bw.close();
        }
    }

    public void dodajDoListy(DoZrobieniaItem item)
    {
        rzeczyDoZrobienia.add(item);
    }

    public void usunItem(DoZrobieniaItem item)
    {
        rzeczyDoZrobienia.remove(item);
    }
}
