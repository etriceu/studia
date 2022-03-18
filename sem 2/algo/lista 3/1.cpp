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
};

void push(lista* &l)
{
	lista *tmp = new lista;
	cout<<"imie: "; cin>>tmp->imie;
	cout<<"nazwisko: "; cin>>tmp->nazwisko;
	cout<<"PESEL: "; cin>>tmp->PESEL;
	cout<<"wiek: "; cin>>tmp->wiek;

	tmp->pop = l;
	l = tmp;
}

bool pop(lista* &l)
{
	if(l == nullptr)
		return false;

    lista *tmp = l->pop;
	delete l;
	l = tmp;
	return true;
}

void show(lista* &l)
{
	for(lista *next = l; next != nullptr; next = next->pop)
		cout<<next->imie<<endl
			<<next->nazwisko<<endl
			<<next->PESEL<<endl
			<<next->wiek<<endl<<endl;
}

void save(lista* &l)
{
	fstream file;
	file.open("plik.txt", ios::out);
	for(lista *next = l; next != nullptr; next = next->pop)
		file<<next->imie<<" "
			<<next->nazwisko<<" "
			<<next->PESEL<<" "
			<<next->wiek<<endl;

	file.close();
}

void menu()
{
	cout<<"a) push"<<endl
		<<"b) pop"<<endl
		<<"c) show"<<endl
		<<"d) save"<<endl
		<<"e) exit"<<endl;
}

int main()
{
	lista *pocz = nullptr;
	menu();
	char cmd;
	do
	{
		cin>>cmd;
		if(cmd == 'a') push(pocz);
		else if(cmd == 'b') pop(pocz);
		else if(cmd == 'c') show(pocz);
		else if(cmd == 'd') save(pocz);
		else if(cmd != 'e') menu();
	} while(cmd != 'e');

	while(pop(pocz));
	return 0;
}
