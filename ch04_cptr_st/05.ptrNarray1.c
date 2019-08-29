#include <stdio.h>

int main(void)
{
	short arr[5] = {1, 2, 3, 4, 5};
	short *p = arr;
	int i;

	printf("arr:%p, &arr[0]:%p, &arr:%p\n", arr, &arr[0], &arr);
	printf("arr+1:%p, &arr[1]:%p, &arr+1:%p\n", arr+1, &arr[1], &arr+1);
	printf("p:%p, &p:%p\n", p, &p);
	printf("p+1:%p, &p+1:%p\n", p+1, &p+1);

	printf("&arr[0]:%p, *&arr[0]:%d\n", &arr[0], *&arr[0]);
	printf("arr[2]:%d, *(a+2):%d, *(2+a):%d, 2[arr]:%d\n", arr[2], *(arr+2), *(2+arr), 2[arr]);

	for(i=0, p=arr; i<5; i++) {
		printf("%d,%d\n", arr[i], p[i]);
		printf("%d,%d\n", *(arr+i), *(p+i));
	}

	return 0;
}
