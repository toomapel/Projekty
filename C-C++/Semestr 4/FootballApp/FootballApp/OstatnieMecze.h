#pragma once
#include <array>
#include <memory>
#include <string>
using namespace std;
/* Wszystkie klasy maj� tablice z STL Array(�eby by�o fajne indeksowanie) , u�y�em smart pointer�w �eby
   unikn�� wyciek�w pami�ci, pami�taj �e te tablice to tak naprawd� pointery i �eby u�ywa� * odwo�uj�c si� do nich            */
class OstatnieMecze
{
private:
	shared_ptr<array<string, 10>> oGospodarze; // dru�yny graj�ce u siebie(po kolei)
	shared_ptr<array<string, 10>> oGoscie; // dru�yny graj�ce na wyje�dzie(po kolei)
	shared_ptr<array<int, 10>> bramkiGospodarzy; // bramki dru�yn gospodarzy
	shared_ptr<array<int, 10>> bramkiGosci; // bramki dru�yn go�ci
public:
	OstatnieMecze();
	~OstatnieMecze();
	//gettery
	array<string, 10>& getOGospodarze();
	array<string, 10>& getOGoscie();
	array<int, 10>& getBramkiGospodarzy();
	array<int, 10>& getBramkiGosci();
};

