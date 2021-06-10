#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <direct.h>
#include "struktury.h"
#include "funkcje.h"


using namespace std;

void odczytajZPliku(string nazwa_pliku, nauczyciel*& pHead)
{
	bool poprawnyOdczyt = true;
	int godzina_rozpoczecia, minuta_rozpoczecia;
	int godzina_zakonczenia, minuta_zakonczenia;
	string dzien, grupa, nazwisko, przedmiot,linia;
	
	char znak;
	fstream plik;
	if (nazwa_pliku.find(".txt") == string::npos) //jezeli nie znaleziono odpowiedniego rozszerzenia pliku , dodajemy je
	{
		nazwa_pliku += ".txt";
	}

	plik.open(nazwa_pliku);
	if (plik.is_open())       //sprawdzenie czy plik zostal poprawnie otwarty
	{
		plik.seekg(0, ios::end); //ustawia kursor na koncu pliku
		if (plik.tellg() == 0) //sprawdza czy poczatkowe polozenie nie jest rowne koncowemu
			cout << "Plik jest pusty";
		else
		{
			plik.seekg(0, ios::beg); //jesli OK , ustawiamy kursor z powrotem na poczatku pliku
			while (!plik.eof())   //petla wczytywania z pliku
			{
			
				plik >> godzina_rozpoczecia;
				if (!godzina_rozpoczecia)
				{
					cout << "Nieprawidlowe dane";
					poprawnyOdczyt = false;
					//break;
				}
				if (!plik)
					break;
				plik >> znak >> minuta_rozpoczecia >> znak >> godzina_zakonczenia >> znak >> minuta_zakonczenia >> dzien >> grupa >> nazwisko >> przedmiot; //wczytywanie do elemtow struktury
				if (dzien.empty() or grupa.empty() or nazwisko.empty() or przedmiot.empty()) //sprawdzanie poprawnosci danych
				{
					cout << "Nieprawidlowe dane";
					poprawnyOdczyt = false;
					break;
				}

				dodajDoListy(pHead,nazwisko,godzina_rozpoczecia,minuta_rozpoczecia,godzina_zakonczenia,minuta_zakonczenia,dzien,grupa,przedmiot);
				

			}
		}
	}
	else {
		cout << "Nie udalo sie poprawnie otworzyc pliku";
	}

	return poprawnyOdczyt;
}

void dodajDoListy(nauczyciel*& pHead,string nazwisko, int godzina_rozpoczecia, int minuta_rozpoczecia, int godzina_zakonczenia, int minuta_zakonczenia, string dzien, string grupa, string przedmiot)
{
	auto p = znajdzNauczyciela(pHead, nazwisko);
	if (p == nullptr)
	{
		nauczyciel* pNowy = new nauczyciel;
		pNowy->nastepny = pHead; 
		pHead = pNowy;
		
		pNowy->pLekcje = nullptr;
		pNowy->nazwisko = nazwisko;
		dodajZajecie(pHead, godzina_rozpoczecia, minuta_rozpoczecia, godzina_zakonczenia, minuta_zakonczenia, dzien, grupa, przedmiot);
		
	}
	else
	{
		
		dodajZajecie(p, godzina_rozpoczecia, minuta_rozpoczecia, godzina_zakonczenia, minuta_zakonczenia, dzien, grupa, przedmiot);
		
		

	}


}
nauczyciel* znajdzNauczyciela(nauczyciel* pHead, string nazwisko) //dziala
{
	if (pHead)
	{
		if (pHead->nazwisko == nazwisko)
			return pHead;
		else
			return  znajdzNauczyciela(pHead->nastepny, nazwisko);
	}
	else 
		return nullptr;

}

