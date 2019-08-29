#include <stdio.h>

void printData(______, int size)
{
	int i, j, k;

	for(i=0; i<size; i++) {
	  for(j=0; j<3; j++) {
	    for(k=0; k<2; k++) {
		  printf("%d,%d\n", data[i][j][k], *(*(*(data+i)+j)+k));
		}
	  }
	}
}

int main(void)
{
	short arr1[2][3][2] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	______ = arr1;


	printData(p, 2);
	printf("-------------------------\n");

	return 0;
}
