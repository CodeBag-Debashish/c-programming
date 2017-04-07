#include <stdio.h>
#include <string.h>
// gate question

int main() {
	
	char a[10];
	char *b = "gate2011";
	int length = strlen(b);
	int i;
	
	for(i=0;i<length;i++) {
		a[i] = b[length - i];
	}

	printf("%s",a);
	
	return 0;
}



