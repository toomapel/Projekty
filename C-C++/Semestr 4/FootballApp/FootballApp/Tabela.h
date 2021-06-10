#pragma once

#include <array>
#include <memory>
#include <string>
/* Wszystkie klasy maj� tablice z STL Array(�eby by�o fajne indeksowanie) , u�y�em smart pointer�w �eby
   unikn�� wyciek�w pami�ci, pami�taj �e te tablice to tak naprawd� pointery i �eby u�ywa� * odwo�uj�c si� do nich            */
using namespace std;
class Tabela
{
private:
	shared_ptr<array<string, 20>> druzyny; // nazwy dru�yn w tabeli(po kolei)
	shared_ptr<array<int, 20>> punkty; // ilo�� punkt�w odpowiadaj�ca danej dru�ynie
	shared_ptr<array<int, 20>> bramki; // r�nica bramek odpowiadaj�ca danej dru�ynie
public:
	Tabela();
	~Tabela();
	//gettery
	array<string, 20>& getDruzyny();
	array<int, 20>& getPunkty();
	array<int, 20>& getBramki();
};

