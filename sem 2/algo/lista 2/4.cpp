#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	srand(time(NULL));
	int tab[10], *ptr[10];

	for(int n = 0; n < 10; n++)
	{
		tab[n] = rand()%101;
		ptr[n] = &tab[n];
	}

	sort(ptr, ptr+10, [](int *a, int *b){return *a < *b;});

	for(int n = 0; n < 10; n++)
		cout<<*ptr[n]<<" ";
	cout<<endl;
}
