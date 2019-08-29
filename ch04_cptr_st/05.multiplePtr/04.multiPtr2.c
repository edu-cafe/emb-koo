#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[20];
	int num;
	short score[3];
} ST;

typedef struct {
	int classId;
	int stCnt;
	ST **stTbl;
} CLS;

ST *stTbl1[3];
ST *stTbl2[5];
ST *stTbl3[4];
CLS *clsTbl[3];

void setStData(_______, int size)
{
	int i;
	static unsigned int cnt=1;
	for(i=0; i<size; i++) {
		stTbl[i] = malloc(sizeof(ST));
		stTbl[i]->num = cnt;
		sprintf(stTbl[i]->name, "kim%d", cnt);
		stTbl[i]->score[0] = cnt;
		stTbl[i]->score[1] = cnt;
		stTbl[i]->score[2] = cnt;
		cnt++;
	}
}

void setClsData(______, ______, int size)
{
	_______ unsigned int num=0;
	clsTbl[num] = malloc(sizeof(CLS));
	clsTbl[num]->classId = num+1;
	clsTbl[num]->stCnt = size;
	clsTbl[num]->stTbl = stTbl;
	num++;
}

void printClsData(_____clsTbl)
{
	int i, j;
	printf("\n======== Class Infomation =========\n");
	for(i=0; i<3; i++) {
		printf("\n-------- Class %d ---------\n", clsTbl[i]->classId);
		for(j=0; j<clsTbl[i]->stCnt; j++) {
			printf("name:%s, num:%d, score:%d,%d,%d\n", 
					clsTbl[i]->stTbl[j]->name,
					clsTbl[i]->stTbl[j]->num,
					clsTbl[i]->stTbl[j]->score[0], 
					clsTbl[i]->stTbl[j]->score[1],
					clsTbl[i]->stTbl[j]->score[2]);
		}
	}
}

int main(void)
{

	setStData(stTbl1, 3);
	setStData(stTbl2, 5);
	setStData(stTbl3, 4);
	
	setClsData(clsTbl, stTbl1, 3);
	setClsData(clsTbl, stTbl2, 5);
	setClsData(clsTbl, stTbl3, 4);
	
	puts("----------------------------------------------");
	printClsData(clsTbl);

	return 0;
}
