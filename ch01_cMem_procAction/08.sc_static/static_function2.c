#include <stdio.h>

void func1(void);

extern int n;

void func2(void)
{
	n++;
	printf("func2 : n=%d\n", n);
	func1();
}
