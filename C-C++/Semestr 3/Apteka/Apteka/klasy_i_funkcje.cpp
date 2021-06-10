#include <iostream>
#include <fstream>
#include "klasy_i_funkcje.h"
using namespace std;

Lek::Lek():
	nazwa(""),
	id(0),
	koszt(0),
	wiek_min(0),
	wiek_max(0),
	czy_na_recepte(false),
	pNext(nullptr)
{}
void Lek::wyluskaj_informacje(ofstream& plik)
{
	plik<<"Nie ma informacji czy recepta jest potrzebna";
	plik << endl;
}
void Lek_na_recepte::wyluskaj_informacje(ofstream& plik)
{
	plik << "Lek wymaga recepty!" << endl;
	plik << endl;
}
void Lek_bez_recepty::wyluskaj_informacje(ofstream& plik)
{
	plik << "Lek dostepny od reki!" << endl;
	plik << endl;
}

Lista_lekow::Lista_lekow() :pHead(nullptr)
{}
Lista_lekow::~Lista_lekow()
{
	while (pHead)
	{
		Lek* pomocniczy = pHead;
		pHead = pHead->pNext;
		delete pomocniczy;
	}
}

Lista_lekow::Lista_lekow(const Lista_lekow& lista) = default;

void Lista_lekow::operator +=(Lek* lek)
{
	lek->pNext = pHead;
	pHead = lek;
}

void Lista_lekow::wypisz_liste_lekow() const
{
	Lek* pom = pHead;
	while (pom)
	{
		cout << "LEK" << endl;
		cout << "Nazwa: " << pom->nazwa << endl;
		cout << "ID: " << pom->id << endl;
		cout << "Wiek min: " << pom->wiek_min << endl;
		cout << "Wiek max: " << pom->wiek_max << endl;
		cout << "Koszt: " << pom->koszt << endl;
		

		cout << endl;
		cout << endl;
		pom = pom->pNext;
	}
}

void Lista_lekow::wyszukaj_lek(int szukane_id, int wiek_pacjenta,ofstream& plik, bool& czyCokolwiekZnaleziono)
{
	
	Lek* wsk = pHead;
	while (wsk)
	{
		if ((szukane_id == wsk->id) && (wsk->wiek_min <= wiek_pacjenta) && (wsk->wiek_max >= wiek_pacjenta)) //je¿eli lek pasuje id i jest dopasowany wiekowo
		{

			plik << "LEK" << endl;
			plik <<"Nazwa:"<<wsk->nazwa << endl;
			plik << "Koszt:" << wsk->koszt << " zl" << endl;
			wsk->wyluskaj_informacje(plik); //zwraca informacje,czy lek jest na recepte,czy nie
			czyCokolwiekZnaleziono = true;
			break;
		}
		wsk = wsk->pNext;
	}
}

bool Lista_lekow::odczytaj_z_pliku_lekow(Lista_lekow& pHead,string nazwa_pliku)
{

	fstream plik;
	plik.open(nazwa_pliku, ios::in);
	if (plik)
	{
		if (plik.peek() != std::ifstream::traits_type::eof()) //sprawdzenie,czy plik jest pusty
		{
			char czy_na_recepte;
			while (!plik.eof())
			{

				plik >> czy_na_recepte;
				if (czy_na_recepte == 'r')
				{
					Lek* p = new Lek_na_recepte();
					p->czy_na_recepte = true;
					
					plik >> p->nazwa >> p->id >> p->koszt >> p->wiek_min >> p->wiek_max; //czytanie do atrybutów obiektu z pliku

					pHead += p; //dodanie do listy nowego leku
				}
				else
				{
					Lek* p = new Lek_bez_recepty();
					p->czy_na_recepte = false;
					
					plik >> p->nazwa >> p->id >> p->koszt >> p->wiek_min >> p->wiek_max; //czytanie do atrybutów obiektu z pliku

					pHead += p; //dodanie do listy nowego leku
				}

			}
			plik.close();
			return true;
		}
		else {

			cout << "Plik z lekami jest pusty!";
			return false; 

		}

	}
	else {

		cout << "Nie udalo sie poprawnie otworzyc pliku z lekami!";
		return false;
		
	}

}


Objaw::Objaw() :nazwa("objaw"), pNext(nullptr), lista_id(nullptr)
{}
void Objaw::dodaj_id(int x)
{
	id* pNowy = new id;
	pNowy->pNext = lista_id;
	pNowy->id = x;
	lista_id = pNowy;
}
Objaw::~Objaw()
{

	while (lista_id)
	{
		id* pomocniczy = lista_id;
		lista_id = lista_id->pNext;
		delete pomocniczy;
	}


}






