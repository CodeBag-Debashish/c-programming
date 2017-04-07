#include <stdio.h>
int main() {
	char a[10];
	a[0] = 'a';
	f(a);
}
f(char a[]) {
	printf("%s\n",a[0]);
}