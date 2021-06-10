package com.tomaszpelan.listadozrobienia;

import javafx.application.Platform;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.transformation.FilteredList;
import javafx.collections.transformation.SortedList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.*;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.paint.Color;
import javafx.util.Callback;

import java.io.IOException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Comparator;
import java.util.List;
import java.util.Optional;
import java.util.function.Predicate;

public class Controller {
    @FXML
    private ListView<DoZrobieniaItem> listaRzeczyDoZrobieniaView;
    @FXML
    private TextArea detale;
    @FXML
    private Label podpisDeadLine;
    private List<DoZrobieniaItem> listaRzeczyDoZrobienia;
    @FXML
    private BorderPane glowneOknoBorderPane;
    @FXML
    ContextMenu listaMenuKontekstowych;
    @FXML
    ToggleButton filterToggleButton;

    private Predicate<DoZrobieniaItem> wszystkieZdarzenia;
    private Predicate<DoZrobieniaItem> tylkoDzisiejsze;

    private FilteredList<DoZrobieniaItem> filtrowanaLista;
            public void initialize()
            {
                listaMenuKontekstowych = new ContextMenu();
                MenuItem menuItem = new MenuItem("Usuń");
                menuItem.setOnAction(new EventHandler<ActionEvent>() {
                    @Override
                    public void handle(ActionEvent actionEvent) {
                        DoZrobieniaItem item = listaRzeczyDoZrobieniaView.getSelectionModel().getSelectedItem();
                        usunItem(item);
                    }
                });

                listaMenuKontekstowych.getItems().addAll(menuItem);
               /* DoZrobieniaItem rzecz1 = new DoZrobieniaItem("Projekt","Projekt z PK4",
                        LocalDate.of(2021, Month.NOVEMBER,2));
                DoZrobieniaItem rzecz2 = new DoZrobieniaItem("Urodziny","Urodziny braci",
                        LocalDate.of(2021, Month.NOVEMBER,1));
                DoZrobieniaItem rzecz3 = new DoZrobieniaItem("Ogród","Przewieźc rzeczy",
                        LocalDate.of(2021, Month.JUNE,15));
                DoZrobieniaItem rzecz4 = new DoZrobieniaItem("Poćwiczyć","Poćwiczyć brzuch",
                        LocalDate.of(2021, Month.MAY,18));
                DoZrobieniaItem rzecz5 = new DoZrobieniaItem("Odpocząć","Odpoacząć sobie po robocie",
                        LocalDate.of(2021, Month.JULY,10));
                listaRzeczyDoZrobienia = new ArrayList<>();
                listaRzeczyDoZrobienia.add(rzecz1);
                listaRzeczyDoZrobienia.add(rzecz2);
                listaRzeczyDoZrobienia.add(rzecz3);
                listaRzeczyDoZrobienia.add(rzecz4);
                listaRzeczyDoZrobienia.add(rzecz5);

                DoZrobieniaDane.getInstance().setRzeczyDoZrobienia(listaRzeczyDoZrobienia);*/





                listaRzeczyDoZrobieniaView.getSelectionModel().selectedItemProperty().addListener(new ChangeListener<DoZrobieniaItem>() {
                    @Override
                    public void changed(ObservableValue<? extends DoZrobieniaItem> observableValue, DoZrobieniaItem stara, DoZrobieniaItem nowa) {
                        if(nowa!=null)
                        {
                            DoZrobieniaItem rzecz = listaRzeczyDoZrobieniaView.getSelectionModel().getSelectedItem();
                            detale.setText(rzecz.getDetale());
                            DateTimeFormatter df = DateTimeFormatter.ofPattern("MMMM d ,yyyy");
                            podpisDeadLine.setText(df.format(rzecz.getDeadLine()));
                        }
                    }
                });

                tylkoDzisiejsze = new Predicate<DoZrobieniaItem>() {
                    @Override
                    public boolean test(DoZrobieniaItem doZrobieniaItem) {
                        return true;

                    }
                };
                tylkoDzisiejsze = new Predicate<DoZrobieniaItem>() {
                    @Override
                    public boolean test(DoZrobieniaItem doZrobieniaItem) {
                        return (doZrobieniaItem.getDeadLine().equals(LocalDate.now()));
                    }
                };


                filtrowanaLista = new FilteredList<>(DoZrobieniaDane.getInstance().getRzeczyDoZrobienia(),
                        wszystkieZdarzenia);
                SortedList<DoZrobieniaItem> sortedList = new SortedList<>(filtrowanaLista,
                        new Comparator<DoZrobieniaItem>() {
                            @Override
                            public int compare(DoZrobieniaItem o1, DoZrobieniaItem o2) {
                                return o1.getDeadLine().compareTo(o2.getDeadLine());
                            }
                        });



                //listaRzeczyDoZrobieniaView.setItems(DoZrobieniaDane.getInstance().getRzeczyDoZrobienia());
                listaRzeczyDoZrobieniaView.setItems(sortedList);
                listaRzeczyDoZrobieniaView.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
                listaRzeczyDoZrobieniaView.getSelectionModel().selectFirst();

                listaRzeczyDoZrobieniaView.setCellFactory(new Callback<ListView<DoZrobieniaItem>, ListCell<DoZrobieniaItem>>() {
                    @Override
                    public ListCell<DoZrobieniaItem> call(ListView<DoZrobieniaItem> doZrobieniaItemListView) {
                        ListCell<DoZrobieniaItem> itemki = new ListCell<>(){
                            @Override
                            protected void updateItem(DoZrobieniaItem doZrobieniaItem, boolean b) {
                                super.updateItem(doZrobieniaItem, b);
                                if(b)
                                {
                                    setText(null);
                                }
                                else
                                {
                                    setText(doZrobieniaItem.getKrotkiOpis());
                                    if(doZrobieniaItem.getDeadLine() == LocalDate.now())
                                        setTextFill(Color.RED);
                                    else if(doZrobieniaItem.getDeadLine().isBefore(LocalDate.now()))
                                        setTextFill(Color.BROWN);
                                    else if(doZrobieniaItem.getDeadLine().equals(LocalDate.now().plusDays(1)))
                                        setTextFill(Color.BLUE);
                                }
                            }
                        };
                        itemki.emptyProperty().addListener(
                                (obs,wasEmpty,isNowEmpty)->{
                                    if(isNowEmpty)
                                    {
                                        itemki.setContextMenu(null);
                                    }else
                                    {
                                        itemki.setContextMenu(listaMenuKontekstowych);
                                    }
                                }
                        );
                        return itemki;
                    }
                });
            }
            @FXML
            public void pokazOknoDialogoweNowejRzeczy()
            {
                Dialog<ButtonType> dialog = new Dialog<>();
                dialog.initOwner(glowneOknoBorderPane.getScene().getWindow());
                FXMLLoader fxmlLoader = new FXMLLoader();
                dialog.setTitle("Nowe wydarzenie");
                fxmlLoader.setLocation(getClass().getResource("oknoDialogoweDodawanie.fxml"));
                try{
                    dialog.getDialogPane().setContent(fxmlLoader.load());
                }catch(IOException e)
                {
                    System.out.println("Nie udało się załadować okna dialogowego");
                    e.printStackTrace();
                    return;
                }

                dialog.getDialogPane().getButtonTypes().add(ButtonType.OK);
                dialog.getDialogPane().getButtonTypes().add(ButtonType.CANCEL);

                Optional<ButtonType> result = dialog.showAndWait();
                if(result.isPresent() && result.get() == ButtonType.OK)
                {
                    DialogController controller = fxmlLoader.getController();
                    DoZrobieniaItem item = controller.przetworzRezultaty();
                    //listaRzeczyDoZrobieniaView.getItems().setAll(DoZrobieniaDane.getInstance().getRzeczyDoZrobienia());
                    listaRzeczyDoZrobieniaView.getSelectionModel().select(item); //po dodaniu nowej rzeczy od razu będzie się zaznaczać

                }
            }
            @FXML
            public void handlerWcisnietoPrzycisk(KeyEvent event)
            {
                DoZrobieniaItem wybrany = listaRzeczyDoZrobieniaView.getSelectionModel().getSelectedItem();
                if(wybrany!=null)
                {
                    if(event.getCode().equals(KeyCode.DELETE))
                    {
                        usunItem(wybrany);
                    }
                }
            }

