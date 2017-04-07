#include <bits/stdc++.h>
using namespace std;
const int mx = 21,sum = 401;
const int N=22,M = 22,K = 405;
double dp[M+1][K+1][N+1];
vector<int>dice = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
double prob(int faces,int x) {
	double res = 1.0;
	for(int i=0;i<x;i++) res = res * (1.0/(double)(faces));
	return res;
}

void sum_table() {
	
	for(int i=1;i<=K;i++) 
		for(auto n:dice) 
			dp[0][i][n-1] = 0.0;
	
	for(auto n:dice) dp[0][0][n-1] = 1.0;
	
	for(auto n:dice) {
		for(int used = 1 ; used <= mx ; used++) {
				for(int num = 0;num <= (n-1);num++) {
					for(int s=0;s+num <= sum;s++) {
						dp[used][num+s][n-1] += dp[used-1][s][n-1] / (double)(used);
					}
				}
		}
	}

}


int main() {
	int T,H,S;
	sum_table();
	cin >> T;
	for(int qq=1;qq<=T;qq++) {
		
		double ans = 0.0;
		cin >> H >> S;
		string str[S];
		for(int i=0;i<S;i++) cin >> str[i];
				
				bool ok = false;
				for(int s=0;s<S && !ok;s++) {
					//cout << "case = "<<qq<<"hello " <<"spell = "<< s << endl; 
					int i=0;int x=0,y=0,z=0;int sign = 1;
					int len = str[s].length();
					if(isdigit(str[s][i]) && isdigit(str[s][i+1])) {
						x = 10*(str[s][i] - '0') + (str[s][i+1] - '0');
						i = 3; 
					}else {
						x = (str[s][i] - '0');
						i = 2;
					}
					y = str[s][i] - '0';
					if( (i+1) != len ) {
						i++;
						if(isdigit(str[s][i])) {
							y = y*10 + (str[s][i] - '0');
							if((i+1) != len) {
								if(str[s][i+1] == '-') sign = -1;
								for(int j=i+2;j<len;j++) {
									z = 10*z + (str[s][j] - '0');
								}
							}else { z = 0; }
						}else {
							if(str[s][i] == '-') sign = -1;
							for(int j=i+1;j<len;j++) {
								z = 10*z + (str[s][j] - '0');
							}
						}
					}else {
						z = 0;
					}
					//cout << "mew11111" << endl;
					z = sign * z;
					printf("x = %d y = %d z = %d\n",x,y,z);
					double c_tot = 0.0;
					int ssum = H - z - x  - 1;
					double p=0.0,fp=0.0;
					printf(" H-z =   %d ssum = %d",H-z,ssum);

					if((H-z) > x*y) {
						printf("   hi1\n");
						fp = 0.0;
					}else if(((H-z) <= x*y) && ((H-z) > 0)) {
						printf("   hi2222\n");
						//	printf("\n-%d- H = %d ssum = %d ", qq,H,ssum);
					//		cout << "mew3333" << endl;
							for(int s = 0;s <= ssum ;s++) c_tot += dp[x][s][y-1];
						//	cout << "HI" <<"case = "<<qq <<"  spell = "<<s<<" x = "<<x<<" y = "<<y<<" z = "<<z<< endl;	
							//p = prob(y,x);
							printf(" tot = %.7f", c_tot);
							fp = 1.0 - c_tot;
					}else if ((H-z) < 0) {
						printf("  Hi333\n");
						fp = 1.0;
						ok = true;
					}
					//printf("fp  %.7f\n",fp);
					ans = max(ans,fp);			
					printf("fp  = %.7f , ans = %.7f\n\n\n",fp,ans);
				}

		printf("Case #%d: ", qq);
		printf("%.6f\n", ans);
	}
	return 0;
}




