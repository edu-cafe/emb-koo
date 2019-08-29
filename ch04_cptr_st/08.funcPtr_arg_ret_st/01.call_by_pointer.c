#include <stdio.h>

#ifndef TEST
void swap(int num1, int num2){
	int tmp;
	tmp = num1;
	num1 = num2;
	num2 = tmp;
}
int main() {
	int n1 = 5;
	int n2 = 10;
	printf("Before--> n1:%d, n2:%d\n", n1, n2);
	swap(n1, n2);
	printf("After--> n1:%d, n2:%d\n", n1, n2);
	return 0;
}
#else
void swapWithPointers(int* pnum1, int* pnum2){
	int tmp;
	tmp = *pnum1;
	*pnum1 = *pnum2;
	*pnum2 = tmp;
}
int main() {
	int n1 = 5;
	int n2 = 10;
	printf("Before--> n1:%d, n2:%d\n", n1, n2);
	swapWithPointers(&n1, &n2);
	printf("After--> n1:%d, n2:%d\n", n1, n2);
	return 0;
}
#endif