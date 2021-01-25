#include<iostream>
#include<string>

using namespace std;

int main()
{   
    string tekst =  "Terra rotunda est";
    string szukaj;
    cout << "Podaj frazę do wyszukania: " << endl;
    cin >> szukaj;
    int pozycja = tekst.find(szukaj);
    if(pozycja!=string::npos) //jesli znaleziono dana fraze
    {
        cout << "Znaleziono na pozycji " << pozycja << endl;
        
    }
    else 
    {
        cout<<"Nie znaleziono danej frazy"<<endl;
        
    }
    
    return 0;
}