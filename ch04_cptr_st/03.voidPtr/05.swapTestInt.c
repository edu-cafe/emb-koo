#include <stdio.h>

int swapInt(int *d1, int *d2);

int main()
{
	int score[] = {10, 20};

	printf("before : score ==> %d,%d\n", score[0], score[1]);
	swapInt(&score[0], &score[1]);
	printf("-------------------------------------\n");
	printf("after  : score ==> %d,%d\n", score[0], score[1]);
	return 0;
}

int swapInt(int *d1, int *d2)
{
	int t;
	
	t = *d1;
	*d1 = *d2;
	*d2 = t;
	return 0;
}
