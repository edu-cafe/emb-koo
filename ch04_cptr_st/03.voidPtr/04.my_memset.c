#include <stdio.h>

void *my_memset(void *s, int c, size_t n)
{
	unsigned char *t_s = (unsigned char*)s;

	for (; n; --n, ++t_s) {
		_________
	}
	
	return (s);
}

void printData(void *data, int len)
{
	int i;
	unsigned char *t_data=(unsigned char *)data;
	for(i=1; i<=len; i++) {
		if(i%10) printf("%02X ", t_data[i-1]);
		else printf("%02X\n", t_data[i-1]);
	}
	printf("\n");
}

int main(void)
{
	short data1[30];
	int data2[10];
	char data3[15];
	
	my_memset(data1, 0xAA, sizeof(data1));
	printData(data1, sizeof(data1));
	puts("-----------------------------------------");
	my_memset(data2, 0x00, sizeof(data2));
	printData(data2, sizeof(data2));
	puts("-----------------------------------------");
	my_memset(data3, 0xCE, sizeof(data3));
	printData(data3, sizeof(data3));
	return 0;
}
