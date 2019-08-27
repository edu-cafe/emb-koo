#include <stdio.h>

int main()
{
	char c;
	unsigned char d;
	
	c = 0x80;
	printf("c : %d(%u)\n", c, c);
	d = 0x80;
	printf("d : %d(%u)\n", d, d);
	printf("---------------------------------\n");

	c = 0xff;
	if (c == 0xff) printf("true\n");
	else printf("false\n");

	d = 0xff;
	if (d == 0xff) printf("true\n");
	else printf("false\n");
	printf("---------------------------------\n");

	printf("signed_0xff : %x(%d), unsigned_0xff : %x(%d))\n", 
		(signed char)0xff, (signed char)0xff,
		(unsigned char)0xff, (unsigned char)0xff);

	return 0;
}
