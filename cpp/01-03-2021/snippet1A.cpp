#include <iostream>
#include <math.h>

using namespace std;

void displayStuff(float a)
{
    cout << "Number a is equal: " << a << endl;
    cout << "It's approximately " << round(a) << endl;
    cout << "Rounding down it's " << floor(a) << endl;
    cout << "Rounding up it's " << ceil(a) << endl;
    cout << "As an integer it's " << trunc(a) << endl;
}

int main()
{
    cout << "For pi:" << endl;
    displayStuff(M_PI);
    cout << endl << "For e:" << endl;
    displayStuff(M_E);

    return 0;
}
