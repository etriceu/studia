#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    do
    {
		int n, res = 0;
		scanf("%d", &n);
		char str[10];
		
        for(int a = 0; a < n; a++)
		{
			scanf("%s", str);
			if(str[strlen(str)-1] == 'a')
				res++;
		}

        printf("%d\nwykonac jeszcze raz? [y/n] \n", res);
    } while(getche() == 'y');
	
    return 0;
}
