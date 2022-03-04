#include <iostream>

using namespace std;

int main()
{
	cout<<"N: ";
	int n;
	cin>>n;

	for(int y = n; y > 0; y--, cout<<endl)
		for(int x = 0; x < n; x++)
			cout<<(x < y-1 ? " " : "* ");
}