void dodajZajecie(nauczyciel*&Nauczyciel, int godzina_rozpoczecia, int minuta_rozpoczecia, int godzina_zakonczenia, int minuta_zakonczenia, string dzien, string grupa, string przedmiot)
{
	



		int pomocnicza = 0;
		if (dzien == "pn")
		{
			pomocnicza += 10000;
		}
		else if (dzien == "wt")
		{
			pomocnicza += 20000;
		}
		else if (dzien == "sr")
		{
			pomocnicza += 30000;
		}
		else if (dzien == "cz")
		{
			pomocnicza += 40000;
		}
		else if (dzien == "pt")
		{
			pomocnicza += 50000;
		}
		pomocnicza += (godzina_rozpoczecia) * 100;
		pomocnicza += (minuta_rozpoczecia);

		if (Nauczyciel->pLekcje == nullptr or Nauczyciel->pLekcje->godzina_rozpoczecia > pomocnicza)
		{
			
			lekcja* pNowa = new lekcja;
		pNowa->nastepny = Nauczyciel->pLekcje;
		Nauczyciel->pLekcje = pNowa;
		pNowa->dzien = dzien;
		pNowa->godzina_rozpoczecia = pomocnicza;
		pNowa->godzina_zakonczenia = godzina_zakonczenia;
		pNowa->grupa = grupa;
		pNowa->minuta_rozpoczecia = minuta_rozpoczecia;
		pNowa->minuta_zakonczenia = minuta_zakonczenia;
		pNowa->przedmiot = przedmiot;

		}
		else
		{
			auto p = Nauczyciel->pLekcje;
			while (p->nastepny and p->nastepny->godzina_rozpoczecia < pomocnicza)
				p = p->nastepny;

			lekcja* pNowa = new lekcja;
			pNowa->nastepny = p->nastepny;
			p->nastepny = pNowa;
			pNowa->dzien = dzien;
			pNowa->godzina_rozpoczecia = pomocnicza;
			pNowa->godzina_zakonczenia = godzina_zakonczenia;
			pNowa->grupa = grupa;
			pNowa->minuta_rozpoczecia = minuta_rozpoczecia;
			pNowa->minuta_zakonczenia = minuta_zakonczenia;
			pNowa->przedmiot = przedmiot;
		}






		
		
		
	
}



void wypiszListeIUsun(nauczyciel* pHead,bool& poprawnyOdczyt)
{
	
	while (pHead)
	{
		ofstream plik;
		if (poprawnyOdczyt == 1)
		{
			
			_mkdir("planyLekcji");
			plik.open("planyLekcji/" + pHead->nazwisko + ".txt");
		}
		while (pHead->pLekcje)
		{
			if(poprawnyOdczyt==1)
			{
			pHead->pLekcje->godzina_rozpoczecia = (pHead->pLekcje->godzina_rozpoczecia % 10000) / 100;
			if (pHead->pLekcje->godzina_rozpoczecia < 10)
			{
				plik << "0" << pHead->pLekcje->godzina_rozpoczecia;
			}
			else
				plik << pHead->pLekcje->godzina_rozpoczecia;
			plik << ":";
			if (pHead->pLekcje->minuta_rozpoczecia < 10)
			{
				plik << "0" << pHead->pLekcje->minuta_rozpoczecia;
			}
			else
				plik << pHead->pLekcje->minuta_rozpoczecia;
			plik << "-";
			if (pHead->pLekcje->godzina_zakonczenia < 10)
			{
				plik << "0" << pHead->pLekcje->godzina_zakonczenia;
			}
			else
				plik << pHead->pLekcje->godzina_zakonczenia;
			plik << ":";
			if (pHead->pLekcje->minuta_zakonczenia < 10)
			{
				plik << "0" << pHead->pLekcje->minuta_zakonczenia;
			}
			else
				plik << pHead->pLekcje->minuta_zakonczenia;




			plik << " " << pHead->pLekcje->dzien << " " << pHead->pLekcje->grupa << " " << pHead->pLekcje->przedmiot << endl;
		}
			auto p = pHead->pLekcje;
			pHead->pLekcje = pHead->pLekcje->nastepny;

			delete p;
		}
		plik.close();
		auto q = pHead;
		pHead = pHead->nastepny;

		delete q;
	}
}




	
	
	

