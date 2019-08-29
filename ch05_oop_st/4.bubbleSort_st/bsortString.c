#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	NAME_SIZE	20

void bsort(char *base, int nelem, int size);
int swap(void *d1, void *d2, int size);

int main()
{
	char name[][NAME_SIZE] = {"yang", "kim", "lee ss", "kang ag", "park jh"};
	int i;

	printf("Before Sort....\n");
	for(i=0; i<sizeof(name)/NAME_SIZE; i++)
		printf("%s\n", name[i]);
	printf("\n\n");

	bsort(&name[0][0], sizeof(name)/NAME_SIZE, NAME_SIZE);

	printf("After Sort....\n");
	for(i=0; i<sizeof(name)/NAME_SIZE; i++)
		printf("%s\n", name[i]);
	printf("\n\n");

	return 0;
}

void bsort(char *base, int nelem, int size)
{
	int step, cmp, change;

	for(step=1; step<=nelem-1; step++) {
      change = 0;
      for(cmp = 1; cmp<=nelem-step; cmp++) {
		if(strcmp(base+(cmp-1)*size, base+cmp*size)>0) {
			swap(base+(cmp-1)*size, base+cmp*size, size);
            change = 1;
		}
	  }
	  if(change == 0) break;
    }
}
