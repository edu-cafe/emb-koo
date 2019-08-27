#include <stdio.h>

#ifdef TEST1
extern int gIntData = 10;
extern int gArrData[3] = {1, 2, 3};
extern char gStrData[10] = "apple";
#else
extern int gIntData;
extern int gArrData[];
extern char gStrData[];
#endif

void printData(void)
{
	printf("-------- global data value ---------\n");
	printf("gIntData : %d\n", gIntData);
	printf("gArrData : %d,%d,%d\n", gArrData[0], gArrData[1], gArrData[2]);
	//printf("gArrData : %d,%d,%d,%d\n", gArrData[0], gArrData[1], gArrData[2], gArrData[3]);
	printf("gStrData : %s\n", gStrData);
}
