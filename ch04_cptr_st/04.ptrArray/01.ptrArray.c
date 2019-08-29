#include <stdio.h>

int main(void)
{
	char *p1 = "kim";
	char *p2 = "Hello!!!";
	char *p3 = "Hi~~";
	
	______p[3] = {"kim", "Hello!!!", "Hi~~"};

	for(int i=0; i<3; i++) {
		puts(p[i]);
	}

	return 0;
}

//gcc -Wall -std=c99 ptrArray.c
