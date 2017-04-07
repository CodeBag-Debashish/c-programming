#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;
int main() {
	int a[] = {1,2,3,4};
	cout <<"    a = " << typeid(a).name() <<"   sizeof a = "<<sizeof(a)<< endl;
	cout <<"    &a = " << typeid(&a).name() <<"   sizeof &a = "<<sizeof(&a)<< endl;
}