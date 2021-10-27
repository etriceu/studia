#include <stdio.h>
#include <math.h>

int main()
{
    float r;
    printf("R = ");
    scanf("%f", &r);
    printf("V = %f\nP = %f\n", 4.0/3*M_PI*r*r*r, 4*M_PI*r*r);
    return 0;
}
