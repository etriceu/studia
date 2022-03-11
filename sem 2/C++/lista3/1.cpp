#include <iostream>

using namespace std;

int func(double kwota, double opr, double okres, double kwota2)
{
	int n = 0;
	do
	{
		kwota *= 1+opr*okres/1200;
		n++;
	} while(kwota < kwota2);
	return n*okres;
}

int main()
{
	double kwota, opr, okres, kwota2;
	cout<<"kwota: "; cin>>kwota;
	cout<<"oprocentowanie: "; cin>>opr;
	cout<<"okres: "; cin>>okres;
	cout<<"oczekiwana kwota: "; cin>>kwota2;
	cout<<func(kwota, opr, okres, kwota2)<<" miesiac(y)\n";
}
