#include <stdio.h>

void printData_1(short data[])
{
	int i;

	for(i=0; i<5; i++) {
		printf("%d,%d\n", data[i], *(data+i));
	}
}

void printData_2(short *data)
{
	int i;

	for(i=0; i<5; i++) {
		printf("%d,%d\n", data[i], *(data+i));
	}
}

void updateData(short *data)
{
	int i;
	for(i=0; i<5; i++) data[i] += 10;
}

int main(void)
{
	short arr[5] = {1, 2, 3, 4, 5};

	printf("-------------------------\n");
	printData_1(arr);
	printf("-------------------------\n");
	printData_2(arr);
	printf("-------------------------\n");
	updateData(arr);
	printData_2(arr);

	return 0;
}
