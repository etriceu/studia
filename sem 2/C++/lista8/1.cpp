#include <iostream>
#include <string>

using namespace std;

struct Osoba
{
	string imie;
	string nazwisko;
	int PESEL;
};

class Urzednik
{
public:
	Urzednik(int VIN, string nrRej, string marka, string model, Osoba wlasciciel)
		: VIN(VIN), nrRejestracji(nrRej), marka(marka), model(model), wlasciciel(wlasciciel)
	{}
	
	void info()
	{
		cout<<"VIN: "<<VIN<<endl
			<<"Rejestracja: "<<nrRejestracji<<endl
			<<"Marka model: "<<marka<<" "<<model<<endl
			<<"Wlasciciel: "<<wlasciciel.imie
			<<" "<<wlasciciel.nazwisko<<endl;
	}
	
	int VIN;
	string nrRejestracji;
	string marka, model;
	Osoba wlasciciel;
};

class Rodzina : public Urzednik
{
public:
	Rodzina(Urzednik car, string silnik, int moc, int poj)
		: Urzednik(car), typSilnika(silnik), mocSilnika(moc), pojemnoscBagaznika(poj)
	{}
	
	void info(bool fullInfo)
	{
		if(fullInfo)
			Urzednik::info();
		
		cout<<"Moc: "<<mocSilnika<<"KM"<<endl
			<<"Cena: "<<cena<<endl
			<<"Paliwo: "<<paliwo<<endl;
			//...
	}
	
	double paliwo, olej, cisnienie;
	int przebieg;
	int mocSilnika;
	int pojemnoscBagaznika;
	int cena;
	string typSilnika;
};

class Mechanik : public Rodzina
{
public:
	Mechanik(Rodzina car)
		: Rodzina(car)
	{}
	
	void info(bool fullInfo)
	{
		if(fullInfo)
			Rodzina::info(fullInfo);
		
		cout<<"Stan: "<<opisStanuPojazdu<<endl
			<<"Awarja abs: "<<abs<<endl
			<<"Awarja elektroniki: "<<ukladElektroniki<<endl;
			//...
	}
	
	string opisStanuPojazdu;
	double klockiHamulcowe;
	// kontrolki alarmowe/awaryjne
	bool abs;
	bool ukladElektroniki;
	bool poduszkaPowietrzna;
	bool wspomaganieKierownicy;
	bool systemHamulcowy;
	
};

int main()
{
	Mechanik brumBrum(Rodzina(
		Urzednik(101, "ONY 1234", "Audi", "A666", {"Bob", "Aasddd", 234723823}),
		"Diesel", 666, 100));
	
	brumBrum.info(false);
	cout<<"----------\n";
	brumBrum.info(true);
}
