#include <stdio.h>

int main(void)
{
	short data[] = {1, 2, 3, 4, 5};
	short *p1=&data[0], *p2=&data[4];

	printf("p1:%p, p2:%p\n", p1, p2);
	printf("p1+4:%p\n", p1 + 4);
	printf("p2-4:%p\n", p2 - 4);
	printf("p2-p1:%d\n", p2 - p1);
	//printf("p1+p2:%p\n", p1 + p2);
	//printf("p1*p2:%p\n", p1 * p2);
	//printf("p1/p2:%p\n", p1 / p2);
	return 0;
}
