#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 50

size_t sort(char *str) //counting sort
{
	char tab[26] = {0};
	
	for(char *ptr = str; ptr < str+SIZE; ptr++)
		tab[*ptr-'a']++;
	
	for(int n = 0; n < 26; n++)
		for(char *end = str+tab[n]; str < end; str++)
			*str = n+'a';

	return SIZE;
}

int main()
{
	srand(time(NULL));
	
	char str[SIZE];
	for(char *ptr = str; ptr < str+SIZE; ptr++)
		*ptr = rand()%26+'a';
	
	printf("%.*s\n", SIZE, str);
	printf("%d\n%.*s\n", sort(str), SIZE, str);
    return 0;
}
