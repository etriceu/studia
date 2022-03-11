#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef struct
{
	int id;
	char imie[20] = {0};
	char nazwisko[20] = {0};
	int wiek;
} tosoba;

void init(tosoba osoby[], int size)
{
	for(int n = 0; n < size; n++)
	{
		osoby[n].id = n;
		for(int x = 0; x < 5; x++)
		{
			osoby[n].imie[x] = 'a'+rand()%26;
			osoby[n].nazwisko[x] = 'a'+rand()%26;
		}
		osoby[n].wiek = rand()%101;
	}
}

int main()
{
	int num;
	cin>>num;
	tosoba *osoby = new tosoba[num];
	init(osoby, num);

	for(int n = 0; n < num; n++)
		cout<<osoby[n].id<<endl
			<<osoby[n].imie<<endl
			<<osoby[n].nazwisko<<endl
			<<osoby[n].wiek<<endl<<endl;

	delete [] osoby;
}
