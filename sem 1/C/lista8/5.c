#include <stdio.h>
#include <stdlib.h>

double func(int n)
{
	double sum = 0;
	for(int a = 1; a <= n; a++)
	{
		double tmp = a%2 ? 1.0/a : -1.0/a;
		printf("%f ", tmp);
		sum += tmp;
	}
	return sum;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("\n%f\n", func(n));
	
    return 0;
}
