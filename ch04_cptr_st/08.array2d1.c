#include <stdio.h>

int main(void)
{
	short a[2][3] = {{1, 2, 3}, {4, 5, 6}};

	printf("&a[0][0]:%p, &a[0][1]:%p\n", &a[0][0], &a[0][1]);
	printf("a[0]:%p, a[0]+1:%p\n", a[0], a[0]+1);
	printf("&a[0][0]:%p, &a[1][0]:%p\n", &a[0][0], &a[1][0]);
	printf("a:%p, a+1:%p\n", a, a+1);

	return 0;
}
