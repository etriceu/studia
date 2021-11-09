#include <stdio.h>
#include <conio.h>

int main()
{
	do
	{
		int n;
		scanf("%d", &n);
		
		if(n >= 1 && n <= 15)
			for(int a = 0, b = 0; a <= n; a++, a < (n+1)/2 ? b++ : b--)
			{
				for(int c = 0; c < n/2-b; c++)
					printf(" ");
				for(int c = 0; c <= b; c++)
					printf("*");
					
				printf("\n");
			}

		printf("wykonac jeszcze raz? [y/n] \n");
	} while(getche() == 'y');
}
