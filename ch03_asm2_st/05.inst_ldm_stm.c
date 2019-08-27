#include <stdio.h>

void print_data(int *arr, int cnt)
{
	int i;
	for(i=0; i<cnt; i++) {
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

extern int asm_stm(int *);
extern int asm_ldm_stm(int *, int *);
int main(void)
{
	int data1[10]={0,};
	int data2[10]={0,};
	int rst;
	printf("Arm Assembly Instruction ldm/stm Test!!\n");
	print_data(data1, 10);
	rst = asm_stm(data1);
	printf("---------------------------\n");
	print_data(data1, 10);
	printf("===========================\n");
	print_data(data2, 10);
	rst = asm_ldm_stm(data1, data2);
	printf("---------------------------\n");
	print_data(data2, 10);
	return 0;
}

