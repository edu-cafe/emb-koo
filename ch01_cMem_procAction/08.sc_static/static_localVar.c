#include <stdio.h>

void func1(void)
{
	int n=0;

	n++;
	printf("func1 : n=%d\n", n);
}

void func2(void)
{
	static int n=0;

	n++;
	printf("func2 : n=%d\n", n);
}

int main(void)
{
	func1();
	func1();
	func1();
	printf("----------------------\n");
	func2();
	func2();
	func2();

	return 0;
}
