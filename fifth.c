#include <stdio.h>

int main() {
	int a[] = {10,20,30,40,50,60};
	int *b[] = {a+3,a+4,a+5,a+2,a,a+1};
	int **c = b;
	
	// 1st
	c++;
	printf("%u  %u  %d\n",c-b,*c-a,**c);
	// 2nd
	*c++;
	printf("%u  %u  %d\n",c-b,*c-a,**c);
	// 3rd
	++*++c;
	printf("%u  %u  %d\n",c-b,*c-a,**c);

	int k =6;
	++++k;
	// 4th
	//*(++(++c));
	//*++++c;
	//*++(++c);
	//printf("%u  %u  %d",c-b,*c-a,**c);

	return 0;
}