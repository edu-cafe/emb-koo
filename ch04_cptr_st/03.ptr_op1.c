#include <stdio.h>

int main(void)
{
	short data[] = {1, 2, 3, 4, 5};
	short *p;
	p = &data[0];	//p = data;
	printf("data[0]:%d, *p:%d\n", data[0], *p);
	p++;
	printf("data[1]:%d, *p:%d\n", data[1], *p);
	p += 2;
	printf("data[3]:%d, *p:%d\n", data[3], *p);
	p += -2;
	printf("data[1]:%d, *p:%d\n", data[1], *p);

	//p *= 2;
	//p /= 2;
	return 0;
}
