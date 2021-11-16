#include <stdio.h>
#include <conio.h>

int main()
{
    unsigned short num;
    do
    {
		scanf("%hu", &num);
        for(int n = sizeof(num)*8-1; n >= 0; n--)
            printf("%d", (num>>n)&1);

        printf("\nwykonac jeszcze raz? [y/n] \n");
    } while(getche() == 'y');
    return 0;
}
