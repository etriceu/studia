#include <iostream>
#include <vector>

#include "mylib.hpp"

using namespace std;

typedef vector <vector<int>> v2d;
typedef void (*func)(v2d (&)[3], int, int);

int main()
{
	int width, height;
	cout<<"width: "; cin>>width;
	cout<<"height: "; cin>>height;
	v2d m[3];
	for(int n = 0; n < 2; n++)
	{
		m[n].resize(height);
		my::loop2d(m[n], width, height,
			[](auto &m, int x, int y){cin>>x; m[y].push_back(x);});
	}
	m[2].resize(height);
	for(int y = 0; y < height; y++)
		m[2][y].resize(width);
	
	cout<<"a) dodawanie\n"
		<<"b) odejmowanie\n"
		<<"c) mnozenie\n"
		<<"d) exit\n";
	
	func funcs[] = {
		[](v2d (&t)[3], int x, int y){t[2][y][x] = t[0][y][x]+t[1][y][x];},
		[](v2d (&t)[3], int x, int y){t[2][y][x] = t[0][y][x]-t[1][y][x];},
		[](v2d (&t)[3], int x, int y){t[2][y][x] = t[0][y][x]*t[1][y][x];},
	};
	
	for(char menu; cin>>menu && menu >= 'a' && menu < 'd';)
	{
		my::loop2d(m, width, height, funcs[menu-'a']);
		for(auto y : m[2])
		{
			for(auto x : y)
				cout<<x<<" ";
			cout<<endl;
		}
	}
}
