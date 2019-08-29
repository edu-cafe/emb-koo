#include <stdio.h>

int v1, v2;

int main(void)
{
	int i;

	for(i=50; i<100; i++) {
		v1 = i * 8;
		v2 = i / 8;
		printf("v1:%d, v2:%d\n", v1, v2);
	}
		
	return 0;
}
