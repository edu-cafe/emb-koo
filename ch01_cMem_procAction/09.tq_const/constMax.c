#include <stdio.h>
//int max(const int *p) {
int max(int *p) {
	int i, tmp=-10000;
	for(i=0; i<10; i++) {
		if(p[i] > tmp) {
			tmp = p[i];
		}
	}
	return tmp;
}
int main(void)
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int m_val=0;
	m_val = max(a);
	printf("max of a_array : %d\n", m_val);
	return 0;
}
