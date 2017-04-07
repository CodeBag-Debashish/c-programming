#include <bits/stdc++.h>
#define SIZE 10
using namespace std;
int partition(int a[],int p,int q) {
	int x = a[p];
	int i = p;
	for(int j=i+1;j<=q;j++) {
		if(a[j] <= x) {
			swap(a[j],a[++i]);
		}
	}
	swap(a[i],a[p]);
	return i;
}
void quick_sort(int a[],int p,int q) {
	if(p < q) {
		int m = partition(a,p,q);
		quick_sort(a,p,m-1);
		quick_sort(a,m+1,q);
	}
}
int main() {
	int a[SIZE] = {1,9,2,8,3,7,4,10,5,6};
	quick_sort(a,0,SIZE-1);
	for(auto e:a) cout << e <<" ";
	cout << endl;

}
