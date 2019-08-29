#include <stdio.h>

size_t my_strlen(________str)
{
	const char *s;

	for (s = str; *s; ++s)
		;
	return (________);
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
	char str[50];
	
	while(1) {
		printf("\n\nInput String => ");
		my_gets(str);
		if(str[0]=='\0') break;
		printf("\nString Length : %d\n", (int)my_strlen(str));
	}
	
	return 0;
}
