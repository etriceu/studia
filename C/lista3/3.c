#include <stdio.h>
#include <conio.h>

int main()
{
    int n, min, max;
    do
    {
        scanf("%d", &n);
        min = n;
        max = n;
        for(int i = 0; i < 9; i++)
        {
            scanf("%d", &n);
            if(n < min)
                min = n;
            if(n > max)
                max = n;
        }

        printf("%d %d\n", min, max);

        printf("wykonac jeszcze raz? [y/n] \n");
    } while(getche() == 'y');
    return 0;
}
