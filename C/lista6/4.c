#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    srand(time(NULL));
	char tab[100];
	do
    {
		for(int n = 0; n < 100; n++)
		{
			tab[n] = rand()%201-100;
			printf("%d ", tab[n]);
		}
		
		for(int n, i = 99, end = 0; !end; i--)
			for(n = 0, end = 1; n < i; n++)
				if(tab[n] > tab[n+1])
				{
					int tmp = tab[n];
					tab[n] = tab[n+1];
					tab[n+1] = tmp;
					end = 0;
				}

		printf("\n\n");
		for(int n = 0; n < 100; n++)
			printf("%d ", tab[n]);
		
		printf("\nwykonac jeszcze raz? [y/n] \n");
    } while(getche() == 'y');
	
    return 0;
}
