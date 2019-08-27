#include <stdio.h>

int main(void)
{
	int n1=10;
	const n2=20;

	n1++;
	n2++;
	printf("n1:%d\n", n1);
	printf("n2:%d\n", n2);
	
	return 0;
}
