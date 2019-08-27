#include <stdio.h>

int func(void);

int d1=10, d2=20, d3;

int main(void)
{
	int rst;

	printf("Main Start..\n");
	
	rst = func();
	printf("rst : %d\n", rst);
	
	printf("Main End..\n");
	
	return 0;
}

int func(void)
{
	d1++;
	d2--;
	d3 = d1 + d2;
	
	return d3;
}