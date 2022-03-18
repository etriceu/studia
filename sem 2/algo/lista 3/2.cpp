#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

struct lista
{
	string imie;
	string nazwisko;
	string PESEL;
	int wiek;
	lista *nast = nullptr;
};

class List
{
public:
	~List()
	{
		clear();
	}
	
	void push_back()
	{
		lista *tmp = new lista;
		cout<<"imie: "; cin>>tmp->imie;
		cout<<"nazwisko: "; cin>>tmp->nazwisko;
		cout<<"PESEL: "; cin>>tmp->PESEL;
		cout<<"wiek: "; cin>>tmp->wiek;

		if(pocz == nullptr)
			pocz = tmp;

		if(kon != nullptr)
			kon->nast = tmp;
		
		kon = tmp;
		size++;
	}

	bool pop_front()
	{
		if(pocz == nullptr)
			return false;

		lista *tmp = pocz->nast;
		if(pocz == kon)
			kon = nullptr;
		delete pocz;
		pocz = tmp;
		size--;
		return true;
	}

	void show()
	{
		for(lista *next = pocz; next != nullptr; next = next->nast)
			cout<<next->imie<<endl
				<<next->nazwisko<<endl
				<<next->PESEL<<endl
				<<next->wiek<<endl<<endl;
	}
	
	void clear()
	{
		while(pop_front());
	}

	void save()
	{
		fstream file;
		file.open("plik.txt", ios::out);
		
		lista **tab = new lista*[size];
		size_t n = 0;
		for(lista *next = pocz; next != nullptr; next = next->nast, n++)
			tab[n] = next;
		
		sort(tab, tab+size, [](lista *a, lista *b){return a->wiek < b->wiek;});
		
		for(n = 0; n < size; n++)
			file<<tab[n]->imie<<" "
				<<tab[n]->nazwisko<<" "
				<<tab[n]->PESEL<<" "
				<<tab[n]->wiek<<endl;

		file.close();
	}
	
	void remove()
	{
		string str;
		cout<<"imie: "; cin>>str;
		for(lista *obj = pocz, *old = pocz; obj != nullptr;)
			if(obj->imie == str)
			{
				if(obj == pocz)
				{
					pop_front();
					old = pocz;
					obj = pocz;
				}
				else
				{
					old->nast = obj->nast;
					if(kon == obj)
						kon = old;
					delete obj;
					obj = old->nast;
				}
			}
			else
			{
				old = obj;
				obj = obj->nast;
			}
	}
	
private:
	lista *pocz = nullptr, *kon = nullptr;
	size_t size = 0;
};

void menu()
{
	cout<<"a) push_back"<<endl
		<<"b) pop_front"<<endl
		<<"c) show"<<endl
		<<"d) clear"<<endl
		<<"e) save"<<endl
		<<"f) remove"<<endl
		<<"g) exit"<<endl;
}

int main()
{
	List lista;
	menu();
	char cmd;
	do
	{
		cin>>cmd;
		if(cmd == 'a') lista.push_back();
		else if(cmd == 'b') lista.pop_front();
		else if(cmd == 'c') lista.show();
		else if(cmd == 'd') lista.clear();
		else if(cmd == 'e') lista.save();
		else if(cmd == 'f') lista.remove();
		else if(cmd != 'g') menu();
	} while(cmd != 'g');

	return 0;
}
