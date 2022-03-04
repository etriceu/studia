#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int findMax(int *tab, int n = 49)
{
	int x = n == 0 ? tab[0] : findMax(tab, n-1);
	return x > tab[n] ? x : tab[n];
}

int main()
{
	srand(time(NULL));
	int tab[50];
	for(int &a : tab)
		a = rand()%101;

	cout<<findMax(tab)<<endl;
}

