#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef struct
{
	int id;
	char imie[20] = {0};
	char nazwisko[20] = {0};
	int wiek;
} tosoba;

class Osoby
{
public:
	~Osoby()
	{
		if(tab != nullptr)
			delete [] tab;
	}

	void add(tosoba os)
	{
		tosoba *tmp = new tosoba[size+1];

		for(unsigned int n = 0; n < size; n++)
			tmp[n] = tab[n];

		if(tab != nullptr)
			delete [] tab;

		tab = tmp;
		tab[size] = os;
		size++;
	}

	void print()
	{
		for(int n = 0; n < size; n++)
			cout<<tab[n].id<<endl
				<<tab[n].imie<<endl
				<<tab[n].nazwisko<<endl
				<<tab[n].wiek<<endl<<endl;
	}

	unsigned int find(string str)
	{
		for(int n = 0; n < size; n++)
			if(tab[n].nazwisko == str)
				return n;
		
		throw "Not found.";
	}
	
	void sort()
	{
		std::sort(tab, tab+size, [](tosoba a, tosoba b)
		{return string(a.nazwisko) < string(b.nazwisko);});
	}
	
	void remove(string str)
	{
		unsigned int pos;
		try
		{
			pos = find(str);
		}
		catch(const char *str)
		{
			return;
		}
		
		tosoba *tmp = new tosoba[size-1];
		
		for(unsigned int n = 0; n < pos; n++)
			tmp[n] = tab[n];
		
		for(unsigned int n = pos+1; n < size; n++)
			tmp[n-1] = tab[n];

		if(tab != nullptr)
			delete [] tab;

		tab = tmp;
		size--;
	}

private:
	tosoba *tab = nullptr;
	unsigned int size = 0;
};

int main()
{
	Osoby osoby;
	osoby.add({0, "Eee", "Kwer", 30});
	osoby.add({1, "Qqq", "Abc", 20});
	osoby.add({2, "Rrr", "Ofgh", 60});
	osoby.add({3, "Www", "Asdwe", 40});
	osoby.print();
	cout<<"--- Sort ---"<<endl;
	osoby.sort();
	osoby.print();
	cout<<"Find \"Kwer\": "<<osoby.find("Kwer")<<endl;
	cout<<"Remove \"Kwer\""<<endl;
	osoby.remove("Kwer");
	osoby.print();
}
