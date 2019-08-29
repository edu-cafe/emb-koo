#include <stdio.h>

short f1(short n)
{
	n++;
	return n;
}
short f2(short *n)
{
	(*n)++;
	return *n;
}

int main(void)
{
	short n1=10, n2=10, n3;
	n3 = f1(n1);
	printf("n1:%d, n2:%d, n3:%d\n", n1, n2, n3);
	n3 = f2(&n2);
	printf("n1:%d, n2:%d, n3:%d\n", n1, n2, n3);
	return 0;
}
