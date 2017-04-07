#include <iostream>
using namespace std;
int main() {
	int i;
	char a[] = {23,37,48,89};
	void *v = a;

	unsigned char *c = (unsigned char*)v;
	for(i=0;i<4;i++) {
		printf("%d ", *(c+i));
	}
	unsigned int *d = (unsigned int*)v;
	printf("%d\n",*d);

	bool *bl = (bool*)v;
	printf("\n");
	return 0;
}