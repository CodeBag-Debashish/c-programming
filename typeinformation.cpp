#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;
int main() {
	char a[] = "GATE IITR";
	char *b = "GATE IITR";
	std::cout << typeid(a).name() << endl;
	std::cout << typeid(b).name() << endl;
}