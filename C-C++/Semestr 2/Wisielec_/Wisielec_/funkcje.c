#include "struktury.h"
#include "funkcje.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_ROZMIAR 30


void dodaj_do_listy(struct kategorie** pHead, char* slowo, FILE * plik) //dodawanie na pocz�tek iteracyjnie
{

	
	struct kategorie* pNowy = (struct kategorie*)malloc(sizeof(struct kategorie)); //utworzernie nowej kategorii
	char bufor[MAX_ROZMIAR]; //bufor do odczytu z pliku
	pNowy->kategoria = malloc(strlen(slowo) + 1); //mallocuje pami�� na kategorie
	strcpy(pNowy->kategoria, slowo); //kopiuje odczytane s�owo do szufladki z kategori�
	pNowy->licznik_hasel = 0; //inicjalizacja licznika hase�(potrzebny do losowania)
	pNowy->pHasla = NULL; //na razie hase� nie wczytalem , wi�c wska�nik na has�a jest 
	pNowy->pNext = (*pHead); //przestawienie wska�nik�w 
	(*pHead) = pNowy;
	while (1)
	{
		

		fscanf(plik, "%s", bufor); // skanuje z pliku w poszukiwaniu hase�
		if (strcmp(bufor, ",") == 0) //program po przecinku poznaje koniec linii
			break;
		else
		{
			dodaj_haslo(&(pNowy->pHasla),bufor); //je�li nie koniec, to dodaje nowe has�o do danej kategorii
			(pNowy->licznik_hasel)++; //i inkrementuje licznik hase�
		}

	}
	


}

void dodaj_haslo(struct hasla** pHead,char * bufor) //dodawanie na pocz�tek iteracyjnie
{
	
	struct hasla* pNowy = (struct hasla*)malloc(sizeof(struct hasla)); //nowe has�o
	pNowy->haslo = malloc(strlen(bufor) + 1); //mallocuje pami�� na has�o
	strcpy(pNowy->haslo, bufor); //kopiuje odczytane has�o 
	pNowy->pNext = (*pHead); //przestawienie wska�nik�w
	(*pHead) = pNowy;

}


void wypisz_kategorie(struct kategorie* pHead,int licznik)
{
	for (int i = 0; i < licznik; i++)
	{
		printf("%d.", i + 1);
		printf("%s\n", pHead->kategoria);
		pHead = pHead->pNext;

	}

}

int odczytaj_z_pliku(struct kategorie** pHead, int* licznik_kategorii) //zwarca 1 jesli odczyt jest poprawny , 0 jesli nie
{
	FILE* plik_wejsciowy;
	plik_wejsciowy = fopen("plik.txt", "r"); //otwarcie pliku w trybie do odczytu
	if (plik_wejsciowy)
	{
		char napis[30];
		while (fscanf(plik_wejsciowy, "%s", napis) == 1) //odczytanie z pliku kategorii
		{
			(*licznik_kategorii)++; //inkrementacja licznika kategorii
			dodaj_do_listy(pHead, napis,plik_wejsciowy); //dodaje kategorie do listy kategorii
			
		}

		fclose(plik_wejsciowy); //zamkni�cie pliku
		return 1; //zwraca czy odczyt by� poprawny
	}
	else {
		printf("Nie udalo sie poprawnie otworzyc pliku."); //zwraca czy odczyt by� poprawny
		return 0;
		}



}

void gra_losowa(struct kategorie* pHead, int licznik_kategorii)
{
	srand(time(NULL));
	int losowa_kategoria = rand() % (licznik_kategorii); //losuje kategorie
	
	for (int i = 0; i < losowa_kategoria; i++)
	{
		pHead = pHead->pNext; //tyle razy ile wylosowa�em przesuwam si� po li�cie kategorii
	}
	int losowe_haslo = rand() % (pHead->licznik_hasel); //losuje has�o
	for (int i = 0; i < losowe_haslo; i++) 
	{
		pHead->pHasla = pHead->pHasla->pNext; ////tyle razy ile wylosowa�em przesuwam si� po li�cie hase�
	}

	graj(pHead->pHasla->haslo, pHead->kategoria); //inicjalizacja gry

}

void gra_z_wyborem_kategorii(struct kategorie* pHead,int kategoria)
{
	srand(time(NULL));
	

	for (int i = 0; i < (kategoria-1); i++) //kategorie dostaje z g�ry , musze tylko wylosowa� has�o
	{
		pHead = pHead->pNext;
	}
	int losowe_haslo = rand() % (pHead->licznik_hasel); //losuje has�o
	for (int i = 0; i < losowe_haslo; i++)
	{
		pHead->pHasla = pHead->pHasla->pNext;
	}

	graj(pHead->pHasla->haslo, pHead->kategoria); //inicjalizacja gry
}

