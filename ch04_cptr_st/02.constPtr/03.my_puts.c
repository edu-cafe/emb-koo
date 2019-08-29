#include <stdio.h>
#include <string.h>

/*
 * Write the given string to stdout, appending a newline.
 */
int my_puts(___________s)
{
	int c = strlen(s);
	int i;
	for(i=0; i<c; i++) {
		___________
	}
	putchar('\n');
	return c;
}

int main(void)
{
	my_puts("Main Start...");
	my_puts("Hi~~~");
	my_puts("Hello!!");
	my_puts("Main End...");
	
	return 0;
}