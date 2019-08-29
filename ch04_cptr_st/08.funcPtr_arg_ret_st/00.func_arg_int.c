#include <stdio.h>

void f1(int num)
{
	num++;
}

void f2(int *num)
{
	(*num)++;
}

int main(void)
{
	int data=10;
	printf("before_f1()==> data:%d\n", data);
	f1(data);
	printf("after_f1()==> data:%d\n", data);
	printf("-------------------------------------\n");
	printf("before_f2()==> data:%d\n", data);
	f2(&data);
	printf("after_f2()==> data:%d\n", data);
	return 0;
}