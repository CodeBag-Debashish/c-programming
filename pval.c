#include <stdio.h>
#define n 5
int main() {
	int p=0;
	int i=0,j=0;
	for(i=1;i<(2*n);i++) {
		for(j=1;j<=n;j++) {
			if(j<i) p=p+1;
		}
	}
	printf("%d\n",p);
}