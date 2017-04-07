#include <stdio.h>

int main() {
	char a[3] = "abc";
	int i=0;
	printf("\n");
	while(i<20) {
		printf("%c  %d\n",a[i],a[i]);
		i++;
	}

	printf("%d\n",sizeof(&a[0]));
	return 0;
}