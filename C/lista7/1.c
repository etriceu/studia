#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	int N;
	scanf("%d", &N);
	int m[N][N];
	for(int y = 0; y < N; y++, printf("\n"))
		for(int x = 0; x < N; x++)
			printf("%2d ", m[y][x] = rand()%19-9);
	
	printf("\n");
	for(int y = 0; y < N; y++, printf("\n"))
		for(int x = 0; x < N; x++)
			printf("%2d ", m[x][y]);
		
    return 0;
}
