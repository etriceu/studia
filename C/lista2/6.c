#include <stdio.h>
#include <math.h>

int main()
{
    int a;
    scanf("%d", &a);
    int b = sqrt(a);
    printf(b*b == a ? "tak\n" : "nie\n");
    return 0;
}
