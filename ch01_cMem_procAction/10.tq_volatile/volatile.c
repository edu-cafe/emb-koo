#include <stdio.h>
#include <time.h>

int main()
{
	unsigned long i1;
	volatile unsigned long i2;
	unsigned long start_tick=0, end_tick=0;
	unsigned long dur1=0, dur2=0;

	start_tick = clock();
	for(i1=1; i1<=0x10000000; i1++) ;
	end_tick = clock();
	dur1 = end_tick - start_tick;

	start_tick = clock();
	for(i2=1; i2<=0x10000000; i2++) ;
	end_tick = clock();
	dur2 = end_tick - start_tick;

	printf("dur1:%lu ticks, dur2:%lu ticks\n", dur1, dur2);

	return 0;
}
