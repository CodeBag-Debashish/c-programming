#include <stdio.h>

int main() {
	int i;
	int a[4] = {1,2,3,4};
	int (*p)[4];
	p = &a;
	for(i=0;i<4;i++) {
		printf("%d\n",*(*p+i));
	}
}