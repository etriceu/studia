#include <iostream>
#include <string>

using namespace std;

class MyVector
{
public:
	~MyVector()
	{
		if(tab != nullptr)
			delete [] tab;
	}
	
	void add(string str)
	{
		string *tmp = new string[_size+1];
		
		for(unsigned int n = 0; n < _size; n++)
			tmp[n] = tab[n];
		
		if(tab != nullptr)
			delete [] tab;
		
		tab = tmp;
		tab[_size] = str;
		_size++;
	}
	
	unsigned int size()
	{
		return _size;
	}
	
	string &operator[](unsigned int n)
	{
		if(tab != nullptr && n < _size)
			return tab[n];
		else
			throw "Invalid index!";
	}
	
private:
	string *tab = nullptr;
	unsigned int _size = 0;
};

void licz(string str)
{
	char c;
	cout<<"Znak do pominiecia: "; cin>>c;
	
	int a = 0, b = 0;
	for(char x : str)
	{
		a += x != ' ';
		b += x != c;
	}
	cout<<"wszystkie: "<<str.size()
		<<"\nbez spacji: "<<a
		<<"\nbez znaku: "<<b<<endl;
}

void wyrazy(string str)
{
	for(char x : str)
		cout<<(x == ' ' ? '\n' : x);
	
	cout<<endl;
}

void podziel(string str)
{
	char c;
	cout<<"znak podzialu: "; cin>>c;
	
	MyVector tab;
	string tmp;
	for(char x : str)
		if(x == c)
		{
			tmp += x;
			tab.add(tmp);
			tmp = "";
		}
		else
			tmp += x;
	
	if(tmp != "")
		tab.add(tmp);
	
	for(int n = 0; n < tab.size(); n++)
		cout<<tab[n]<<endl;
}

int main()
{
	string str;
	cout<<"Text: ";
	getline(cin, str);
	licz(str);
	wyrazy(str);
	podziel(str);
}