Lista_Objawow::Lista_Objawow(const Lista_Objawow& ob):pHead(ob.pHead),licznik(ob.licznik)
{
	cout << "Konstruktor kopiujacy zostal uzyty!" << endl;
}





















Lista_Objawow::Lista_Objawow() :pHead(nullptr), licznik(0)
{}
Lista_Objawow::~Lista_Objawow()
{
	while (pHead)
	{
		Objaw* pomocniczy = pHead;
		pHead = pHead->pNext;
		delete pomocniczy;
	}
}
void Lista_Objawow::operator+=(Objaw* o)
{
	o->pNext = pHead;
	pHead = o;
}
void Lista_Objawow::wypisz_liste_objawow()
{
	Objaw* pom = pHead;
	for (int i = 1; i <= licznik; i++)
	{
		string bufor = pom->nazwa;
		for (int j = 0; j < bufor.length(); j++) //pêtla s³u¿y zamianie ewentualnych podkreslen na spacje,by ³adniej wypisywaæ te dane w programie
		{
			if (bufor[j] == '_')
				bufor[j] = ' ';
		}
		cout << i << "." << bufor << endl;
		pom = pom->pNext;
	}
}
bool Lista_Objawow::odczytaj_z_pliku_objawow(Lista_Objawow& pHead)
{

	fstream plik;
	plik.open("objawy.txt", ios::in);
	if (plik)
	{
		if (plik.peek() != std::ifstream::traits_type::eof()) //sprawdzenie czy plik jest pusty
		{
			while (!plik.eof())
			{
				Objaw* p = new Objaw();

				plik >> p->nazwa; //najpierw czytamy nazwe
				int id_dodawane = 0;

				while (true)
				{
					plik >> id_dodawane; //nastêpnie czytamy id dodawanych leków a¿ do napotkania -1
					if (id_dodawane == -1)
						break; //jeœli napotkamy -1 to wychodzimy z pêtli dodawania
					else
					{
						p->dodaj_id(id_dodawane);
					}
				}
				pHead += p; //dodajemy nowy obiaw do listy obiawów
				pHead.licznik++; //inkrementujemy licznik obiawów
			}
			plik.close();
			return true;
		}
		else
		{
			cout << "Plik z objawami jest pusty!";
			return false;

		}


	}
	else
	{
		cout << "Nie udalo sie poprawnie otworzyc pliku z objawami!";
		return false;

	}

}

Powitanie::Powitanie() :tresc(new char[strlen("Witaj w zdalnej aptece") + 1])
{
	strcpy_s(tresc, strlen("Witaj w zdalnej aptece") + 1, "Witaj w zdalnej aptece");
}
Powitanie::~Powitanie()
{
	delete [] tresc;
}
char* Powitanie::getPowitanie()
{
	return tresc;
}
void obsloz_pacjenta(string imie, string nazwisko, int wiek, int wybor, Lista_lekow& pHead_leki, Lista_Objawow& pHead_objawy)
{
	bool czyCokolwiekZnaleziono = false;
	Objaw* pom = pHead_objawy.pHead;
	for (int i = 0; i < wybor - 1; i++)
	{
		pom = pom->pNext;		//na podstawie wyboru numeru objawu pacjenta,przestawiam wskaŸnik na dany obiaw
	}

	string nazwa_pliku = nazwisko + "_" + imie + ".txt";	//plik wyjœciowy zostanie nazwany nazwiskiem i imieniem pacjenta
	ofstream plik_wyjsciowy;
	plik_wyjsciowy.open(nazwa_pliku, ios::out);
	if (plik_wyjsciowy)
	{
		plik_wyjsciowy << "Oto lista lekow na " << pom->nazwa << ":" << endl;
	}
	id* wsk = pom->lista_id;
	while (wsk)
	{
		pHead_leki.wyszukaj_lek(wsk->id, wiek, plik_wyjsciowy,czyCokolwiekZnaleziono);	// nastêpnie od danego objawu wychodzi lista leków przeciwdzia³aj¹cym mu
		wsk = wsk->pNext;																//wiêc szukam pasuj¹cego obiawem i wiekiem leku
	}
	if(!czyCokolwiekZnaleziono)
		{
			plik_wyjsciowy<<"Nie udalo sie znalezc leku na podany objaw."<<endl;	//jeœli nic nie znaleziono zostanie wyœwietlony komunikat
		}
	plik_wyjsciowy.close();
}
