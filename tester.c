#include <stdio.h>
#define N 4 		// how many bits we need to check

void display_bits(unsigned int data) {
	for(int i = (sizeof(int) << 3) -1;i>=0;i--) {
		(data&(1<<i))?printf("1"):printf("0");
	}
}
int main() {
	
	printf("1st Example : \n");
	unsigned int mask = 0;
	mask |= (1<<0) | (1<<1) | (1<<2) |(1<<3); // or mask |= 15;

	unsigned int data1 = 205;
	printf("Here is the data bits : \n");
	display_bits(data1);
	printf("\n");

	unsigned int result1 = data1 & mask;

	printf("Here is the result bits after masking\n");
	display_bits(result1);
	printf("\n");

	printf("-----------------------------------------\n");
	printf("2nd Example : \n");
	// Another example
	mask = 0;

	int pos[N] = {2,3,6,7}; // positions where we need to check the data bits
							// other positions we dont care 	
	// prepare the mask
	for(int i = 0; i<N ; i++) {
		mask = mask | (1<<pos[i]);	
	}
	// mask is ready
	

	// this is our data
	unsigned int data2 = 345;
	printf("Here is the data bits : \n");
	display_bits(data2);
	printf("\n");

	printf("Here is the result bits after masking\n");
	// result is the new word they are taking about
	unsigned int result2 = data2 & mask;
	display_bits(result2);
	printf("\n");

	return 0;
}