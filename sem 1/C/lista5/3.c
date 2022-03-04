#include <stdio.h>
#include <conio.h>

int main()
{
    unsigned short num;
    do
    {
		scanf("%hu", &num);
        for(int n = sizeof(num)*8-4, a; n >= 0; n -= 4)
		{
			a = (num>>n)&0xf;
            printf("%c", a < 10 ? '0'+a : 'A'+a-10);
		}

        printf("\nwykonac jeszcze raz? [y/n] \n");
    } while(getche() == 'y');
    return 0;
}
