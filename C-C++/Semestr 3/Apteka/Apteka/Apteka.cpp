// Apteka.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include "klasy_i_funkcje.h"
using namespace std;


int main(int argc, char* argv[])
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // wycieki pamieci byly sprawdzane
	Lista_Objawow glowa;
	Lista_Objawow nowa_glowa(glowa);
	//Lista_lekow pHead;
	//
	//	string nazwa_pliku;

	//	if (argc <= 2)
	//	{
	//		bool czy_poprawny_plik_z_lekami = pHead.odczytaj_z_pliku_lekow(pHead);
	//		bool czy_poprawny_plik_z_objawami = glowa.odczytaj_z_pliku_objawow(glowa);
	//		if (!czy_poprawny_plik_z_lekami || !czy_poprawny_plik_z_objawami)
	//			return -1;
	//	}
	//	else
	//	{
	//		for (int i = 0; i < argc; ++i)
	//		{
	//			nazwa_pliku = argv[i];
	//			if (argv[i] == "-i")
	//			{
	//				nazwa_pliku = argv[i + 1];
	//				i++;

	//			}
	//			
	//		}
	//		bool czy_poprawny_plik_z_lekami = pHead.odczytaj_z_pliku_lekow(pHead,nazwa_pliku);
	//		bool czy_poprawny_plik_z_objawami = glowa.odczytaj_z_pliku_objawow(glowa);
	//		if (!czy_poprawny_plik_z_lekami || !czy_poprawny_plik_z_objawami)
	//			return -1;

	//	}
	//
	//	Powitanie witaj;
	//cout << witaj.getPowitanie() << endl;

	//glowa.wypisz_liste_objawow(); //funkcja wypisuje wszystkie objawy na ekran konsoli
	//cout << endl;

	//cout << "Prosze wybrac objaw z listy,ktory Pana/Pania dotyczy:";

	//int input_uzytkownika;
	//cin >> input_uzytkownika;
	//while ((input_uzytkownika <= 0) || (input_uzytkownika > glowa.licznik)) //nazwa obiawu nie może być ujemna ,ale nie można też wybrać objawu spoza listy!
	//{
	//	cout << "Prosze wybrac numer dostepny w liscie objawow." << endl;
	//	cin >> input_uzytkownika;
	//}
	//
	//cout << endl;
	//string imie, nazwisko;
	//int wiek;						
	//cout << "Prosze podac imie:";
	//cin >> imie;
	//cout << "Prosze podac nazwisko:";
	//cin >> nazwisko;
	//cout << "Prosze podac wiek:";
	//cin >> wiek;
	//
	//obsloz_pacjenta(imie, nazwisko, wiek, input_uzytkownika, pHead, glowa); //funkcja ktora obslozy pacjenta w zdalnej aptece
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
