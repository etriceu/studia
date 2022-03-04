#include <stdio.h>
#include <math.h>

int main()
{
    float a, b;
    printf("Podaj A i B: ");
    scanf("%f%f", &a, &b);

    printf("%f + %f = %f\n", a, b, a+b);
    printf("%f - %f = %f\n", a, b, a-b);
    printf("%f * %f = %f\n", a, b, a*b);
    printf("%f / %f = %f\n", a, b, a/b);
    printf("%f ^ %f = %f\n", a, b, pow(a, b));

    return 0;
}
