#include <stdio.h>

int main(void)
{
	short arr[5] = {1, 2, 3, 4, 5};
	short *p = arr;
	int i;

	for(i=0, p=arr; i<5; i++, p++) {
		printf("%d,%d\n", arr[i], *p);
	}
	p = &arr[0];
	printf("p[2] : %d\n", p[2]);
	p = &arr[2];
	printf("p[2] : %d\n", p[2]);

#ifdef TEST
	for(i=0, p=arr; i<5; i++, arr++) {
		printf("%d,%d\n", p[i], *arr);
	}
#endif

	return 0;
}
