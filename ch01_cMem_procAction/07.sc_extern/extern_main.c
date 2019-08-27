#include <stdio.h>

void printData(void);
void updateData(void);

int gIntData = 10;
int gArrData[3] = {1, 2, 3};
char gStrData[10] = "apple";

int main(void)
{
	printf("\nsizeof(gArrData):%u, sizeof(gStrData):%u\n\n",
		sizeof(gArrData), sizeof(gStrData));
	printData();
	updateData();
	printData();
	
	return 0;
}
