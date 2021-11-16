#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct
{
	int id;
	char imie[20];
	char nazwisko[20];
	int rok_u, mies_u, dzien_u;
} tosoba;

int main()
{
	srand(time(NULL));
    tosoba os;
	
	sprintf(os.imie, "imie%d", rand()%100);
	sprintf(os.nazwisko, "naz%d", rand()%100);
	os.rok_u = rand()%100+1900;
	os.mies_u = rand()%12+1;
	os.dzien_u = rand()%31+1;
	os.id = rand()%100+1;
	
    return 0;
}
