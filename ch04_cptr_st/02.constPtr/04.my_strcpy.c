#include <stdio.h>

char *my_strcpy(_____to, _______from)
{
	char *save = to;

	for (; (______ = *from) != '\0'; ++from, ++to);
	return(save);
}

int main(void)
{
	char str1[50];
	
	my_strcpy(str1, "Main Start...");
	printf("str1:%s\n", str1);
	my_strcpy(str1, "Hello..Hi~~");
	printf("str1:%s\n", str1);
	my_strcpy(str1, "Main End...");
	printf("str1:%s\n", str1);
	
	return 0;
}