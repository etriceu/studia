#include <iostream>

using namespace std;

int silnia(int n)
{
	return n <= 0 ? 1 : n*silnia(n-1);
}

int main()
{
	int n;
	cin>>n;
	cout<<silnia(n)<<endl;
}
