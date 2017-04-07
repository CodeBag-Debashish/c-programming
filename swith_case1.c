#include <stdio.h>
int main() {
	int i;
	for(i=1;i<=4;i++) {
		switch(i) {
			case 1:
				printf("CASE 1 printed\n");
			case 2:
				printf("CASE 2 printed\n");
			default:
				printf("Default printed\n");
			case 3:
				printf("CASE 3 printed\n");
			case 4:
				printf("CASE 4 printed\n");
		}
	}
}