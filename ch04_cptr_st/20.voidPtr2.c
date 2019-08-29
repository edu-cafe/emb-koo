#include <stdio.h>

int main(void)
{
	char c[51+1] = "ABCDE";
	short s[5] = {10, 20, 30, 40, 50};
	int i[5] = {100, 200, 300, 400, 500};
	float f[5] = {1000.1F, 2000.2F, 3000.3F, 4000.4F, 5000.5F};
	void *p;

	p = (void *)c;    //p = (char *)p + 1;       
	p = p + 1;
	printf("c:%c, *p:%c\n", c[1], *((char *)p));
	
	p = (void *)s;    p = (short *)p + 1;
	//p = p + 1;
	printf("s:%d, *p:%d\n", s[1], *((short *)p));
	p = (void *)s;    p = (char *)p + 2;
	printf("s:%d, *p:%d\n", s[1], *((short *)p));
	
	p = (void *)i;    p = (int *)p + 1;
	printf("i:%d, *p:%d\n", i[1], *((int *)p));
	p = (void *)f;    p = (float *)p + 1;
	printf("f:%.1f, *p:%.1f\n", f[1], *((float *)p));

	return 0;
}
