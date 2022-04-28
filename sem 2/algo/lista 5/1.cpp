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
	
	bool insert()
	{
		lista *tmp = new lista;
		cout<<"imie: "; cin>>tmp->imie;
		cout<<"nazwisko: "; cin>>tmp->nazwisko;
		cout<<"PESEL: "; cin>>tmp->PESEL;
		cout<<"wiek: "; cin>>tmp->wiek;

		bool added = false, duplicate = false;
		for(lista *next = pocz; next != nullptr; next = next->nast)
		{
			if(next->nazwisko > tmp->nazwisko && !added)
			{
				tmp->nast = next;
				tmp->pop = next->pop;
				if(tmp->pop) tmp->pop->nast = tmp;
				else pocz = tmp;
				next->pop = tmp;
				added = true;
			}
			else if(next->nast == nullptr && !added)
			{
				next->nast = tmp;
				tmp->pop = next;
				added = true;
			}
			if(	!duplicate &&
				next != tmp &&
				next->nazwisko == tmp->nazwisko &&
				next->imie == tmp->imie &&
				next->PESEL == tmp->PESEL &&
				next->wiek == tmp->wiek)
				duplicate = true;
		}
		
		if(pocz == nullptr)
			pocz = tmp;
		
		if(duplicate)
			cout<<"Podobny element juz jest w liscie\n";
		
		return duplicate;
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
		
		cout<<"a) zapisz wszystkie\n"
			<<"b) o podanym nazwisku\n"
			<<"c) pelnoletnie\n";
		
		string nazwisko;
		char odp;
		cin>>odp;
		if(odp == 'b')
			cin>>nazwisko;
		
		for(lista *next = pocz; next != nullptr; next = next->nast)
			if(	odp == 'a' ||
				(odp == 'b' && next->nazwisko == nazwisko) ||
				(odp == 'c' && next->wiek >= 18))
				file<<next->imie<<" "<<next->nazwisko<<" "
					<<next->PESEL<<" "<<next->wiek<<endl;

		file.close();
	}
	
	void read()
	{
		fstream file;
		file.open("plik.txt", ios::in);
		
		for(string line; getline(file, line); cout<<line<<endl);
		
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
		<<"h) read"<<endl
		<<"i) exit"<<endl;
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
		else if(cmd == 'h') lista.read();
		else if(cmd != 'i') menu();
	} while(cmd != 'i');

	return 0;
}
