#include <stdio.h>

#ifndef TEST2
extern int asm_func_call(void);
int main(void)
{
	int rst;

	printf("Arm Assembly Function Call Test!!\n");
	rst = asm_func_call();
	printf("Return Val : %d\n", rst);

	return 0;
}
#else
extern int asm_func_call(int);
int main(void)
{
	int rst;
	printf("Arm Assembly Function Call Test!!\n");
	rst = asm_func_call('7');
	printf("Return Val : %c(0x%x)\n", rst, rst);
	rst = asm_func_call('5');
	printf("Return Val : %c(0x%x)\n", rst, rst);
	rst = asm_func_call('B');
	printf("Return Val : %c(0x%x)\n", rst, rst);
	return 0;
}
#endif
