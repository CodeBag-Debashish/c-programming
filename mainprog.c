#include <stdio.h>
int main() {
	extern x,y,z;
	x = 10;y = 20;
	z = x+y;
	printf("%d\n",z);
}