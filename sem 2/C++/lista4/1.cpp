#include <iostream>
#include <vector>

#include "mylib.hpp"

using namespace std;

int main()
{
	int num;
	cout<<"N: "; cin>>num;
	
	vector <int> tab;
	for(int n = 0, a; n < num; n++)
	{
		cin>>a;
		tab.push_back(a);
	}
	
	int tmp = my::min(tab.begin(), tab.size());
	cout<<"Min: "<<tab[tmp]<<" at "<<tmp<<endl;
	tmp = my::max(tab.begin(), tab.size());
	cout<<"Max: "<<tab[tmp]<<" at "<<tmp<<endl;
	cout<<"Find: ";
	cin>>tmp;
	cout<<"Index: "<<my::find(tab.begin(), tab.size(), tmp)<<endl;
}
