//prog2.c
#include <stdio.h>
int f(int *x,int *y,int *z) {
  *x = *x + 1;
  *y = *y + 1;
  *z = *z + 1;
  return 0;
}
int main() {
  int a=0,b=0,c=0;
  printf("%d %d %d\n",a,f(&a,&b,&c),b);;
  return 0;
}
// gcc output : 1 0 0
// clang-3.5 :  0 0 1