            @FXML
            public void kliknietaWListe()
            {
                DoZrobieniaItem rzecz =listaRzeczyDoZrobieniaView.getSelectionModel().getSelectedItem();
               detale.setText(rzecz.getDetale());
               podpisDeadLine.setText(rzecz.getDeadLine().toString());
               /* StringBuilder sb = new StringBuilder(rzecz.getDetale());
                sb.append("\n\n\n\n");
                sb.append("Do:");
                sb.append(rzecz.getDeadLine());*/


            }

            public void usunItem(DoZrobieniaItem item)
            {
                Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
                alert.setTitle("Usuń wydarzenie");
                alert.setHeaderText("Usuwany element: " + item.getKrotkiOpis());
                alert.setContentText("Czy na pewno chcesz usunąć to wydarzenie?");
                Optional<ButtonType> rezultat = alert.showAndWait();// do obsłużenia rezultatu kliknięcia w oknie

                if(rezultat.isPresent() && (rezultat.get() == ButtonType.OK))
                {
                    DoZrobieniaDane.getInstance().usunItem(item);
                }
            }
            @FXML
            public void handlerToggleButton()
            {
                DoZrobieniaItem wybrany = listaRzeczyDoZrobieniaView.getSelectionModel().getSelectedItem();

                if(filterToggleButton.isSelected())
                {
                        filtrowanaLista.setPredicate(tylkoDzisiejsze);
                        if(filtrowanaLista.isEmpty())
                        {
                            detale.clear();
                            podpisDeadLine.setText("");
                        }
                        else if(filtrowanaLista.contains(wybrany)) {
                            listaRzeczyDoZrobieniaView.getSelectionModel().select(wybrany);
                        }
                        else {
                            listaRzeczyDoZrobieniaView.getSelectionModel().selectFirst();
                        }
                }
                else {
                    filtrowanaLista.setPredicate(wszystkieZdarzenia);
                    listaRzeczyDoZrobieniaView.getSelectionModel().select(wybrany);
                }
            }
            @FXML
            public void handlerWyjscia()
            {
                Platform.exit();
             }
}
