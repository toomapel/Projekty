#pragma once
#include <array>
#include <memory>
#include <string>
using namespace std;

/* Wszystkie klasy maj� tablice z STL Array(�eby by�o fajne indeksowanie) , u�y�em smart pointer�w �eby
   unikn�� wyciek�w pami�ci, pami�taj �e te tablice to tak naprawd� pointery i �eby u�ywa� * odwo�uj�c si� do nich           */

class NajlepsiZawodnicy
{
private:
	shared_ptr<array<string, 10>> najlepsiStrzelcy; //imiona i nazwiska strzelc�w
	shared_ptr<array<string, 10>> najlepsiAsystenci; //imiona i nazwiska asystent�w
	shared_ptr<array<int, 10>> ileStrzelili; // tu trzeba wpisa� ile bramek poszczeg�lny strzelec strzeli�
	shared_ptr<array<int, 10>> ileAsystowali; // tu trzeba wpisa� ile bramek poszczeg�lny asystent asystowa�
public:
	NajlepsiZawodnicy();
	~NajlepsiZawodnicy();
	//gettery
	array<string, 10>& getNajlepsiStrzelcy();	
	array<string, 10>& getNajlepsiAsystenci();
	array<int, 10>& getIleStrzelili();
	array<int, 10>& getIleAsystowali();
	
};

