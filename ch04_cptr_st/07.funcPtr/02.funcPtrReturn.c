#include <stdio.h>

typedef int (*IFP)(int, int);

int add(int x, int y)
{
    return x+y;
}
int sub(int x, int y)
{
    return x-y;
}

//...............
IFP fp_op(int type)
{
    if(type == 1) return add;
    else return sub;
}

int main(void)
{
    int n1=10, n2=5;
    int sel;
    IFP fp;

    printf("Select(1:add, 2:sub) => ");
    scanf("%d", &sel);

    fp = fp_op(sel);
    printf("rst => %d\n", fp(n1, n2));

    return 0;
}
