#include <stdio.h>

int a, b = 0;

int main(void)
{
	scanf("%d", &a);
	if(a<0 && a>10) b = 10;
	if(a<0 || a>10) b = 20;
	printf("b:%d\n", b);
	
	return 0;
}
