#include <stdio.h>
#include <conio.h>

int main()
{
	do
	{
		int n;
		scanf("%d", &n);
		
		if(n >= 1 && n <= 15)
			for(int a = n; a > 0; a--)
			{
				for(int b = 0; b < n*2-a; b++)
					printf(b < a-1 ? " " : "*");
					
				printf("\n");
			}

		printf("wykonac jeszcze raz? [y/n] \n");
	} while(getche() == 'y');
}
