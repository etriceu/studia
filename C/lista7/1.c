#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

int main()
{
	srand(time(NULL));
    int m[N][N];
	for(int y = 0; y < N; y++, printf("\n"))
		for(int x = 0; x < N; x++)
		{
			int r = rand()%19-9;
			printf("%2d ", r);
			m[y][x] = r;
		}
	
	printf("\n");
	for(int y = 0; y < N; y++, printf("\n"))
		for(int x = 0; x < N; x++)
			printf("%2d ", m[x][y]);
		
    return 0;
}
