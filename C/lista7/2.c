#include <stdio.h>

#define N 5

int main()
{
    int m[N][N], col, sum = 0;
	for(int *i = m[0], n; i < m[0]+N*N; i++)
	{
		scanf("%d", &n);
		*i = n;
		if(n < -5 || n >= 10 || n == 0)
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
