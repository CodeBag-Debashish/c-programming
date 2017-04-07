#include <stdio.h>
#include <stdbool.h>
bool f();

int main() {
	if(f()) {
		printf("OK\n");
	}
}

bool f() {
	return false;
}

