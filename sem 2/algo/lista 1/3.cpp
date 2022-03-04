#include <iostream>

using namespace std;

int fibo(int n)
{
	return n <= 1 ? 1 : fibo(n-1)+fibo(n-2);
}

int main()
{
	int n;
	cin>>n;
	cout<<fibo(n)<<endl;
}
