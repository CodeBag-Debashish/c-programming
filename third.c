#include <stdio.h>

// gate question

int main() {
	
	char *c = "hello";
	c++;
	printf("%s\n",c);
	printf("%u\n%u\n",c,&c);


	return 0;
}
