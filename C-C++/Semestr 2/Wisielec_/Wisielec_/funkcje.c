#include "struktury.h"
#include "funkcje.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_ROZMIAR 30


void dodaj_do_listy(struct kategorie** pHead, char* slowo, FILE * plik) //dodawanie na pocz¹tek iteracyjnie
{

	
	struct kategorie* pNowy = (struct kategorie*)malloc(sizeof(struct kategorie)); //utworzernie nowej kategorii
	char bufor[MAX_ROZMIAR]; //bufor do odczytu z pliku
	pNowy->kategoria = malloc(strlen(slowo) + 1); //mallocuje pamiêæ na kategorie
	strcpy(pNowy->kategoria, slowo); //kopiuje odczytane s³owo do szufladki z kategori¹
	pNowy->licznik_hasel = 0; //inicjalizacja licznika hase³(potrzebny do losowania)
	pNowy->pHasla = NULL; //na razie hase³ nie wczytalem , wiêc wskaŸnik na has³a jest 
	pNowy->pNext = (*pHead); //przestawienie wskaŸników 
	(*pHead) = pNowy;
	while (1)
	{
		

		fscanf(plik, "%s", bufor); // skanuje z pliku w poszukiwaniu hase³
		if (strcmp(bufor, ",") == 0) //program po przecinku poznaje koniec linii
			break;
		else
		{
			dodaj_haslo(&(pNowy->pHasla),bufor); //jeœli nie koniec, to dodaje nowe has³o do danej kategorii
			(pNowy->licznik_hasel)++; //i inkrementuje licznik hase³
		}

	}
	


}

void dodaj_haslo(struct hasla** pHead,char * bufor) //dodawanie na pocz¹tek iteracyjnie
{
	
	struct hasla* pNowy = (struct hasla*)malloc(sizeof(struct hasla)); //nowe has³o
	pNowy->haslo = malloc(strlen(bufor) + 1); //mallocuje pamiêæ na has³o
	strcpy(pNowy->haslo, bufor); //kopiuje odczytane has³o 
	pNowy->pNext = (*pHead); //przestawienie wskaŸników
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

		fclose(plik_wejsciowy); //zamkniêcie pliku
		return 1; //zwraca czy odczyt by³ poprawny
	}
	else {
		printf("Nie udalo sie poprawnie otworzyc pliku."); //zwraca czy odczyt by³ poprawny
		return 0;
		}



}

void gra_losowa(struct kategorie* pHead, int licznik_kategorii)
{
	srand(time(NULL));
	int losowa_kategoria = rand() % (licznik_kategorii); //losuje kategorie
	
	for (int i = 0; i < losowa_kategoria; i++)
	{
		pHead = pHead->pNext; //tyle razy ile wylosowa³em przesuwam siê po liœcie kategorii
	}
	int losowe_haslo = rand() % (pHead->licznik_hasel); //losuje has³o
	for (int i = 0; i < losowe_haslo; i++) 
	{
		pHead->pHasla = pHead->pHasla->pNext; ////tyle razy ile wylosowa³em przesuwam siê po liœcie hase³
	}

	graj(pHead->pHasla->haslo, pHead->kategoria); //inicjalizacja gry

}

void gra_z_wyborem_kategorii(struct kategorie* pHead,int kategoria)
{
	srand(time(NULL));
	

	for (int i = 0; i < (kategoria-1); i++) //kategorie dostaje z góry , musze tylko wylosowaæ has³o
	{
		pHead = pHead->pNext;
	}
	int losowe_haslo = rand() % (pHead->licznik_hasel); //losuje has³o
	for (int i = 0; i < losowe_haslo; i++)
	{
		pHead->pHasla = pHead->pHasla->pNext;
	}

	graj(pHead->pHasla->haslo, pHead->kategoria); //inicjalizacja gry
}

