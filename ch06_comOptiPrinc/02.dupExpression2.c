#include <stdio.h>

int getData();
int a, b;

int main(void)
{
	int c;
	printf("main->a(%d), b(%d), c(%d)\n", a, b, c);
	c = getData();
	printf("main->a(%d), b(%d), c(%d)\n", a, b, c);
	return c;
}

int getData()
{
	int c;
	scanf("%d %d", &a, &b);
	c = a + b;
	printf("c:%d\n", c);
	if((a + b) > 10 ) c = (a + b) * 2;
	else c = (a + b) * 5;

	return c;
}
