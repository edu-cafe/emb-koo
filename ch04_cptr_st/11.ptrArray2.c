#include <stdio.h>

void printData(short *ap, int size)
{
	int i;

	for(i=0; i<size; i++) {
		printf("%d,%d\n", ap[i], *(ap+i));
	}
}

int main(void)
{
	short a1[5] = {1, 2, 3, 4, 5};
	short a2[] = {10, 20, 30};
	short a3[4] = {100, 200, 300, 400};
	short *p[] = {a1, a2, a3};
	int i;

	for(i=0; i<3; i++) {
		printData(p[i], 3);
		printf("-------------------------\n");
	}

	return 0;
}
