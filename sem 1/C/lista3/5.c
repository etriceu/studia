#include <stdio.h>
#include <math.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    for(int n = a; n <= b; n++)
        if(n%2 == 0 && n >= 0)
            printf("%d\n", n);

    for(int n = a; n >= b; n--)
        if(n%2 == 0 && n >= 0)
            printf("%d\n", n);
    return 0;
}
