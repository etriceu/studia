#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
    do
    {
		int tab[100], sum = 0;
        for(int n = 0; n < 100; n++)
		{
			int r = rand()%80;
			tab[n] = r < 40 ? r-50 : r-29;
			if(tab[n]%2 == 0)
				sum += tab[n];
		}

        printf("%d\nwykonac jeszcze raz? [y/n] \n", sum);
    } while(getche() == 'y');
    return 0;
}

/*
int main()
{
	srand(time(NULL));
    do
    {
		int sum = 0;
        for(int n = 0; n < 100; n++)
		{
			int r = rand()%80;
			r -= r < 40 ? 50 : 29;
			if(r%2 == 0)
				sum += r;
		}

        printf("%d\nwykonac jeszcze raz? [y/n] \n", sum);
    } while(getche() == 'y');
    return 0;
}*/
