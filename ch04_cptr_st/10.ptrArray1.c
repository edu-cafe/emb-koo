#include <stdio.h>
#include <stdlib.h>

char *errs[] = {
	"No such file or directory",
	"No read permisson",
	"No write permission",
	"No execute permission"
	};

int error_chk()
{
	return rand()%4;
}

void p_error(int errno)
{
	printf("Error=>%s\n", errs[errno]);
}

int main(void)
{
	int errno;

	srand(getpid());
	errno = error_chk();
	p_error(errno);
	errno = error_chk();
	p_error(errno);

	return 0;
}
