#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key;
	____cb_func_____
} CB_TBL;

CB_TBL cbTbl[10];
int cb_id1 = 1;
int cb_id2 = 4;
int cb_id3 = 8;

int cbRegister(int id, ____func_____)
{
	cbTbl[id].key = id;
	cbTbl[id].cb_func = func;
	return id;
}

int cb_func1(unsigned long arg)
{
	printf("cb_func1() called!!\n");
	printf("cb_func1 key : %ld\n", arg);
	return 0;
}

int cb_func2(unsigned long arg)
{
	printf("cb_func2() called!!\n");
	printf("cb_func2 key : %ld\n", arg);
	return 0;
}

int cb_func3(unsigned long arg)
{
	printf("cb_func3() called!!\n");
	printf("cb_func3 key : %ld\n", arg);
	return 0;
}

int main(void)
{
	int rst;
	rst = cbRegister(cb_id1, cb_func1);
	if(rst < 0) {
		printf("cbRegister error1!!\n");
		exit(1);
	}
	rst = cbRegister(cb_id2, cb_func2);
	if(rst < 0) {
		printf("cbRegister error2!!\n");
		exit(1);
	}
	rst = cbRegister(cb_id3, cb_func3);
	if(rst < 0) {
		printf("cbRegister error3!!\n");
		exit(1);
	}
	
	while(1)
	{
		int key;
		printf("\n\nInput Key => ");
		scanf("%d", &key);
		if(key==-1) break;
		if(cbTbl[key].key == 0) {
			printf("No Registered Callback!!\n");
			continue;
		} 
		else ________
	}
	
	return 0;	
}

