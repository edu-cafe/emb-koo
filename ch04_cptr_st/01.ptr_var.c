#include <stdio.h>

int main(void)
{
	short n1=10, n2=20;
	int n3=0x10203040;
	short *p;
	p = &n1;
	printf("n1:%d, *p:%d\n", n1, *p);
	*p = 100;
	printf("n1:%d, *p:%d\n", n1, *p);
	(*p)++;
	printf("n1:%d, *p:%d\n", n1, *p);
	p = &n2;
	printf("n2:%d, *p:%d\n", n2, *p);
	p = &n3;
	printf("n3:%x, *p:%x\n", n3, *p);
	printf("n3:%x, *p:%x\n", n3, *(p+1));
	return 0;
}
