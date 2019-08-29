#include <stdio.h>

int main(void)
{
	short d = 10;
	short *p1 = &d;
	short **p2 = &p1;
	short ***p3 = &p2;

	printf("&d:%p, p1:%p, d:%d, *p1:%d\n", &d, p1, d, *p1);
	printf("p1:%p, *p2:%p, d:%d, **p2:%d\n", p1, *p2, d, **p2);
	printf("*p2:%p, **p3:%p, d:%d, ***p3:%d\n", *p2, **p3, d, ***p3);

	return 0;
}
