#include <stdio.h>
#include <time.h>

int main()
{
	unsigned long int i1, n1, s1;
	register unsigned long int i2, n2, s2;
	unsigned long start_tick=0, end_tick=0, dur1=0, dur2=0;

	start_tick = clock();
	for(i1=1, s1=0; i1<=0x10000000; i1++) {
		s1 += i1;
	}
	end_tick = clock();
	dur1 = end_tick - start_tick;
	start_tick = clock();
	for(i2=1, s2=0; i2<=0x10000000; i2++) {
		s2 += i2;
	}
	end_tick = clock();
	dur2 = end_tick - start_tick;
	printf("dur1:%lu ticks, dur2:%lu ticks\n", dur1, dur2);
	printf("s1:%lu, s2:%lu\n", s1, s2);

	return 0;
}
