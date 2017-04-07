#include <stdio.h>
#define print(x) printf("%d",x)

int main() {
	float fl_var = -112;
	
	int xx = *(int*)(&fl_var);
	
	for(int i=(sizeof(float)<<3)-1;i>=0;i--) {
		if(i == 30 || i == 22) printf(" | ");
		(xx & (1<<i)) ? print(1):print(0); 
	}
	
	printf("\n");

	double d_var = -112.0;
	
	long long yy = *(long long *)(&d_var); 
	
	for(int i=(sizeof(double)<<3)-1;i>=0;i--) {
		if(i == 62 || i == 51) printf(" | ");
		(yy & (1<<i)) ? print(1):print(0);
	}
	
	printf("\n");

}