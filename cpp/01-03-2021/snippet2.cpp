#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float aX = 0;
    float aY = 0;
    float bX = 0;
    float bY = 0;

    cout << "Please input where point A lies on the X axis:" << endl;
    cin >> aX;
    cout << "Please input where point A lies on the Y axis:" << endl;
    cin >> aY;
    cout << endl << "Please input where point B lies on the X axis:" << endl;
    cin >> bX;
    cout << "Please input where point B lies on the Y axis:" << endl;
    cin >> bY;

    cout << endl << endl << "The distance between points A(" << aX << ", " << aY << ") and B(" << bX << ", " << bY << ") is equal too: ";
    cout << sqrt(pow(bX - aX, 2) + pow(bY - aY, 2)) << endl;

    return 0;
}
