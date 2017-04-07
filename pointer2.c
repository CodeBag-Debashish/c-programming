#include <stdio.h>
int main() {
	int i,n;
	int a = 123456789;

	void *v = &a;
	
	unsigned char *c = (unsigned char*)v;
	
	for(i=0;i< sizeof a;i++) {
		printf("%u  ",*(c+i));
	}

	char *cc = (char*)v;
	printf("\n %d", *(cc+1));

	char *ccc = (char*)v;
	printf("\n %u \n", *(ccc+1));


    double *d = (double *)v;

    


}