#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
	fstreamplik;
	plik.open("text.txt")
	if(plik.good() == true)
	{
		string linia; 
		int nr_linii = 1;
		while(getline(plik, linia))
		{
			cout << linia << endl;
			getline(plik, linia);
			nr_linii += 2;
		}
		plik.close();
	}
	else
	{
		cout << "File not found" << endl;
	}
	
	return 0;
}
