#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	int ile;

	cout << "Ile liczb w tablicy? ";
	cin >> ile;

	int *tablica;
	tablica = new int[ile];
	for(int i = 0; i < ile; i++)
	{
		tablica[i] = i;
		cout << tablica[i] << ", " << &tablica[i] << endl;
	}

	delete[] tablica; // Zwolnienie pamięci

	return 0;
}
