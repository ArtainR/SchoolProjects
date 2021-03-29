#include <random>
#include <ctime>
#include <iostream>
#include <climits>

using namespace std;

void quicksort(int d [10000], int lewy, int prawy)
{
  int i,j,piwot;

  i = (lewy + prawy) / 2;
  piwot = d[i]; d[i] = d[prawy];
  for(j = i = lewy; i < prawy; i++)
  if(d[i] < piwot)
  {
    swap(d[i], d[j]);
    j++;
  }
  d[prawy] = d[j]; d[j] = piwot;
  if(lewy < j - 1)  quicksort(d, lewy, j - 1);
  if(j + 1 < prawy) quicksort(d, j + 1, prawy);
}

int main()
{
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> distRNG(0, INT_MAX);

	int tab1 [10000];
	int tab2 [10000];

	for(int i = 0; i < 10000; i++)
	{
		tab1[i] = distRNG(rng);
	}

	for(int i = 0; i < 10000; i++)
	{
		tab2[i] = distRNG(rng);
	}

	int start = clock();

	quicksort(tab1, 0, 9999);

	int end = clock();

	cout << "Quick sort: " << (float)(end - start) / CLOCKS_PER_SEC << "s" << endl;

	start = clock();

	for(int j = 0; j < 9999; j++)
      for(int i = 0; i < 9999; i++)
        if(tab2[i] > tab2[i + 1]) swap(tab2[i], tab2[i + 1]);

	end = clock();

	cout << "Bubble sort: " << (float)(end - start) / CLOCKS_PER_SEC  << "s" << endl;

	return 0;
}
