#include <stdio.h>
#include <conio.h>

int main()
{
    do
    {
        int n, i = 2;
        double res = 0;
        scanf("%d", &n);
		if(n > 0)
		{
			printf("1");
			res = 1;
		}
		
        for(; i <= n; i++)
        {
            printf(" + 1/%d", i);
            res += 1.0/i;
        }
        printf(" = %lf\n", res);

        printf("wykonac jeszcze raz? [y/n] \n");
    } while(getche() == 'y');
    return 0;
}
