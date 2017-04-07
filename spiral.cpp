#include <bits/stdc++.h>
using namespace std;
#define ROWS 10
#define COLS 13
#define MOD 50
int main() {
	srand(time(NULL));
	int a[ROWS][COLS];
	for(int i=0;i<ROWS;i++) {
		for(int j=0;j<COLS;j++) {
			a[i][j] = rand() % MOD;
		}
	} 
	for(int i=0;i<ROWS;i++) {
		for(int j=0;j<COLS;j++) {
			cout << setw(3)<<a[i][j] <<" ";
		}
		cout << endl<<endl;
	}
	int T = ROWS*COLS; 
	int cnt = 0;
	int rs = 0,re = ROWS-1,cs = 0,ce = COLS-1;
	while(cnt < T ) {
		for(int r = rs++,c = cs;c<=ce;c++) if(cnt++ < T)cout<<a[r][c]<<" ";
		for(int c = ce--,r = rs;r<=re;r++) if(cnt++ < T)cout<<a[r][c]<<" ";
		for(int r = re--,c = ce;c>=cs;c--) if(cnt++ < T)cout<<a[r][c]<<" ";
		for(int c = cs++,r = re;r>=rs;r--) if(cnt++ < T)cout<<a[r][c]<<" ";
	}
	return 0;
}

/*r = row
c = col
rs = row_start_index
re = row_end_index
cs = col_start_index
ce = col_end_index*/