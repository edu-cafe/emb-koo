#include <stdio.h>
#include <stdlib.h>

______ allocateArray(int size, int value) {
	int* arr = (int*)malloc(size * sizeof(int));
	for(int i=0; i<size; i++) {
		arr[i] = value;
	}
	return _____;
}

int main(void)
{
	int* vector = allocateArray(5,45);
	for(int i=0; i<5; i++) {
		printf("%d\n", vector[i]);
	}
	_______(vector);
	return 0;
}