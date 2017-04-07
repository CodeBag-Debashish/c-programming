#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

	pid_t child;
	

	child = fork();
	printf("value of child = %d\n", child);
	int c = 5;
	if(child == 0) {
		c += 5;
		printf("child = %d and %d\n",child,c);
	}
	else {
		child = fork();
		printf("value of child = %d\n", child);
		c+=10;
		printf("child = %d and %d\n",child,c);
		if(child) { 
			c+=5;
			printf("child = %d and %d\n",child,c);
		}
	}

}