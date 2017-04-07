#include <stdio.h>

//gate question

int main() {
	
	char *b = "Hello";
	int i;
	for(i=0;i<5;i++) {
		printf("%c\n",*(b+i));
	}
	*(b+2) = 'k';
	//printf("%c\n",*(b+2));
	return 0;
}