void graj(char* haslo,char * kategoria)//dostaje has�o i kategorie do gry
{
	
	int dlugosc = strlen(haslo); // pobieram jak d�ugie jest has�o
	for (int i = 0; i < dlugosc; i++)
	{
		if (haslo[i] == '_')		//zamieniam podkre�lenia na spacje
			haslo[i] = ' ';		
	}
	char* odgadywana = malloc(strlen(haslo) + 1); //mallocuje dwie pomocnicze tablice
	char* pomocnicza = malloc(strlen(haslo) + 1);

	if (odgadywana == NULL || pomocnicza == NULL)
	{
		printf("Nie udalo sie zaalokowac pamieci.");
		
	}
	else
	{
		strcpy(odgadywana, haslo); //i kopiuje do nich has�o
		strcpy(pomocnicza, haslo);
		printf("\n");
		for (int i = 0; i < dlugosc; i++)
		{
			if (odgadywana[i] != ' ')    //zast�puje obie my�lnikami �eby nie by�o od razu wida� has�a
				odgadywana[i] = '-';

		}
		for (int i = 0; i < dlugosc; i++)
		{
			if (pomocnicza[i] != ' ')  //zast�puje obie my�lnikami �eby nie by�o od razu wida� has�a
				pomocnicza[i] = '-';

		}

		printf("\n");

		char strzelone[26];   //max ilo�� liter w alfabecie
		int ile_strzalow = 0; //licznik strza��w
		char strzal = 'n'; //inicjalizacja strza�u
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("%s\n", odgadywana);
		printf("Sprobuj szczescia!\n");
		int zycia = 10;
		while ((strcmp(odgadywana, haslo) != 0) && zycia != 0) //dop�ki u�ytkownik ma �ycia lub nie odgad� has�a
		{
			printf("Kategoria:%s\n", kategoria);
			printf("Te litery juz byly:");
			for (int i = 0; i < ile_strzalow; i++)
			{
				printf(" %c ", strzelone[i]);           //wy�wietla litery kt�re ju� by�y
			}
			printf("\n");
			printf("Strzal:");


			scanf(" %c", &strzal);
			while (!isalpha(strzal)) //rzutowanie na tablice ascii - przechodz� tylko ma�e litery
			{
				printf("Prosze podac litere.\n");
				printf("Strzal:");
				scanf(" %c", &strzal); //pobiera strza� od u�ytkownika
			}
			for (int i = 0; i < ile_strzalow; i++)
			{
				if (strzal == strzelone[i])
				{
					printf("Ta litera juz byla.\n"); //sprawdzenie czy u�ytkownbik nie podaj 2 razy tej samej litery
					printf("Strzal:");
					scanf(" %c", &strzal);
				}
			}
			if (islower(strzal))
			{
				strzal = toupper(strzal);
			}

			strzelone[ile_strzalow] = strzal;
			ile_strzalow += 1;


			for (int i = 0; i < dlugosc; i++)
			{
				if (haslo[i] == strzal)
				{
					odgadywana[i] = strzal;     //spraedzam czy co� nie by�o trafione

				}

			}

			if ((strcmp(pomocnicza, odgadywana)) == 0)  //je�li to , co przed strza�em jest r�wne temu co po strzale , to znaczy �e u�ytkownik nie trafi�
				zycia--;

			printf("\n");
			system("cls");
			dobierz_rysunek(zycia); //dobieram rysunek
			printf("\n");
			printf("\n");
			printf("%s", odgadywana); //wy�wietlam odgadywan�
			strcpy(pomocnicza, odgadywana); //aktualizuje tablice przed nast�pnym strza�em

			printf("\n");


		}
		if (strcmp(odgadywana, haslo) == 0) //przypadek w kt�rym u�ytkownik odgad�
		{
			printf("\n");
			printf("Haslo odgadniete , gratulacje!"); //je�li has�a takie same - to odgad� has�o
		}
		else //przypadek w kt�rym u�ytkownik przegra�
		{

			system("cls");
			rysunek10();
			printf("\n");
			printf("Moze nastepnym razem!\n");
			printf("Poprawne haslo:%s", haslo);
		}
		free(odgadywana); //zwalnianie wcze�niej zaalokowanych malloc'kiem tablic
		free(pomocnicza);

	}
}

