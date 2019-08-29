#include <stdio.h>
#include <stdlib.h>

void printData(________, int size)
{
	int i, j;

	for(i=0; i<size; i++) {
		for(j=0; j<4; j++) {
			printf("%3d ", data[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	_____________
	int i, j, cnt=5;
	
	score = malloc(cnt * sizeof(short[4]));
	for(i=0; i<cnt; i++) {
		for(j=0; j<4; j++) {
			score[i][j] = i*10 + j;
		}
	}
	
	printData(score, cnt);
	free(score);
	return 0;
}
