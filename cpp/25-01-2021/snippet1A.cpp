#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string napis_1 = "DUBITO ERGO COGITO ";
	string napis_2 = "cogito ergo sum";
	
	transform(napis_1.begin(), napis_1.end(), napis_1.begin(), ::tolower)
	transform(napis_2.begin(), napis_2.end(), napis_2.begin(), ::toupper)
	
	cout << napis_1 << endl;
	cout << napis_2 << endl;
	
	return 0;
}