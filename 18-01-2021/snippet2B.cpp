#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    string word;
    
    cout << "Please input a word:" << endl;
    cin >> word;
    
    for(int i = word.size() - 1; i >= 0; i--)
    {
        cout << word[i];
    }
    cout << endl;
    
    return 0;
}