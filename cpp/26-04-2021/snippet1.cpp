#include <iostream>

using namespace std;

int getPower(int n, int m)
{
	if(m == 0)
	{
		return 1;
	}
	return n * getPower(n, m - 1);
}

int main()
{
	int a;
	int b;
	cout << "Input a number: ";
	cin >> a;
	cout << "Input a second number: ";
	cin >> b;

	cout << a << "^" << b << " = " << getPower(a, b) << endl;

	return 0;
}
