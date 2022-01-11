#include <stdio.h>
#include <stdlib.h>

int func()
{
	int k, sum = 0;
	scanf("%d", &k);
	for(int n = 1; n <= k; n++)
		sum += n*n*n;
	
	return sum;
}

int main()
{
	printf("%d\n", func());
	
    return 0;
}
