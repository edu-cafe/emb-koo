#include <stdio.h>
int a;

void func(void) {
	int c=100;
	printf("func() -> a:%d, c:%d\n", a, c);
}

int main()
{
	int a = 10;
	{
		int a = 200, b=300;
		printf("main_inner_block -> a:%d, b:%d\n", a, b);
	}
	printf("main_outer_block -> a:%d\n", a);
	//printf("main_outer_block -> b:%d\n", b);
	func();
	//printf("main_outer_block -> c:%d\n", c);

	return 0;
}
