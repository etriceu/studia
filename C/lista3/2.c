#include <stdio.h>
#include <conio.h>

int main()
{
    int n, b;
    do
    {
        scanf("%d", &n);
        for(b = 1; n > 0; n--)
            b *= n;

        printf("%d\n", b);

        printf("wykonac jeszcze raz? [y/n] \n");
    } while(getche() == 'y');
    return 0;
}
