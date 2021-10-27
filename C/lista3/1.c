#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
    char str[128];
    do
    {
        scanf("%s", str);

        char res = 1;
        for(int a = 0, b = strlen(str)-1; a < b; a++, b--)
            if(str[a] != str[b])
            {
                res = 0;
                break;
            }

        if(res)
            printf("palindrom\n");


        printf("wykonac jeszcze raz? [y/n]\n");
    } while(getche() == 'y');
    return 0;
}
