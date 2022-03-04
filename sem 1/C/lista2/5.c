#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    scanf("%d", &a);
    if(a > 99)
    {
        printf("1\t%d\n", a%10);
        printf("10\t%d\n", a/10%10);
        printf("100\t%d\n", a/100%10);
    }

    return 0;
}
