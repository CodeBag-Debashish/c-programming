#include <stdio.h>

int* func() {
	int a = 10; 
	return &a;
}

int main() {
	printf("%d\n", *func());
	return 0;
}