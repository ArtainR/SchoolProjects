#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
	fstreamplik;
	plik.open("id.txt");
	if(plik.good() == false)
	{ 
		cout << "File doesn't exist";
		exit(0);
	} 
	else
	{
		cout << "File successfully opened";
	}
	plik.close();
	
	return 0;
}
