#include <bits/stdc++.h>
using namespace std;

#define MOD 8
#define eps 0.0000001

string c;

double expo(double x,int y) {
	double res = 1.0;
	for(int i=1;i<=y;i++) {
		res = res * x;
	}
	return res;
}

double PWLCM(double old_x,double p) {
	// peicewise
	if( old_x < p) return old_x/p;
	else if ( ( (fabs(old_x - p) <= eps) || (old_x > p) ) && old_x < 0.5 ) return (old_x - p)/(0.5 - p);
	else if ( ( (fabs(old_x - 0.5) <= eps) || (old_x > 0.5) ) && old_x < (1-p) ) return (1 - p - old_x)/(0.5 - p);
	else if ( ( (fabs(old_x - (1-p)) <= eps) || (old_x > (1-p) ) ) && ( (fabs(1.0 - p) <= eps) || (old_x < 1) )) return (1 - old_x)/p;
}

double GCM(double old_f,bool a[],double old_x) {

	double res = a[1]*( ( (int)(c[i-1]) )/256.0) + a[2]*fabs(sin(c[i-1])) + a[3]*expo(fabs(sin(c[i-1])),2)
				+ a[4]*expo(fabs(sin(c[i-1])),3) + a[5]*fabs(cos(c[i-1])) + a[6]*(1 - expo(old_x,2)) + a[7]*(1 - expo(old_f,3));

	return res;
}

int main() {

	cin >> c;
	int N = c.length();
	unsigned int s[N+1];
	bool a[8];
	double f_val,old_x;
	double X[6];
	
	old_x = 0.2323;
	f_val = 0.0;

	for(int i=1;i<=6*N;i++) {
		s[i] = c[i-1] % MOD;
		for(int j=1;j<=7;j++) {
			(j<=s[i])?a[j] = 1:a[j] = 0; 
		}
		// take care of 1st iteration
		old_x = PWLCM(old_x,f_val);
		f_val = GCM(f_val,a,old_x);
		
		if(i == N) {
			// one iteration over !
			f_val = fabs(f_val - floor(f_val) - 0.5);
			X[0] = 
		}
	}

}