void graj(char* haslo,char * kategoria)//dostaje has³o i kategorie do gry
{
	
	int dlugosc = strlen(haslo); // pobieram jak d³ugie jest has³o
	for (int i = 0; i < dlugosc; i++)
	{
		if (haslo[i] == '_')		//zamieniam podkreœlenia na spacje
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
		strcpy(odgadywana, haslo); //i kopiuje do nich has³o
		strcpy(pomocnicza, haslo);
		printf("\n");
		for (int i = 0; i < dlugosc; i++)
		{
			if (odgadywana[i] != ' ')    //zastêpuje obie myœlnikami ¿eby nie by³o od razu widaæ has³a
				odgadywana[i] = '-';

		}
		for (int i = 0; i < dlugosc; i++)
		{
			if (pomocnicza[i] != ' ')  //zastêpuje obie myœlnikami ¿eby nie by³o od razu widaæ has³a
				pomocnicza[i] = '-';

		}

		printf("\n");

		char strzelone[26];   //max iloœæ liter w alfabecie
		int ile_strzalow = 0; //licznik strza³ów
		char strzal = 'n'; //inicjalizacja strza³u
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
		while ((strcmp(odgadywana, haslo) != 0) && zycia != 0) //dopóki u¿ytkownik ma ¿ycia lub nie odgad³ has³a
		{
			printf("Kategoria:%s\n", kategoria);
			printf("Te litery juz byly:");
			for (int i = 0; i < ile_strzalow; i++)
			{
				printf(" %c ", strzelone[i]);           //wyœwietla litery które ju¿ by³y
			}
			printf("\n");
			printf("Strzal:");


			scanf(" %c", &strzal);
			while (!isalpha(strzal)) //rzutowanie na tablice ascii - przechodz¹ tylko ma³e litery
			{
				printf("Prosze podac litere.\n");
				printf("Strzal:");
				scanf(" %c", &strzal); //pobiera strza³ od u¿ytkownika
			}
			for (int i = 0; i < ile_strzalow; i++)
			{
				if (strzal == strzelone[i])
				{
					printf("Ta litera juz byla.\n"); //sprawdzenie czy u¿ytkownbik nie podaj 2 razy tej samej litery
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
					odgadywana[i] = strzal;     //spraedzam czy coœ nie by³o trafione

				}

			}

			if ((strcmp(pomocnicza, odgadywana)) == 0)  //jeœli to , co przed strza³em jest równe temu co po strzale , to znaczy ¿e u¿ytkownik nie trafi³
				zycia--;

			printf("\n");
			system("cls");
			dobierz_rysunek(zycia); //dobieram rysunek
			printf("\n");
			printf("\n");
			printf("%s", odgadywana); //wyœwietlam odgadywan¹
			strcpy(pomocnicza, odgadywana); //aktualizuje tablice przed nastêpnym strza³em

			printf("\n");


		}
		if (strcmp(odgadywana, haslo) == 0) //przypadek w którym u¿ytkownik odgad³
		{
			printf("\n");
			printf("Haslo odgadniete , gratulacje!"); //jeœli has³a takie same - to odgad³ has³o
		}
		else //przypadek w którym u¿ytkownik przegra³
		{

			system("cls");
			rysunek10();
			printf("\n");
			printf("Moze nastepnym razem!\n");
			printf("Poprawne haslo:%s", haslo);
		}
		free(odgadywana); //zwalnianie wczeœniej zaalokowanych malloc'kiem tablic
		free(pomocnicza);

	}
}

void usun_liste(struct kategorie** pHead) //usuwanie listy od pocz¹tku iteracyjnie
{
	if (*pHead) //jeœli pHead istnieje
	{
		while (*pHead)
		{
			while (((*pHead)->pHasla)) //dopóki kategoria ma has³a 
			{
				struct hasla* pom = ((*pHead)->pHasla->pNext); //pomocniczy wskaŸnik
				free(((*pHead)->pHasla->haslo)); //zwolnienie pamieci has³a
				free(((*pHead)->pHasla)); //zwolnienie ca³ej pamiêci w podliœcie
				((*pHead)->pHasla) = pom; //przestawienie wsklaŸnika
			}
			struct kategorie* p = (*pHead)->pNext; //pomocniczy wskaŸnik
			free((*pHead)->kategoria); // zwolnienie tekstu przechowywuj¹cego kategorie
			free(*pHead);   //zwolnienie struktury
			(*pHead) = p; //przestawienie wskaŸnika
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

void dobierz_rysunek(int zycia) //dobiera rysunek w zale¿noœci od ¿ycia
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

void menu_glowne() //wyœwietla menu g³owne
{
	printf("Witaj w grze w wisielca.Wybierz tryb gry:\n");
	printf("\n");
	printf("1.Losowy wybor kategorii\n");
	printf("2.Reczny wybor kategorii\n");
	printf("\n");
	printf("Wybierz 1 lub 2 i zatwierdz enterem.\n");
	printf("Twoj wybor:");



}

void menu_po_grze() // wyœwietla menu po zakoñczeniu gry
{
	printf("\n");
	printf("Co chcesz teraz zrobic:\n");
	printf("\n");
	printf("1.Zagraj jeszcze raz\n");
	printf("2.Zakoncz\n");
	printf("Twoj wybor:");

}