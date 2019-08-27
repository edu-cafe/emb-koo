#include <stdio.h>

void print_data(int data)
{
	printf("data -> %d\n", data);
}

#ifdef TEST1
extern int asm_sum_1_10(void);
int main(void)
{
	int rst;
	printf("Arm Assembly sum_1_10() Test!!\n");
	rst = asm_sum_1_10();
	printf("\nasm_sum_1_10() -> : %d\n", rst);
	return 0;
}
#endif


#ifdef TEST2
extern int asm_sum_1_x(int);
int main(void)
{
	int rst;
	int x;
	printf("Arm Assembly sum_1_x() Test!!\n");
	x = 10;
	rst = asm_sum_1_x(x);
	printf("\nasm_sum_1_x(1,%d) -> %d\n", x, rst);

	x = 5;
	rst = asm_sum_1_x(5);
	printf("\nasm_sum_1_x(1,%d) -> %d\n", x, rst);
	return 0;
}
#endif


#ifdef TEST3
extern int asm_sum_x_y(int, int);
int main(void)
{
	int rst;
	int x, y;
	printf("Arm Assembly sum_x_y() Test!!\n");
	x=1; y=10;
	rst = asm_sum_x_y(1,10);
	printf("\nasm_sum_x_y(%d,%d) -> %d\n", x, y, rst);

	x=2; y=7;
	rst = asm_sum_x_y(2,7);
	printf("\nasm_sum_x_y(%d,%d) -> %d\n", x, y, rst);
	return 0;
}
#endif

