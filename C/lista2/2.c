#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if(a%2 == 0 || b%2 == 0 || c%2 == 0)
		printf("parzysta\n");

    return 0;
}
