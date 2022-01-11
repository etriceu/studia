#include <stdio.h>
#include <stdlib.h>

unsigned int silnia(int  a)
{
	unsigned int ret = 1;
	for(int n = 2; n <= a; n++)
		ret *= n;

	return ret;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%u\n", silnia(n));
    return 0;
}