void usun_liste(struct kategorie** pHead) //usuwanie listy od pocz�tku iteracyjnie
{
	if (*pHead) //je�li pHead istnieje
	{
		while (*pHead)
		{
			while (((*pHead)->pHasla)) //dop�ki kategoria ma has�a 
			{
				struct hasla* pom = ((*pHead)->pHasla->pNext); //pomocniczy wska�nik
				free(((*pHead)->pHasla->haslo)); //zwolnienie pamieci has�a
				free(((*pHead)->pHasla)); //zwolnienie ca�ej pami�ci w podli�cie
				((*pHead)->pHasla) = pom; //przestawienie wskla�nika
			}
			struct kategorie* p = (*pHead)->pNext; //pomocniczy wska�nik
			free((*pHead)->kategoria); // zwolnienie tekstu przechowywuj�cego kategorie
			free(*pHead);   //zwolnienie struktury
			(*pHead) = p; //przestawienie wska�nika
		}
		
		
	}
}
void rysunek1()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("_____________");


}
void rysunek2()
{
	printf("      |\n");
	printf("      |\n");
	printf("      |\n");
	printf("      |\n");
	printf("      |\n");
	printf("      |\n");
	printf("      |\n");
	printf("_____________");
}
void rysunek3()
{
	printf("      -----------\n");
	printf("      |\n");
	printf("      |\n");
	printf("      |\n");
	printf("      |\n");
	printf("      |\n");
	printf("      |\n");
	printf("_____________");
}
void rysunek4()
{
	printf("      -----------\n");
	printf("      |          |\n");
	printf("      |\n");
	printf("      |\n");
	printf("      |\n");
	printf("      |\n");
	printf("      |\n");
	printf("_____________");
}
void rysunek5()
{
	printf("      -----------\n");
	printf("      |          |\n");
	printf("      |         ( )\n");
	printf("      |\n");
	printf("      |\n");
	printf("      |\n");
	printf("      |\n");
	printf("_____________");
}
void rysunek6()
{
	printf("      -----------\n");
	printf("      |          |\n");
	printf("      |         ( )\n");
	printf("      |          |\n");
	printf("      |          |\n");
	printf("      |\n");
	printf("      |\n");
	printf("_____________");
}
void rysunek7()
{
	printf("      -----------\n");
	printf("      |          |\n");
	printf("      |         ( )\n");
	printf("      |         /|\n");
	printf("      |          |\n");
	printf("      |\n");
	printf("      |\n");
	printf("_____________");
}
void rysunek8()
{
	printf("      -----------\n");
	printf("      |          |\n");
	printf("      |         ( )\n");
	printf("      |         /|\\\n");
	printf("      |          |\n");
	printf("      |\n");
	printf("      |\n");
	printf("_____________");
}
void rysunek9()
{
	printf("      -----------\n");
	printf("      |          |\n");
	printf("      |         ( )\n");
	printf("      |         /|\\\n");
	printf("      |          |\n");
	printf("      |         /\n");
	printf("      |\n");
	printf("_____________");
}
void rysunek10()
{
	printf("      -----------\n");
	printf("      |          |\n");
	printf("      |         ( )\n");
	printf("      |         /|\\\n");
	printf("      |          |\n");
	printf("      |         / \\\n");
	printf("      |\n");
	printf("_____________");
}

void dobierz_rysunek(int zycia) //dobiera rysunek w zale�no�ci od �ycia
{
	switch (zycia)
	{
	case 10:
		{
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		}
		break;
	case 9:
		rysunek1();
		break;
	case 8:
		rysunek2();
		break;
	case 7:
		rysunek3();
		break;
	case 6:
		rysunek4();
		break;
	case 5:
		rysunek5();
		break;
	case 4:
		rysunek6();
		break;
	case 3:
		rysunek7();
		break;
	case 2:
		rysunek8();
		break;
	case 1:
		rysunek9();
		break;
	case 0:
		rysunek10();
		break;
	}
}

void menu_glowne() //wy�wietla menu g�owne
{
	printf("Witaj w grze w wisielca.Wybierz tryb gry:\n");
	printf("\n");
	printf("1.Losowy wybor kategorii\n");
	printf("2.Reczny wybor kategorii\n");
	printf("\n");
	printf("Wybierz 1 lub 2 i zatwierdz enterem.\n");
	printf("Twoj wybor:");



}

void menu_po_grze() // wy�wietla menu po zako�czeniu gry
{
	printf("\n");
	printf("Co chcesz teraz zrobic:\n");
	printf("\n");
	printf("1.Zagraj jeszcze raz\n");
	printf("2.Zakoncz\n");
	printf("Twoj wybor:");

}