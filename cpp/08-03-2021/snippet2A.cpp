#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
	fstreamplik;
	plik.open("text.txt");
	if(plik.good() == true)
	{
		string linia; 
		int nr_linii = 1;
		while(getline(plik, linia))
		{
			cout << linia << endl;
			nr_linii++;
		}
		plik.close();
	}
	else
	{
		cout << "File doesn't exist" << endl;
	}
	
	return 0;
}
