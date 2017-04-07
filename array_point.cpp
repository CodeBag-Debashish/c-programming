#include <bits/stdc++.h>
#include <typeinfo>

using namespace std;

int main() {
	int a[4] = {1,2,3,4};
	int (*p)[4];
	cout << typeid(a[1]).name() << endl;
	cout << typeid(a).name() << endl;
	cout << typeid(&a).name() << endl;
	cout << typeid(p).name() << endl;

}