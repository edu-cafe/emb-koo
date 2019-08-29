#include <stdio.h>

void printData(......., int size)
{
	int i, j;

	for(i=0; i<size; i++) {
	  for(j=0; j<3; j++) {
		printf("%d,%d\n", ......... );
	  }
	}
}

int main(void)
{
	short a1[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	short a2[4][3] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};
	short a3[2][3] = {100, 200, 300, 400, 500, 600};
	
	.......

	p = a1;
	printData(p, 3);
	printf("-------------------------\n");
	p = a2;
	printData(p, 4);
	printf("-------------------------\n");
	p = a3;
	printData(p, 2);

	return 0;
}
