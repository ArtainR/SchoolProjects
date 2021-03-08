#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
	fstreamplik; //tworzenie uchwytu
	plik.open("tekst.txt"); //otwarcie pliku
	if(plik.good() == true)
	{
		string linia; 
		int nr_linii = 1;
		while(getline(plik, linia)) //wczytywanie danych
		{
			cout << linia << endl;
			nr_linii++;
		}
		plik.close();//zamknięcie pliku
	}
	else
	{
		cout << "Plik nie istnieje" << endl;
	}
	
	return 0;
}