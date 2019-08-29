#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _INFO {
	int age;
	char name[20];
	float height;
} INFO;

void printData(INFO *data, int nelem)
{
	int i;
	
	for(i=0; i<nelem; i++) {
		printf("%s, %d, %.1f\n", 
			data[i].name, data[i].age, data[i].height);
	}
}

... fcmp_sort(......)
{
	.....
}


void dataSearch(INFO *data, int nelem)
{
	char sname[80];
	INFO *tdata;
	
	while(1) {
		printf("\nInput Search Name(quit:'end') => ");
		fgets(sname, sizeof(sname), stdin);
		sname[strlen(sname)-1] = '\0';
		if(!strcmp(sname, "end")) break;
		.....  bsearch(...........);
		printf("\nSearch Result....\n");
		if(tdata == NULL) {
			printf("%s => no data!!\n", sname);
		} else {
			printf("%s, %d, %.1f\n", 
				tdata->name, tdata->age, tdata->height);
		}
	
	}
}

int main(void)
{
	INFO data[] = {
		{17, "park", 170.1F},
		{20, "lee", 168.2F},
		{18, "kim", 172.3F},
		{22, "yang", 180.1F},
		{19, "kang", 177.3F}};
	
	printf("Before Sort....\n");
	printData(data, sizeof(data)/sizeof(INFO));
	qsort(...........);
	printf("---------------------------\n");
	printf("After Sort....\n");
	printData(data, sizeof(data)/sizeof(INFO));
	
	dataSearch(data, sizeof(data)/sizeof(INFO));
	
	return 0;
}
