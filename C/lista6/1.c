#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    do
    {
		int n, res = 0;
		char str[10];
		
        for(scanf("%d", &n); n > 0; n--)
		{
			scanf("%s", str);
			if(str[strlen(str)-1] == 'a')
				res++;
		}

        printf("%d\nwykonac jeszcze raz? [y/n] \n", res);
    } while(getche() == 'y');
	
    return 0;
}
