#include <stdlib.h>
#include <string.h>

int swap(void *d1, void *d2, int size)
{
	void * t;

	if((t = malloc(size)) == NULL) return -1;
	memcpy(t, d1, size);
	memcpy(d1, d2, size);
	memcpy(d2, t, size);
	free(t);
	return 0;
}
