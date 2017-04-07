#include <stdio.h>
void func(int *a[]) {
	**(a+1) = 3;
}
int main() {
	int a[2][2] ={{1,2},{3,4}};
	func((int **)a);
	printf("%d\n",**(a+1));
}
