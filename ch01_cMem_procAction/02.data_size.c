#include <stdio.h>

int main()
{
	printf("char:%d, short:%d, int:%d, long:%d\n", 
		sizeof(char), sizeof(short), sizeof(int), sizeof(long));
	printf("long long:%d, float:%d, double:%d, long double:%d\n", 
		sizeof(long long), sizeof(float), sizeof(double), sizeof(long double));

	return 0;
}
