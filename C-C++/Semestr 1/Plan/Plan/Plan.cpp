#include <fstream>
#include <iostream>
//#include <vld.h>
#include "struktury.h"
#include "funkcje.h"

using namespace std;

int main(int argc,char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	string nazwaPliku;
	
	/*for (int i = 0; i < argc; ++i)
	{
		string przelacznik=argv[i];
		if (przelacznik == "-i")
			nazwaPliku = argv[i + 1];
	}*/
	cin >> nazwaPliku;
	
	
	nauczyciel* pGlowa = nullptr;
	
	
	
	
	
	
	
	bool poprawny = odczytajZPliku(nazwaPliku,pGlowa);
	
	//wypiszListeIUsun(pGlowa,poprawny);
	
	
	_CrtDumpMemoryLeaks();
	return 0;
}
