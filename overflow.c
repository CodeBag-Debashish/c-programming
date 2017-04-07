/*#include <stdio.h>
int main() {
	int a;
	int i=0;
	char ch;
	while(i<5) {
		scanf(" %c",&ch);
		printf("char = %c\n", ch);
		i++;
	}
	return 0;
}*/
	#include <stdio.h>
 
int main(void)
{
    char c;
    /* FIX: Leave a space before %c */
     
    printf("Input No.1\n");
    scanf(" %c", &c);
    printf("c = %c\n", c);
     
    printf("Input No.2\n");
    scanf(" %c", &c);
    printf("c = %c\n", c);
     
    printf("Input No.3\n");
    scanf(" %c", &c);
    printf("c = %c\n", c);
    return 0;
}