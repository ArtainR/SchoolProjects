#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    string name;
    
    cout << "Please input your name:" << endl;
    cin >> name;
	
    if(name[name.size() - 1] == 'a') // In Polish, female names end with "a", while male names don't
    {
        cout << "Inputted name is feminine" << endl;
    }
    else
    {
        cout << "Inputted name is masculine" << endl;
    }
	
	return 0;
}