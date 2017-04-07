#include <stdio.h>
#include <string.h>
int main() {

	char *s[] = {"cricket","tennis","football"};
	
	int i=0;
	
	printf(" String are: \n\n");
	printf("  %s \n", *(s));
	printf("  %s \n", *(s+1));
	printf("  %s \n", *(s+2));
	printf("  \n\n");

	printf("  Starting locations of the string are: \n\n");
	
	printf("  %d\n",*(s));
	printf("  %d\n",*(s+1));
	printf("  %d\n",*(s+2));
	printf("  \n\n");
 
	return 0;
}