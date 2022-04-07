#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct lista
{
	string imie;
	string nazwisko;
	string PESEL;
	int wiek;
	lista *pop = nullptr;
	lista *nast = nullptr;
};

class List
{
public:
	~List()
	{
		for(lista *next = pocz, *tmp = pocz;
			next != nullptr;
			tmp = next, next = next->nast, delete tmp);
	}
	
	void insert()
	{
		lista *tmp = new lista;
		cout<<"imie: "; cin>>tmp->imie;
		cout<<"nazwisko: "; cin>>tmp->nazwisko;
		cout<<"PESEL: "; cin>>tmp->PESEL;
		cout<<"wiek: "; cin>>tmp->wiek;

		if(pocz != nullptr)
		{
			tmp->nast = pocz;
			pocz->pop = tmp;
		}
			
		pocz = tmp;
	}

	bool remove(string str)
	{
		for(lista *next = pocz; next != nullptr; next = next->nast)
			if(next->nazwisko == str)
			{
				if(next->nast == nullptr && next->pop != nullptr)
					next->pop->nast = nullptr;
				else if(next->nast != nullptr && next->pop != nullptr)
				{
					next->pop->nast = next->nast;
					next->nast->pop = next->pop;
				}
				else if(next->nast != nullptr && next->pop == nullptr)
				{
					pocz = next->nast;
					next->nast->pop = nullptr;
				}
				else
					pocz = nullptr;
				
				delete next;
				return true;
			}

		return false;
	}
	
	void removeAll(string str)
	{
		while(remove(str));
	}
	
	void find(string str)
	{
		for(lista *next = pocz; next != nullptr; next = next->nast)
			if(next->nazwisko == str)
				cout<<next->imie<<endl<<next->nazwisko<<endl
					<<next->PESEL<<endl<<next->wiek<<endl<<endl;
	}
	
	void edit(string str)
	{
		for(lista *next = pocz; next != nullptr; next = next->nast)
			if(next->nazwisko == str)
			{
				cout<<"imie: "; cin>>next->imie;
				cout<<"nazwisko: "; cin>>next->nazwisko;
				cout<<"PESEL: "; cin>>next->PESEL;
				cout<<"wiek: "; cin>>next->wiek;
				return;
			}
	}

	void show()
	{
		for(lista *next = pocz; next != nullptr; next = next->nast)
			cout<<next->imie<<endl<<next->nazwisko<<endl
				<<next->PESEL<<endl<<next->wiek<<endl<<endl;
	}

	void save()
	{
		fstream file;
		file.open("plik.txt", ios::out);
		
		for(lista *next = pocz; next != nullptr; next = next->nast)
			file<<next->imie<<" "<<next->nazwisko<<" "
				<<next->PESEL<<" "<<next->wiek<<endl;

		file.close();
	}
	
private:
	lista *pocz = nullptr;
};

void menu()
{
	cout<<"a) insert"<<endl
		<<"b) remove"<<endl
		<<"c) removeAll"<<endl
		<<"d) find"<<endl
		<<"e) show"<<endl
		<<"f) edit"<<endl
		<<"g) save"<<endl
		<<"h) exit"<<endl;
}

int main()
{
	List lista;
	menu();
	char cmd;
	do
	{
		cin>>cmd;
		if(cmd == 'a') lista.insert();
		else if(cmd == 'b' || cmd == 'c' || cmd == 'd' || cmd == 'f')
		{
			string str;
			cout<<"nazwisko: "; cin>>str;
			if(cmd == 'b') lista.remove(str);
			else if(cmd == 'c') lista.removeAll(str);
			else if(cmd == 'd') lista.find(str);
			else lista.edit(str);
		}
		else if(cmd == 'e') lista.show();
		else if(cmd == 'g') lista.save();
		else if(cmd != 'h') menu();
	} while(cmd != 'h');

	return 0;
}
