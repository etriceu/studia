#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MIN 100
#define MAX 999

int main()
{
    srand(time(NULL));
	
	char tab[MAX-MIN+1] = {0};
	
	for(int n = 0; n < 5;)
	{
		int r = rand()%(MAX-MIN+1);
		if(!tab[r])
		{
			tab[r] = 1;
			printf("%d\n", r+MIN);
			n++;
		}
	}
	
    return 0;
}
