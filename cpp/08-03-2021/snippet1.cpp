#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
	fstreamplik; //tworzenie uchwytu
	plik.open("wizytowka.txt"); //otwarcie pliku
	if(plik.good() == false) //test otwarcia pliku
	{ 
		cout << "Plik nie istnieje";
		exit(0);
	} 
	else
	{
		cout << "Udalo sie otworzyc plik";
	}
	plik.close(); //zamkniecie pliku
	
	return 0;
}