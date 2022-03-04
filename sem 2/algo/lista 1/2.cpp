#include <iostream>

using namespace std;

void funcX(int n)
{
	if(n == 0)
		return;
	funcX(n-1);
	cout<<"*";
}

void funcY(int n)
{
	funcX(n);
	cout<<endl;
	if(n != 0)
		funcY(n-1);
}

int main()
{
	int n;
	cin>>n;
	funcY(n);
}
