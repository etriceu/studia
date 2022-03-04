#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c, min;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d %d %d\n", a*a, b*b, c*c);
	if(a*a <= b*b && a*a < c*c) min = a;
	else if(b*b <= a*a && b*b < c*c) min = b;
	else min = c;
	printf("min: %d\n", min);
    return 0;
}
