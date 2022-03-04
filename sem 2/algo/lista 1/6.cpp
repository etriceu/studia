#include <iostream>

using namespace std;

void hanoi(int n, char a = 'A', char b = 'B', char c = 'C')
{
	if(n == 0)
		return;
	
	hanoi(n-1, a, c, b);
	cout<<a<<" -> "<<c<<endl;
	hanoi(n-1, b, a, c);
}

int main()
{
	int n;
	cin>>n;
	hanoi(n);
}
