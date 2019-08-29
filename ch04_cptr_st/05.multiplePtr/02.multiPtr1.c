#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	short data = 0x1122;
	______p1=&data;
	______p2=&p1;
	______p3=&p2;
	
	printf("data => %x, %x, %x, %x\n", data, *p1, **p2, ***p3);
	printf("addr_data => %p, %p, %p, %p\n", &data, p1, *p2, **p3);
	printf("addr_p1 => %p, %p, %p\n", &p1, p2, *p3);
	printf("addr_p2 => %p, %p\n", &p2, p3);

	return 0;
}
