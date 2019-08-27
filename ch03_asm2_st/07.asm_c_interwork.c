#include <stdio.h>

void print_data(int data)
{
	printf("data -> %d\n", data);
}

int c_sum_1_x(int x)
{
	int i, sum;
	for(i=1, sum=0; i<=x; i++) {
		sum += i;
	}
	return sum;
}

extern int asm_sum_1_10(void);
extern int asm_sum_1_x(int x);
extern int asm_sum(int x, int y);
extern int asm_sum_xy(int x, int y);
extern int asm_sum_x_y(int x, int y);
int main(void)
{
	int rst;

	printf("Arm Assembly sum_1_10() Test!!\n");
	rst = asm_sum_1_10();
	printf("asm_sum_1_10() -> : %d\n", rst);

	printf("\nArm Assembly sum_1_x() Test!!\n");
	rst = asm_sum_1_x(10);
	printf("asm_sum_1_x(10) -> : %d\n", rst);

	printf("\nArm Assembly sum() Test!!\n");
	rst = asm_sum(1,10);
	printf("asm_sum(1,10) -> : %d\n", rst);
	printf("\nArm Assembly sum_x_y() Test!!\n");
	rst = asm_sum_x_y(1,10);
	printf("asm_sum_x_y(1,10) -> : %d\n", rst);
	printf("\nArm Assembly sum_xy() Test!!\n");
	rst = asm_sum_xy(1,10);
	printf("asm_sum_xy(1,10) -> : %d\n", rst);

	return 0;
}
