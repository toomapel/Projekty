/** @file */
#include "struktury.h"

#include <stdio.h>
#include <stdlib.h>

/**Funkcja odczytuje z pliku hasla i kategorie
@param licznik_kategorii jest to licznik wszystkich kategorii
@param [int,out] pHead wskaznik na pierwszy element listy kategorii
@return informacja czy plik zostal poprawnie odczytany
*/
int odczytaj_z_pliku(struct kategorie** pHead, int* licznik_kategorii);
/**Funkcja dodaje kategorie do listy kategorii
@param plik jest to wskaznik na strumien plikowy z haslami i kategoriami
@param slowo nowo odczytany wyraz , nazwa nowej (dodawanej) kategorii
@param [int,out] pHead wskaznik na pierwszy element listy kategorii */
void dodaj_do_listy(struct kategorie** pHead, char* slowo, FILE* plik);
/**Funkcja dodaje haslo do listy hasel
@param bufor nazwa hasla dodawanego
@param [int,out] pHead wskaznik na pierwszy element listy hasel */
void dodaj_haslo(struct hasla** pHead, char* bufor);
/**Funkcja inicjalizuje gre losowa
@param licznik_kategorii jest to licznik wszystkich kategorii
@param [int,out] pHead wskaznik na pierwszy element listy kategorii */
void wypisz_kategorie(struct kategorie* pHead,int licznik_kategorii);
/**Funkcja inicjalizuje gre losowa
@param [int,out] pHead wskaznik na pierwszy element listy kategorii */
void usun_liste(struct kategorie** pHead);
/**Funkcja inicjalizuje gre losowa
@param licznik_kategorii jest to licznik wszystkich kategorii
@param [int,out] pHead wskaznik na pierwszy element listy kategorii */
void gra_losowa(struct hasla* pHead, int licznik_kategorii);

/**Funkcja inicjalizuje gre z wyborem kategorii
@param kategoria numer kategorii ktory ma byc wybrany do gry
@param [int,out] pHead wskaznik na pierwszy element listy kategorii */
void gra_z_wyborem_kategorii(struct hasla* pHead,int kategoria);
/**Funkcja odpowiada za przeprowadzenie samej gry
@param haslo jest to haslo ktore uzytkownik musi zgadnac
@param kategoria jest to kategoria hasla */
void graj(char* haslo, char* kategoria);

// rysunki wisielca
/**Rysunek wisielca nr 1
 */
void rysunek1();
/**Rysunek wisielca nr 2
 */
void rysunek2();
/**Rysunek wisielca nr 3
 */
void rysunek3();
/**Rysunek wisielca nr 4
 */
void rysunek4();
/**Rysunek wisielca nr 5
 */
void rysunek5();
/**Rysunek wisielca nr 6
 */
void rysunek6();
/**Rysunek wisielca nr 7
 */
void rysunek7();
/**Rysunek wisielca nr 8
 */
void rysunek8();
/**Rysunek wisielca nr 9
 */
void rysunek9();
/**Rysunek wisielca nr 10
 */
void rysunek10();
/**Funkcja dobiera odpowiedni rysunek wisielca
@param zycia jest to ilosc zyc uzytkownika w danym momencie gry
 */
void dobierz_rysunek(int zycia);

/**Wysietla menu glowne
 */
void menu_glowne();
/**Wyswietla menu po grze
 */
void menu_po_grze();