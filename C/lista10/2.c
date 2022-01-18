#include <stdio.h>

#define SIZE 50

int main()
{
	char buf[SIZE];
	scanf("%s", buf);
	FILE *file = fopen(buf, "r");
	int count = 0;
	for(int c = fgetc(file); c != EOF; c = fgetc(file))
		if(c >= '0' && c <= '9')
			count++;

	fclose(file);
	printf("%d\n", count);
    return 0;
}
