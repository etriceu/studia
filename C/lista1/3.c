#include <stdio.h>

int main()
{
    float a, b, c;
    printf("Podaj A, B i C: ");
    scanf("%f%f%f", &a, &b, &c);
    printf("D = %f\n", b*b-4*a*c);
    return 0;
}
