#include <stdio.h>
int main() {
	int i=3;
	int j = ++i+ ++i+ ++i+ ++i;
	printf("i= %d j= %d\n",i,j);
	return 0;
}

//Undefined behavior and sequence points