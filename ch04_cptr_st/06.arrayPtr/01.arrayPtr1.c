#include <stdio.h>

void printData(________, int size)
{
	int i, j;

	for(i=0; i<size; i++) {
	  for(j=0; j<3; j++) {
		printf("%d,%d\n", _______, ________);
	  }
	}
}

int main(void)
{
	short arr1[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	short arr2[4][3] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};
	short arr3[2][3] = {100, 200, 300, 400, 500, 600};
	_______ = arr1;

	printf("&arr1[0]:%p, arr1[0]:%p, arr1[1]:%p, arr1[2]:%p\n", &arr1[0], &arr1[0][0], &arr1[1][0], &arr1[2][0]);
	printf("arr1:%p, arr1+0:%p, arr1+1:%p, arr1+2:%p\n", arr1, arr1+0, arr1+1, arr1+2);
	printData(p, 3);
	printf("-------------------------\n");
	p = arr2;
	printData(p, 4);
	printf("-------------------------\n");
	p = arr3;
	printData(p, 2);

#ifdef SOO
	.............
#endif
	return 0;
}
