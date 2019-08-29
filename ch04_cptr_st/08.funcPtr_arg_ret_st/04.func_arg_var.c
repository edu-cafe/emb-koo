#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

#if 0
int sum(int nargs, ...)
{
	_____ argp;
	int i;
	int total;
	______(argp, nargs);
	for(i=0, total=0; i<nargs; i++) {
		total += _____(argp, ____);
	}
	______(argp);
	return total;
}
	
int main(void)
{
	printf("sum : %d\n", sum(5, 1,2,3,4,5));
	printf("sum : %d\n", sum(10, 1,2,3,4,5,6,7,8,9,10));
	printf("sum : %d\n", sum(2, 102, 301));
	
	return 0;
}
#endif


#if 1
void my_printf(char *fmt, ...)
{
	_____ argp;
	int i;
	
	___________
	for(i=0; fmt[i]; i++) {
		switch(fmt[i]) {
			case 's':
				printf("%s", va_arg(argp, char*));
				break;
			case 'd' :
				printf("%d", va_arg(argp, int));
				break;
			case 'c' :
				printf("%c", va_arg(argp, int));
				break;
			default :
				assert(0);
		}
	}
	__________
	printf("\n");
}
int main(void)
{
	char name[] = "kim";
	int age=17;
	char gender = 'F';
	
	my_printf("sssdsc", "name:", name, ", age:", age, ", gender:", gender);
	
	return 0;
}
#endif