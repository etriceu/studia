#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main()
{
	srand(time(NULL));
    int size, sum[2] = {0};
	scanf("%d", &size);
	if(size < 1 || size > 10)
		return 1;
	
	int m[size][size];
	for(int y = 0; y < size; y++, printf("\n"))
		for(int x = 0; x < size; x++)
		{
			m[x][y] = rand()%21-10;
			printf("%3d ", m[x][y]);
		}
		
	for(int n = 0; n < size; n++)
	{
		sum[0] += m[n][n];
		sum[1] += m[size-n-1][n];
	}
	printf("%d %d\n", sum[0], sum[1]);
		
    return 0;
}
