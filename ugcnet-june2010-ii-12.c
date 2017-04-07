#include <stdio.h>
int main() {
	char *p = "aym";
	char c = ++*p;
	printf("%c\n",c );
	return 0;
}