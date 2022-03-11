#include <iostream>

using namespace std;

void minMax(int tab[])
{
	int max = 0, min = 0;
	for(int n = 0; n < 15; n++)
	{
		if(tab[max] < tab[n])
			max = n;
		if(tab[min] > tab[n])
			min = n;
	}
	
	cout<<"Min: "<<tab[min]<<" index: "<<min<<endl;
	cout<<"Max: "<<tab[max]<<" index: "<<max<<endl;
}

void avg(int tab[])
{
	double avg = 0;
	for(int n = 0; n < 15; n++)
		avg += tab[n];
	
	avg /= 15;
	cout<<"Srednia: "<<avg<<endl;
}

void find(int tab[], int a)
{
	for(int n = 0; n < 15; n++)
		if(tab[n] == a)
		{
			cout<<"Find: "<<a<<" index: "<<n<<endl;
			break;
		}
}

int main()
{
	int tab[15];
	for(int &a : tab)
		cin>>a;
	
	minMax(tab);
	avg(tab);
	int a;
	cout<<"Znajdz: ";
	cin>>a;
	find(tab, a);
}
