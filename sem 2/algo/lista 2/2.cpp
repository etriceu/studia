#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define N 10

int main()
{
	srand(time(NULL));
	int *i = new int(rand()%101);
	double *d = new double((rand()+0.)/RAND_MAX);
	float *f = new float((rand()+0.)/RAND_MAX);
	int *tab = new int[N];
	for(int n = 0; n < N; n++)
		tab[n] = rand()%101;

	cout<<*i<<endl<<*d<<endl<<*f<<endl;
	for(int n = 0; n < N; n++)
		cout<<tab[n]<<" ";

	cout<<endl;

	delete i, d, f;
	delete [] tab;
}
