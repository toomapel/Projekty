/** @file */
#pragma once

#include <stdio.h>
#include <stdlib.h>

/** Struktura listy jednokierunkowej z haslami dla danej kategorii */
struct hasla
{
	char* haslo;  ///< haslo do gry
	struct hasla* pNext; ///< wskaznik na nastepny element listy

};
/** Struktura listy jednokierunkowej z kategoriami */
struct kategorie
{
	char* kategoria; ///< kategoria do gry
	int licznik_hasel; ///< licznik wszystkich hasel 
	struct kategorie* pNext; ///< wskaznik na nastepny element listy
	struct hasla* pHasla; ///< wskaznik na pierwszy element listy hasel dla danej kategorii

};