#include <iostream>

using namespace std;

int main()
{
	cout<<"liczba ocen: ";
	int num;
	cin>>num;
	double avg = 0;
	for(int n = 0, a; n < num && cin>>a; n++)
		avg += a;

	avg /= num;
	cout<<avg<<(avg > 4.1 ? " stypendium\n" : "\n");
}
