#include <stdio.h>
#include <string.h>

void inputData(short *data, int cnt)
{
	int i;
	printf("inputData-->addr_data:%p(%p)\n", &data, data);  //?????
	for(i=0; i<cnt; i++) {
		data[i] = 100+i;
	}	
}

void printData(short *data, int cnt)
{
	int i;
	printf("printData-->addr_data:%p(%p)\n", &data, data);  //?????
	for(i=1; i<=cnt; i++) {
		if(i%10) printf("%d ", data[i-1]);
		else printf("%d\n", data[i-1]);
	}	
}

void updateData(short *data, int cnt)
{
	int i;
	printf("updateData-->addr_data:%p(%p)\n", &data, data);  //?????
	for(i=1; i<=cnt; i++) {
		data[i-1] = 500+i;
	}	
}

int main(void)
{
	int cnt=20;
	short data[cnt];
	printf("main-->addr_data:%p(%p)\n", &data, data);  //?????
	memset(data, 0, sizeof(data));
	printData(data, cnt);
	inputData(data, cnt);
	printData(data, cnt);
	printf("----------------------------------------------\n");
	updateData(data, cnt);
	printData(data, cnt);
	return 0;
}