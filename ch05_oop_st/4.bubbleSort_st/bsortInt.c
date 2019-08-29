#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bsort(int *base, int nelem);
int swap(void *d1, void *d2, int size);

int main()
{
	int score[] = {78, 23, 86, 33, 98, 42};
	int i;

	printf("Before Sort....\n");
	for(i=0; i<sizeof(score)/sizeof(int); i++)
		printf("%d ", score[i]);
	printf("\n\n");

	bsort(score, sizeof(score)/sizeof(int));

	printf("After Sort....\n");
	for(i=0; i<(sizeof(score)/sizeof(int)); i++)
		printf("%d ", score[i]);
	printf("\n\n");

	return 0;
}

void bsort(int *base, int nelem)
{
	int step, cmp, change;

	for(step=1; step<=nelem-1; step++) {
      change = 0;
      for(cmp = 1; cmp<=nelem-step; cmp++) {
		if(base[cmp-1] > base[cmp]) {
			swap(&base[cmp-1], &base[cmp], sizeof(int));
            change = 1;
		}
	  }
	  if(change == 0) break;
    }
}
