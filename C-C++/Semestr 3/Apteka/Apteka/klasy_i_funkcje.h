#pragma once
#include <iostream>

class Lista_lekow;
class Lista_Objawow;



class Lek
{
	
	friend class Lista_lekow;
private:
	Lek* pNext;
	std::string nazwa;
	int id;
	int koszt;
	int wiek_min, wiek_max;
	bool czy_na_recepte;

public:
	Lek();
	virtual void wyluskaj_informacje(std::ofstream& plik);
	
	friend void obsloz_pacjenta(std::string imie, std::string nazwisko, int wiek, int wybor,Lista_lekow& pHead_leki, Lista_Objawow& pHead_objawy);

};

class Lek_na_recepte : public Lek
{

public:

	void wyluskaj_informacje(std::ofstream& plik);

};
class Lek_bez_recepty : public Lek
{

public:

	void wyluskaj_informacje(std::ofstream& plik);

};

class Lista_lekow
{
	

public:
	Lek* pHead;


	Lista_lekow();
	~Lista_lekow();
	Lista_lekow(const Lista_lekow& lista);
	void operator +=(Lek* lek);
	void wypisz_liste_lekow() const;
	void wyszukaj_lek(int szukane_id, int wiek_pacjenta, std::ofstream& plik,bool &czyCokolwiekZnaleziono);
	bool odczytaj_z_pliku_lekow(Lista_lekow& pHead,std::string nazwa_pliku = "leki.txt");

	friend class Lek;
	friend void obsloz_pacjenta(std::string imie, std::string nazwisko, int wiek, int wybor, Lista_lekow& pHead_leki, Lista_Objawow& pHead_objawy);
};

struct id
{
	int id;
	struct id* pNext;
};

class Objaw
{
	
	friend class Lista_Objawow;

private:
	std::string nazwa;
	Objaw* pNext;
	id* lista_id;

public:
	Objaw();
	~Objaw();
	void dodaj_id(int x);

	friend void obsloz_pacjenta(std::string imie, std::string nazwisko, int wiek, int wybor, Lista_lekow& pHead_leki, Lista_Objawow& pHead_objawy);
};






class Lista_Objawow
{
	

public:
	Objaw* pHead;
	int licznik;

	Lista_Objawow();
	Lista_Objawow(const Lista_Objawow& ob); //konstruktor kopiuj¹cy
	~Lista_Objawow();
	void operator+=(Objaw* o);
	void wypisz_liste_objawow();
	bool odczytaj_z_pliku_objawow(Lista_Objawow& pHead);

	friend void obsloz_pacjenta(std::string imie, std::string nazwisko, int wiek, int wybor, Lista_lekow& pHead_leki, Lista_Objawow& pHead_objawy);
	
};















class Powitanie
{
	char* tresc;
public:
	Powitanie();
	~Powitanie();
	char* getPowitanie();
};

void obsloz_pacjenta(std::string imie, std::string nazwisko, int wiek, int wybor, Lista_lekow& pHead_leki, Lista_Objawow& pHead_objawy);

