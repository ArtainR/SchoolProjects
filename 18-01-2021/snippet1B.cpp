#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    string tab[10][3];
    
    /* // For easier testing
    string sample[3][10] = {
        {"Liam", "Olivia", "Noah", "Emma", "Olivier", "Ava", "William", "Sophia", "Elijah", "Isabella"},
        {"Smith", "Johnson", "Williams", "Brown", "Jones", "Miller", "Davis", "Garcia", "Rodriguez", "Wilson"},
        {"62", "46", "97", "9", "34", "43", "31", "60", "87", "89"}
    };
    */
    
    for(int i = 0; i < 10; i++) 
    {
        cout << "Please input the " << i + 1<< " person's name, surname, and age:" << endl;
        cin >> tab[i][0] >> tab[i][1] >> tab[i][2];
        
        /* // For easier testing
        tab[i][0] = sample[0][i];
        tab[i][1] = sample[1][i];
        tab[i][2] = sample[2][i];
        */
        
        system("clear"); // Not safe according to https://www.cplusplus.com/articles/j3wTURfi/ but no other options on onlinegdb.com
    }
    
    for(int i = 0; i < 10; i++)
    {
        cout << tab[i][0] + " | " + tab[i][1] + " | " + tab[i][2] << endl;
    }
	
	return 0;
}