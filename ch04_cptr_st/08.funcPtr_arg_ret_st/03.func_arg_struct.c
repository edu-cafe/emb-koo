#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct _info {
	int id;
	short data[200];
} INFO;

void inputData1(INFO data, int cnt)
{
	int i;
	
	printf("inputData1==>addr_data:%p, addr_data[99]:%p, addr_data[199]:%p\n", 
			&(data.data[0]), &(data.data[99]), &(data.data[199]));
	assert(cnt<=200);
	data.id = 1111;
	for(i=0; i<cnt; i++) {
		data.data[i] = 100+i;
	}	
}

void inputData2(INFO *data, int cnt)
{
	int i;
	
	printf("inputData2==>addr_data:%p, addr_data[99]:%p, addr_data[199]:%p\n", 
			&(data->data[0]), &(data->data[99]), &(data->data[199]));
	assert(cnt<=200);
	data->id = 2222;
	for(i=0; i<cnt; i++) {
		data->data[i] = 200+i;
	}	
}

void printData(INFO data, int cnt)
{
	int i;
	
	printf("printData==>addr_data:%p, addr_data[99]:%p, addr_data[199]:%p\n", 
			&(data.data[0]), &(data.data[99]), &(data.data[199]));
	assert(cnt<=200);
	for(i=1; i<=cnt; i++) {
		if(i%10) printf("%d ", data.data[i-1]);
		else printf("%d\n", data.data[i-1]);
	}	
}

int main(void)
{
	int cnt=20;
	INFO data;
	printf("main==>addr_data:%p, addr_data[99]:%p, addr_data[199]:%p\n", 
			&(data.data[0]), &(data.data[99]), &(data.data[199]));
	memset(&data, 0x00, sizeof(data));
	printData(data, cnt);
	printf("----------------------------------------------\n");
	inputData1(data, cnt);
	printData(data, cnt);
	printf("----------------------------------------------\n");
	inputData2(&data, cnt);
	printData(data, cnt);
	return 0;
}