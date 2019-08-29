#include <stdio.h>

int main(void)
{
	short a[2][3] = {{1, 2, 3}, {4, 5, 6}};

	printf("a[0]:%p, *a:%p\n", a[0], *a);
	printf("a[0]+1:%p, *a+1:%p\n", a[0]+1, *a+1);
	printf("*a[0]:%d, **a:%d\n", *a[0], **a);
	printf("*(a[0]+1):%d, *(*a+1):%d\n", *(a[0]+1), *(*a+1));
	printf("-------------------------------\n");
	printf("a[1]:%p, *(a+1):%p\n", a[1], *(a+1));
	printf("a[1]+1:%p, *(a+1)+1:%p\n", a[1]+1, *(a+1)+1);
	printf("*a[1]:%d, *(*(a+1)):%d\n", *a[1], **(a+1));
	printf("*(a[1]+1):%d, *(*(a+1)+1):%d\n", *(a[1]+1), *(*(a+1)+1));

	return 0;
}
