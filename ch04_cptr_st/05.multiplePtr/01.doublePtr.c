#include <stdio.h>
#include <stdlib.h>

int allocateArray(______arr, int size, int value)
{
	_____ = (int*)malloc(size * sizeof(int));
	if(*arr == NULL) return -1;
	for(int i=0; i<size; i++) {
		______ = value;
	}
	return 0;
}

void printArray(int *arr, int size) {
	for(int i=0; i<size; i++) {
		printf("arr[%d] : %d\n", i, arr[i]);
	}
}

int main(void)
{
	int *vector = NULL;
	allocateArray(&vector, 5, 30);
	printArray(vector, 5);
	return 0;
}

