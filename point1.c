#include <stdio.h>
int func(int ,int *,int **);
int main() {
	int a = 20,*p,**q;
	p = &a;
	q = &p;
	//func(a,p,q);
	printf("%d %d %d\n",a,func(a,p,q),a);
	//printf("%d\n",a);
}
int func(int x,int *pz,int **ppz) {
	**ppz += 2;
	return 2;
}

