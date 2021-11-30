#include <stdio.h>

#define N 5

int main()
{
    int m[N][N], col, sum = 0;
	for(int *i = m[0]; i < m[0]+N*N; i++)
	{
		scanf("%d", i);
		if(*i < -5 || *i >= 10 || *i == 0)
			i--;
	}
	
	for(int y = 0; y < N; y++, printf("\n"))
		for(int x = 0, i; x < N; x++)
			printf("%3d ", m[y][x]);
	
	scanf("%d", &col);
	for(int y = 0; y < N; y++)
		sum += m[y][col];
	
	printf("%d\n", sum);
		
    return 0;
}
