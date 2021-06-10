#include <fstream>
#include <iostream>

using namespace std;

/*
Funkcja odczytuje z pliku potrzebne informacje o planie lekcji nauczycieli
@param nazwa_pliku jest to nazwa pliku wejsciowego programu
@param pHead wskaznik na pierwszy element listy nauczycieli
*/
bool odczytajZPliku(string nazwa_pliku, nauczyciel*& pHead);//odczytuje z pliku tesktowego informacje
/* 
Funkcja dodaje odczytanego nauczyciela do listy nauczycieli
@param pHead wskaznik na pierwszy element listy nauczycieli
@param nazwisko nazwisko nauczyciela
@param godzina_rozpoczecia godzina rozpoczecia lekcji
@param minuta_rozpoczenia minuta rozpoczecia lekcji
@param godzina_zakonczenia godzina zakonczenia lekcji
@param minuta_zakonczenia minuta zakonczenia lekcji
@param dzien dzien odbycia sie lekcji
@param grupa grupa z która nauczyciel ma lekcje
@param przedmiot przedmiot z którego prowadzona jest lekcja
*/
void dodajDoListy(nauczyciel*& pHead,string nazwisko, int godzina_rozpoczecia, int minuta_rozpoczecia, int godzina_zakonczenia, int minuta_zakonczenia, string dzien, string grupa, string przedmiot);
/* 
Funkcja wypisuje po kolei kazda podliste do osobnego pliku, a nastepnie usuwa 
@param pHead wskaznik na pierwszy element listy nauczycieli*/
void wypiszListeIUsun(nauczyciel* pHead,bool &poprawnyOdczyt); 
/*
Funkcja dodaje zajêcie konkretnemu nauczycielowi
@param nauczyciel wskaznik na nauczyciela któremu chcemy dodac zajêcie
@param godzina_rozpoczecia godzina rozpoczecia lekcji
@param minuta_rozpoczenia minuta rozpoczecia lekcji
@param godzina_zakonczenia godzina zakonczenia lekcji
@param minuta_zakonczenia minuta zakonczenia lekcji
@param dzien dzien odbycia siê lekcji
@param grupa grupa z ktora nauczyciel ma lekcje
@param przedmiot przedmiot z którego prowadzona jest lekcja
*/
void dodajZajecie(nauczyciel*& nauczyciel, int godzina_rozpoczecia, int minuta_rozpoczecia, int godzina_zakonczenia, int minuta_zakonczenia, string dzien, string grupa, string przedmiot);
/* 
Funkcja znajduje nauczyciela po jego nazwisku i zwraca wskaznik na niego
@param pHead wskaznik na pierwszy element listy nauczycieli
@param nazwisko nazwisko nauczyciela ktorego chcemy wyszukac
@return wskaznik do nauczyciela*/
nauczyciel* znajdzNauczyciela(nauczyciel* pHead, string nazwisko);
/* 
Funkcja sortuje zajecia chronologicznie:(dzien -> godzina rozpoczecia -> godzina zakonczenia)
@param pHead wskaznik na pierwszy element listy nauczycieli
*/



