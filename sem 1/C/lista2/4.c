#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, min;
    scanf("%d%d", &min, &a);
	if(a < min) min = a;
	scanf("%d", &a);
	if(a < min) min = a;
	scanf("%d", &a);
	if(a < min) min = a;
	scanf("%d", &a);
	if(a < min) min = a;
    printf("%d\n", min);
    return 0;
}
