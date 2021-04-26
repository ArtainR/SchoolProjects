#include <ctime>
#include <iostream>

using namespace std;

unsigned long long getFactorialIter(int n)
{
	unsigned long long r = 1;
	for(int i = n; i > 0; i--)
	{
		r *= i;
	}
	return r;
}

unsigned long long getFactorialRec(unsigned long long n)
{
	if(n == 1 || n == 0 || n == -1)
	{
		return n;
	}

	return n * getFactorialRec(n - 1);
}

int main()
{
	int n = 15;

	int start = clock();
	unsigned long long a = getFactorialIter(n);
	int end = clock();
	float timeIter = (float)(end - start) / CLOCKS_PER_SEC;

	int start2 = clock();
	unsigned long long b = getFactorialRec(n);
	int end2 = clock();
	float timeRec = (float)(end2 - start2) / CLOCKS_PER_SEC;

	cout << "Factorial of " << n << " (" << a << ") using iteration took: " << timeIter << " seconds" << endl;
	cout << "Factorial of " << n << " (" << b << ") using recurrency took: " << timeRec << " seconds" << endl;

	return 0;
}
