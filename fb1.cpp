#include <bits/stdc++.h>
using namespace std;
#define painted " black"
#define not_painted " white"
#define one 0
#define two 1
#define thr 2
#define fur 3
#define px  4
#define nx  5
#define py  6
#define ny  7
#define org 8
bool flag[9];
const double PI = 3.141592653;
const double epsilon = 0.000001;
void set_flag(int x,int y) {
	x -= 50; y -= 50;
	if(x == 0 && y == 0 ) flag[org] = true;
	else if(x == 0 && y > 0 ) flag[py] = true;
	else if(x == 0 && y < 0 ) flag[ny] = true;
	else if(x > 0 && y == 0 ) flag[px] = true;
	else if(x < 0 && y == 0) flag[nx] = true;
	else if(x > 0 && y > 0) flag[one] = true;
	else if(x > 0 && y < 0) flag[two] = true;
	else if(x < 0 && y > 0) flag[fur] = true;
	else if(x < 0 && y < 0) flag[thr] = true;
}
int main() {
	bool rad_ok,ang_ok,near,inside;
	int x,y,P,T;
	double ang;
	cin >> T;
	for(int qq = 1; qq<=T;qq++) {
		memset(flag,false,sizeof flag);
		cin >> P >> x >> y;
		set_flag(x,y);
		if(P == 0) {
			cout <<"Case #"<<qq<<":"<<not_painted<<endl;
		}else if(P > 0 && flag[org]) {
			//cout << "sss" << endl;
			cout <<"Case #"<<qq<<":"<<painted<<endl;
		}else {
			ang = atan2(fabs(y-50),fabs(x-50.0));
			int dist =  (x-50)*(x-50) + (y-50)*(y-50);
			double r = hypot((double)(x-50),(double)(y-50));
			(dist <= 2500) ? rad_ok = true: rad_ok = false;
			if(flag[one]) ang = 0.5*PI - ang;
			else if(flag[two]) ang = 0.5*PI + ang;
			else if(flag[thr]) ang = 1.5*PI - ang;
			else if(flag[fur]) ang = 1.5*PI + ang; 
			else if(flag[px]) ang = 0.5*PI;
			else if(flag[nx]) ang = 1.5*PI;
			else if(flag[py])  ang = 0;
			else if(flag[ny]) ang = PI;
			double percent = P / (double)(100.0); 
			//cout << percent << endl;
			double g_ang = percent * 2 * PI;
			((fabs(g_ang - ang) * r) <= epsilon) ? near = true:near = false;
			(ang < g_ang) ? inside = true:inside = false;
			if( inside || near) ang_ok = true; 
			else ang_ok = false;
			if(ang_ok && rad_ok) 
				cout <<"Case #"<<qq<<":"<<painted<<endl;
			else cout <<"Case #"<<qq<<":"<<not_painted<<endl;
		}
	}
	return 0;
}