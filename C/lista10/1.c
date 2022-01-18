#include <stdio.h>

#define SIZE 50

void save(void *ptr)
{
	FILE *file = fopen("1.txt", "w");
	fprintf(file, "%.*s", SIZE, ptr);
	fclose(file);
	file = fopen("2.bin", "wb");
	fwrite(ptr, sizeof(char), SIZE, file);
	fclose(file);
}

int main()
{
	char buf[SIZE] = {'h', 'e', 'l', 'l', 'o', '\0', 1, 2, 3, 'w', 'o', 'r', 'd'};
	save(buf);
    return 0;
}
