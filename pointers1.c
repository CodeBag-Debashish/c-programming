#include <stdio.h>
int main() {
	int i,n;
	unsigned int a[] = {123456789,987654321};
	void *v = a;
	unsigned char *c = (unsigned char*)v;
	for(i=0;i<8;i++) {
		printf("%u  ",*(c+i));
	}

	char *cc = (char*)v;
	printf("\n%d\n", *(cc+1));

}
