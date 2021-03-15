#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	string imie, nazwisko, klasa;

	cout << "Podaj imie";
	cin >> imie;
	cout << "Podaj nazwisko:";
	cin >> nazwisko;
	cout << "Podaj klase:";
	cin >> klasa;

	fstream plik;
	plik.open("NotExistant.txt", ios::out | ios::app);
	plik << imie << endl;
	plik << nazwisko << endl;
	plik << klasa << endl;
	plik.close();

	return 0;
}
