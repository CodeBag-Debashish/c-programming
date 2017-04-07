#include <stdio.h>
void f(char a[]) {
	printf("%u\n",a);
	printf("%d\n",sizeof(*a));
}

int main() {
	char a[10] = {'a','b','c','d'};
	printf("%d\n",sizeof(a));
	printf("%u\n",a);
	f(a);
}