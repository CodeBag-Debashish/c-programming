#include <stdio.h>
int A() {
	printf("Hello A\n");
	return 1;
}
int B() {
	printf("Hello B\n");
	return 2;
}
int C() {
	printf("Hello C\n");
	return 3;
}
int D() {
	printf("Hello D\n");
	return 4;
}
/*void func ( void (*a)(),void (*b)(),void (*c)() ) {
	(*a)();
	(*b)();
	(*c)();
}*/
int main() {
	printf("%d %d %d %d \n",A(),B(),C(),D());
	return 0;
}