package com.tomaszpelan.listadozrobienia;

import java.time.LocalDate;

public class DoZrobieniaItem {

    private String krotkiOpis;
    private String detale;
    private LocalDate deadLine;

    public String getKrotkiOpis() {
        return krotkiOpis;
    }

    public void setKrotkiOpis(String krotkiOpis) {
        this.krotkiOpis = krotkiOpis;
    }

    public String getDetale() {
        return detale;
    }

    @Override
    public String toString() {
        return krotkiOpis;
    }

    public void setDetale(String detale) {
        this.detale = detale;
    }

    public LocalDate getDeadLine() {
        return deadLine;
    }

    public void setDeadLine(LocalDate deadLine) {
        this.deadLine = deadLine;
    }

    public DoZrobieniaItem(String krotkiOpis, String detale, LocalDate deadLine) {
        this.krotkiOpis = krotkiOpis;
        this.detale = detale;
        this.deadLine = deadLine;
    }
}
