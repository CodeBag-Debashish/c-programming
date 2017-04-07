#include <stdio.h>
int main(){
	char ch=1;
	while(ch<256) {
		printf("%d\n",ch);
		ch++;
	}
	printf("Loop end");
	return 0;
}
// For gcc, the default is signed
// -funsigned-char