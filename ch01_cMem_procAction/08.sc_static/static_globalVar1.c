#include <stdio.h>

void func2(void);

static int n = 0;

void func1(void)
{
	n++;
	printf("func1 : n=%d\n", n);
}

int main(void)
{
	func1();
	func1();
	func1();
	printf("----------------------\n");
	func2();

	return 0;
}
