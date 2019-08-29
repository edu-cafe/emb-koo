#include <stdio.h>

int inc(int d);
int add(int d1, int d2);

typedef int (*FP1)(int);
typedef int (*FP2)(int, int);
typedef void (*FPV)(void);

int add(int x, int y)
{
    return x+y;
}
int inc(int x)
{
    return x+1;
}

int main(void)
{
    FP1 f1 = add;
    printf("%d\n", f1(10));
    //printf("%d\n", f1(10, 20));		//?????

    FP2 f2 = f1;
    printf("%d\n", f2(10, 20));
        
    FPV p = (FPV)add;			//?????
    //..............
	//void *p = (void*)add;		//?????
    printf("%d\n", (______p)(10, 20));
    //printf("%d\n", (__________p)(10, 20));

    return 0;
}
