#include <stdio.h>

int main(void)
{
	char c = 'A';
	short s = 10;
	int i = 100;
	float f = 1000.1F;
	void *p;

	p = (void *)&c;
	printf("c:%c, *p:%c\n", c, *(______p));
	p = (void *)&s;
	printf("s:%d, *p:%d\n", s, *(______p));
	p = (void *)&i;
	printf("i:%d, *p:%d\n", i, *(______p));
	p = (void *)&f;
	printf("f:%.1f, *p:%.1f\n", f, *(______p));

	return 0;
}
