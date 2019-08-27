#include <stdio.h>

void print_data(int *arr, int cnt)
{
	int i;
	for(i=0; i<cnt; i++) {
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

extern int asm_str(int *, int);
extern int asm_ldr_str(int *, int *);
int main(void)
{
	int data1[10]={0,};
	int data2[10]={0,};
	int rst;
	printf("Arm Assembly Instruction ldr/str Test!!\n");

	print_data(data1, 10);
	rst = asm_str(data1, 30);
	printf("---------------------------\n");
	print_data(data1, 10);

	printf("===========================\n");
	print_data(data2, 10);
	rst = asm_ldr_str(data1, data2);
	printf("---------------------------\n");
	print_data(data2, 10);

	return 0;
}

