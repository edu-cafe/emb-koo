#include <stdio.h>

int f1(int d1, int d2);

int main(void)
{
	int a, b, c;
	a = 10;
	b = 20;
	c = f1(a, b);
	printf("c:%d\n", c);
	return 0;
}

int f1(int d1, int d2)
{
	int rst;
	d1 += 10;
	d2 = d1 + 5;
	rst = d1 + d2;
	return rst;
}
