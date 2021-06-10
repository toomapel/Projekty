
#include <iostream>
using namespace std;


struct lekcja //struktura zawierajaca skladowe lekcji oraz wskaznik
{

	int godzina_rozpoczecia, minuta_rozpoczecia;
	int godzina_zakonczenia, minuta_zakonczenia;
	string dzien, grupa,przedmiot;
	lekcja* nastepny;
};
struct nauczyciel
{
	string nazwisko;
	lekcja* pLekcje;
	nauczyciel* nastepny;
};