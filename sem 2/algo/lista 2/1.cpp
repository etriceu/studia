#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	srand(time(NULL));
	int a[10];
	for(int i = 0; i < 10; i++)
	{
		*(&a[0]+i) = rand()%100+1;
		cout<<*(&a[0]+i)<<" ";
	}
	cout<<endl;
}
