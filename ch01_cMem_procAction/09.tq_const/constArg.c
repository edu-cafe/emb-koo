#include <stdio.h>
void constArgTest1(int * p) {
	printf("p:%p, *p:%d\n", p, *p);
	(*p)++;
	printf("p:%p, *p:%d\n", p, *p);
	p++;
	printf("p:%p, *p:%d\n", p, *p);
}
void constArgTest2(const int * p) {
	printf("p:%p, *p:%d\n", p, *p);
	(*p)++;
	printf("p:%p, *p:%d\n", p, *p);
	p++;
	printf("p:%p, *p:%d\n", p, *p);
}
void constArgTest3(int * const p) {
	printf("p:%p, *p:%d\n", p, *p);
	(*p)++;
	printf("p:%p, *p:%d\n", p, *p);
	p++;
	printf("p:%p, *p:%d\n", p, *p);
}

int main(void)
{
	int arr[] = {1, 2, 3};
	int *p=arr;

	constArgTest1(p);
	printf("----------------------------------\n");
	constArgTest2(p);
	printf("----------------------------------\n");
	constArgTest3(p);

	return 0;
}
