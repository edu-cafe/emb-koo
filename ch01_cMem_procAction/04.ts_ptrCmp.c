#include <stdio.h>

int main()
{
	int a = 10;
	int *p = &a;

	if( p > -1 ) printf("true\n");
	else printf("false\n");

	if( p > 0 ) printf("true\n");
	else printf("false\n");

	return 0;
}
