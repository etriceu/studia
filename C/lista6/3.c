#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct
{
	int id;
	char imie[20];
	char nazwisko[20];
	int wiek;
} tosoba;

int main()
{
	tosoba osoby[5];
    do
    {
        for(int n = 0; n < 5; n++)
			scanf("%d%s%s%d", &osoby[n].id, osoby[n].imie,
				  osoby[n].nazwisko, &osoby[n].wiek);
		
		char imie[20];
		scanf("%s", imie);
		for(int n = 0; n < 5; n++)
			if(!strcmp(osoby[n].imie, imie))
				printf("%d\n%s\n%s\n%d\n", osoby[n].id, osoby[n].imie,
					   osoby[n].nazwisko, osoby[n].wiek);
		
        printf("\nwykonac jeszcze raz? [y/n] \n");
    } while(getche() == 'y');
    return 0;
}
