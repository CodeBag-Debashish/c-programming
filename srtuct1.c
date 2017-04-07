#include <stdio.h>
int main() {
	struct b {
		static const int  q = 6;
		static const char  word[] = "EXAM";
	};
	//struct a p;
	struct b p;
	printf("%d\n",p.q);
	printf("%s\n",p.word);
}