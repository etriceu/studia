#include <stdio.h>
#include <conio.h>

int main()
{
	do
	{
		int n;
		scanf("%d", &n);
		
		if(n >= 1 && n <= 15)
			for(int a = 1; a <= n; a++)
			{
				for(int b = 0; b < a-1; b++)
					printf(" ");
				for(int b = 0; b < (n-a)*2+1; b++)
					printf("*");
					
				printf("\n");
			}

		printf("wykonac jeszcze raz? [y/n] \n");
	} while(getche() == 'y');
}
