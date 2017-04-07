#include<stdio.h>

int x; 

int *call();
int main(){
int *ptr;
ptr=call();
 
 
printf("%d",*ptr);
return 0;
}
int * call(){
 
 x=25;
++x;
 
return &x;
}