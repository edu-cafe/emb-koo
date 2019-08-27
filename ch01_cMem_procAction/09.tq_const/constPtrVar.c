#include <stdio.h>

int main(void) {
	int n1=10, n2=20, n3=30;
	int * p1=&n1;
	const int * p2=&n1;
	int * const p3=&n1;

	(*p1)++;
	(*p2)++;
	(*p3)++;

	p1 = &n2;
	p2 = &n2;
	p3 = &n2;
	
	return 0;
}
