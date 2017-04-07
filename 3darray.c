#include <stdio.h>
char a[10][3][2];
int main() {
  char a[] = "GATE IITR";
  char *b = "GATE IITR";
  printf("\n %d %d",sizeof(a),sizeof(b));
  printf("\n %d %d",sizeof(*a),sizeof(*b));
  printf("%c\n",*a);
}