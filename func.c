#include <stdio.h>
int main() {
	m();
	void m() {
		printf("Hello\n");
	}

}
If no function prototype is declared before using it, here the compiler guesses or implicitly creates one depending on the arguments passed with return type as 'int'. If later we declare with same function name and if it does not match with the guessed one (by the compiler) then, compilers throws error. Warning type conflict because of the implicit 'int'.