#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 5

int main()
{
	srand(time(NULL));
    float m[N][N];

	for(int y = 0; y < N; y++, printf("\n"))
		for(int x = 0; x < N; x++)
		{
			m[x][y] = x < y ? 0 : (float)rand()/RAND_MAX*10;
			printf("%5.2f ", m[x][y]);
		}
		
    return 0;
}
