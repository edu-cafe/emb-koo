#include <stdio.h>

int main(void)
{
	int a, b, c;
	scanf("%d %d", &a, &b);
	c = a + b;
	printf("c:%d\n", c);
	if((a + b) > 10 ) c = (a + b) * 2;
	else c = (a + b) * 5;

	return c;
}
