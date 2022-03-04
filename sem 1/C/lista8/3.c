#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fill(double *tab)
{
	int n;
	scanf("%d", &n);
	
	if(n < 1 || n > 10)
		return;
	
	for(int y = 0; y < n; y++)
		for(int x = 0; x < n; x++)
			tab[x+y*10] = rand()/(RAND_MAX+0.)*20-10;
}

int main()
{
	srand(time(NULL));
    double tab[10][10] = {0};
	fill(*tab);
	for(int y = 0; y < 10; y++)
	{
		for(int x = 0; x < 10; x++)
			printf("%f ", tab[x][y]);
		
		printf("\n");
	}
    return 0;
}
