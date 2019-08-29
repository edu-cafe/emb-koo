#include <stdio.h>

int main(void)
{
	char s1[] = "apple";
	char *s2 = "banana";

	printf("s1:%s, s2:%s\n", s1, s2);

	s1[0] = 'A';
	s2[0] = 'B';
	printf("s1:%s, s2:%s\n", s1, s2);

	return 0;
}
