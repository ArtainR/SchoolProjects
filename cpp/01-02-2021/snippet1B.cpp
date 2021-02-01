#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text = "Veni, vidi, vici";
    cout << "Before: " << text << endl;
    text.replace(12, 4, "Deus vicit");
    cout << "After: " << text << endl;
	
	return 0;
}
