#include <iostream>

using namespace std;

int nwd(int a, int b)
{
	if(a == b) return a;
	return a > b ? nwd(a-b, b) : nwd(a, b-a);
}

int main()
{
	int a, b;
	cin>>a>>b;
	cout<<nwd(a, b)<<endl;
}
