#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    // DISCLAIMER: I still have no idea how to calculate this in reality,
    // so here's whatever I could find. For some reason, the output is negative.
    float angle;
    float torque;
    float m;

    cout << "Please input the angle of the incline: ";
    cin >> angle;
    cout << "Please input the torque of the object: ";
    cin >> torque;
    cout << "Please input the mass of the object: ";
    cin >> m;

    float a = m * 10 * sin(angle);
    float b = m * 10 * cos(angle);

    cout << "Acceleration a = " << (a - (torque * b)) / m << " m/s^2" << endl;

    return 0;
}
