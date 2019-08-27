#include <stdio.h>
#include <string.h>
#ifdef TEST2
extern int gIntData;
extern int gArrData[5];
extern char gStrData[80];
#else
extern int gIntData;
extern int gArrData[];
extern char gStrData[];
#endif
void updateData(void) {
	int i;
	gIntData++;
#ifdef TEST2
	for(i=0; i<5; i++) {
		gArrData[i]++;
		strcpy(gStrData, "Good Morning?");
	}
#else
	for(i=0; i<3; i++) gArrData[i]++;
	//for(i=0; i<5; i++) gArrData[i]++;
#endif
}
