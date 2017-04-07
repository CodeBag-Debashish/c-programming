#include <stdio.h>
#define MOD 1000000007
int m = 0;
int cnt=0;
int power(int x, unsigned int y) {
	printf("%d th invocation\n",++cnt);
	int ID = cnt;
	int temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0) {
		m++;
		printf("ID =%d , two temp = %d multiplication\n",ID,temp);
		return (temp*temp)%MOD;
	}
	else {
		m = m+2;
		printf("ID =%d , one x = %d and two temp = %d multiplication\n",ID,x,temp);
		return (x*temp*temp)%MOD;
	}
}
int main() {
	power(2,24);
	printf("%d\n",m);
}