#include <stdio.h>

char *my_gets(char *buf)
{
	int c;
	char *s;

	for (s = buf; (c = _______) != '\n';) {
		if (c == EOF) {
			if (s == buf) {
				*s = '\0';
				return (NULL);
			} else
				break;
		} else
			_________
	}
	_________
	return (buf);
}

int main(void)
{
	char name[50];
	
	while(1) {
		printf("\nInput Name => ");
		my_gets(name);
		if(name[0]=='\0') break;
		printf("\nName : %s\n", name);
	}
	
	return 0;
}