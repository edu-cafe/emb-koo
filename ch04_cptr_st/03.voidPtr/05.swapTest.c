#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int swap(______d1, ______d2, int size);

int main()
{
	char name[][20] = {"kim", "lee"};
	int score[] = {10, 20};
	short age1=17, age2=34;
	float height1=100.1F, height2=200.2F;

	printf("before : name ==> %s,%s\n", name[0], name[1]);
	printf("before : age ==> %d,%d\n", age1, age2);
	printf("before : score ==> %d,%d\n", score[0], score[1]);
	printf("before : height ==> %.1f,%.1f\n", height1, height2);
	swap(name[0], name[1], 20);
	swap(&age1, &age2, sizeof(short));
	swap(&score[0], &score[1], sizeof(int));
	swap(&height1, &height2, sizeof(float));
	printf("-------------------------------------\n");
	printf("after : name ==> %s,%s\n", name[0], name[1]);
	printf("after : age ==> %d,%d\n", age1, age2);
	printf("after : score ==> %d,%d\n", score[0], score[1]);
	printf("after : height ==> %.1f,%.1f\n", height1, height2);
	printf("\n\n");
	
	return 0;
}

int swap(_____d1, _____d2, int size)
{
	void * t;

	if((t = malloc(size)) == NULL) return -1;
	memcpy(t, d1, size);
	memcpy(d1, d2, size);
	memcpy(d2, t, size);
	free(t);
	return 0;
}

