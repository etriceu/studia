#include <stdio.h>
#include <conio.h>

int main()
{
    int n;
    do
    {
        int n, i = 1;
        double res = 0;
        scanf("%d", &n);
        for(; i < n; i++)
        {
            printf("1/%d + ", i);
            res += 1.0/i;
        }
        res += 1.0/i;
        printf("1/%d = %lf\n", i, res);

        printf("wykonac jeszcze raz? [y/n] \n");
    } while(getche() == 'y');
    return 0;
}
