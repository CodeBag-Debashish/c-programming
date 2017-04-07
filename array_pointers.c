#include <stdio.h>

int main() {
	int a[2][3];

	printf("a = %u and a+1 = %u\n",a,a + 1); // pointer increment
	printf("sizeof(*a) = %d\n",sizeof(*a));

	int b[3];

	printf("&b = %u and &b+1 = %u\n",&b,&b + 1); // pointer increment
	printf("sizeof( *(&b) ) = %d\n", sizeof(*(&b)) );

	printf("%d\n", sizeof b);
}