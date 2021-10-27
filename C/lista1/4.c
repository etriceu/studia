#include <stdio.h>

int main()
{
    int c;
    printf("Podaj C: ");
    scanf("%d", &c);
    printf("Wynik: %f\n", (c*2-c+5.0)/(1.0/(c*c)));
    return 0;
}
