#include <stdio.h>

void printInt(int **data, int size)
{
	int i;

	for(i=0; i<size; i++) {
		printf("%d,%d,%d\n", data[i][0], *data[i], *(*(data+i)));
	}
}

void printStr(char **data, int size)
{
	int i;

	for(i=0; i<size; i++) {
		printf("%s,%s\n", data[i], *(data+i));
	}
}

int main(void)
{
	int intArr[][2] = {1,2,3,4,5,6};
	int *intPArr[] = {intArr[0], intArr[1], intArr[2]};
	char *charPArr[] = {"kim", "lee", "park"};
	int **dp1 = intPArr;
	char **dp2 = charPArr;

	printInt(dp1, 3);
	printf("-------------------------\n");
	printStr(dp2, 3);

	return 0;
}
