#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float APi = M_PI * 2 * 2;
    float AThree = 3.14 * 2 * 2;
    cout << "For pi:" << endl << "The area of a circle with radius 2: ";
    cout << APi << endl;
    cout << "For 3.14:" << endl << "The area of a circle with radius 2: ";
    cout << AThree << endl;
    cout << "Therefore, the relative error is: " << 1 - AThree / APi << "%" << endl;

    return 0;
}