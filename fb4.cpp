#include <bits/stdc++.h>
using namespace std;
const int n = 21,mx = 21,sum = 401;
const int M = 22,K = 405;
int dp[M+1][K+1];
double prob(int faces,int x) {
	double res = 1.0;
	for(int i=0;i<x;i++) res = res * (1.0/(double)(faces));
	return res;
}
void sum_table() {
	for(int i=1;i<=K;i++) dp[0][i] = 0;
	dp[0][0] = 1;
	for(int used = 1 ; used <= mx ; used++) {
		for(int num = 0;num <= n;num++) {
			for(int s=0;s+num <= sum;s++) {
				dp[used][num+s] += dp[used-1][s];
			}
		}
	}
	for(int i=0;i<15;i++) {
		for(int j=0;j<15;j++) {
			cout << setw(7) << dp[i][j] <<" ";
		}
		cout << endl;
	}	
}


int main() {
	int T,H,S;
	sum_table();
	cin >> T;
	for(int qq=1;qq<=T;qq++) {
		printf("Case #%d: ", qq);
		double ans = 0.0;
		cin >> H >> S;
		string str[S];
		for(int i=0;i<S;i++) cin >> str[i];
				
				for(int s=0;s<S;s++) {
					int x=0,y=0,z=0;
					int sign = 1;
					int len = str[s].length();
					int i=0;
					// x
					if(isdigit(str[s][i]) && isdigit(str[s][i+1])) {
						x = 10*(str[s][i] - '0') + (str[s][i+1] - '0');
						i = 3; 
					}else {
						x = (str[s][i] - '0');
						i = 2;
					}
					// y
					y = str[s][i] - '0';
					if( (i+1) != len ) {
						// still more stuff
						i++;
						if(isdigit(str[s][i])) {
							y = y*10 + (str[s][i] - '0');
							if((i+1) != len) {
								// + or - detected	
								if(str[s][i+1] == '-') sign = -1;
								for(int j=i+2;j<len;j++) {
									z = 10*z + (str[s][j] - '0');
								}
							}else {
								z = 0;
							}
						}else {
							// + or - detected
							if(str[s][i] == '-') sign = -1;
							for(int j=i+1;j<len;j++) {
								z = 10*z + (str[s][j] - '0');
							}
						}
					}else {
						z = 0;
					}
					z = sign * z;
					int ssum = H - z - x -1 ;
					int mmx = y - 1;
					int c_tot = 0;
					cout <<endl<<"ssum = "<< ssum <<" mmx = " <<mmx<<" ";
					for(int s = 0;s <= ssum ;s++) c_tot += dp[mmx][s];
					double p = prob(y,x);
					cout <<endl<<"p = "<< p <<" c_tot = " <<c_tot <<" ";
					double fp = 1 - p*c_tot;
					ans = max(ans,fp);			
					printf(" res =   %.6f \n", ans);
				}
		

		printf("%.6f\n", ans);
	}
	return 0;
}




