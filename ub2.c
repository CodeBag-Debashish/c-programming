#include <stdio.h>
#define CUBE(x) (x*x*x)


int main() {
	int a,b=3;
	a = CUBE(b++);
	printf("%d,%d\n",a,b);
	return 0;
}
