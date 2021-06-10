#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"
#include "struktury.h"
#include <Windows.h>

int main()
{
	struct kategorie* pHead = NULL;
	int licznik_kategorii = 0;
	
	if(odczytaj_z_pliku(&pHead, &licznik_kategorii) == 0) //sprawdzenie czy odczyt sie uda³
		return EXIT_FAILURE;
	int wybor_po_grze = 0; //wybory króre u¿ytkownik bedzie podawa³ 
	int wybor = 0;
	do {
		menu_glowne();					//wyœwietla menu g³ówne gry
		int poprawny = scanf("%d", &wybor);			//pobiera informacje
		while (poprawny!=1 || wybor < 1 || wybor > 2  )	//zabezpieczenie przed niew³aœciwym wyborem
		{
			rewind(stdin);
			printf("\n");
			printf("Nieprawidlowe dane.Wybierz 1 lub 2.\n");
			printf("Twoj wybor:");
			poprawny = scanf("%d", &wybor);
			
			
		}
		system("cls");					//estetyczne czyszczenie konsoli
		if (wybor == 1)
		{
			system("cls");
			gra_losowa(pHead, licznik_kategorii); //wyswietla gre z losowaniem zarowno kategorii jak i has³a

		}
		else
		{
			int wybor_kategorii = 0;
			printf("Wybierz kategorie:\n");
			printf("\n");
			wypisz_kategorie(pHead, licznik_kategorii); //wypisuje kategorie
			printf("\n");
			printf("Twoj wybor:");
			poprawny = scanf("%d", &wybor_kategorii);										//pobiera informacje
			while (poprawny!=1 || wybor_kategorii < 1 || wybor_kategorii>licznik_kategorii)	//zabezpieczenie przed niew³aœciwym wyborem
			{
				rewind(stdin);
				printf("\n");
				printf("Nieprawidlowe dane.Wybierz numer kategorii z listy.\n");
				printf("Twoj wybor:");
				poprawny = scanf("%d", &wybor_kategorii);  //pobiera informacje ponownie
			}
			system("cls");
			gra_z_wyborem_kategorii(pHead, wybor_kategorii);	//wyswietla gre z wyborem kategorii
		}

		menu_po_grze();		
		poprawny = scanf("%d", &wybor_po_grze);					//pobiera informacje
		while (poprawny!=1 || wybor_po_grze < 1 || wybor_po_grze>2)	//zabezpieczenie przed niew³aœciwym wyborem
		{
			rewind(stdin);
			printf("\n");
			printf("Nieprawidlowe dane.Wybierz 1 lub 2.\n");
			printf("Twoj wybor:");
			poprawny = scanf("%d", &wybor);
		}
		system("cls");
	} while (wybor_po_grze != 2);

	usun_liste(&pHead); //usuwanie listy
	
	return 0;



}