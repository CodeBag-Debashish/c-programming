#include <stdio.h>
int main() {
	char *p[] = {"abc","abcdef"};
	printf("p1 = %u p2 = %u\n",p,p+1);
	return 0;

}