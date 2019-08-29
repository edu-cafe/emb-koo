#include <stdio.h>

/*
 * Compare strings.
 */
int my_strcmp(_______s1, _________s2)
{
	while (*s1 == *s2++)
		if (*s1++ == 0)
			return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}

char *my_gets(char *buf)
{
	int c;
	char *s;

	for (s = buf; (c = getchar()) != '\n';)
		if (c == EOF)
			if (s == buf) {
				*s = '\0';
				return (NULL);
			} else
				break;
		else
			*s++ = c;
	*s = '\0';
	return (buf);
}

int main(void)
{
	char str1[50], str2[50];
	int rst;
	while(1) {
		printf("\n\nInput String_1 => ");
		my_gets(str1);
		if(str1[0]=='\0') break;
		printf("Input String_2 => ");
		my_gets(str2);
		rst = my_strcmp(str1, str2);
		if(rst == 0) printf("\nString_1 = String_2");
		else if(rst < 0) printf("\nString_1 < String_2");
		else printf("\nString_1 > String_2");
	}

	return 0;
}