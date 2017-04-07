#include <stdio.h>

int main(){
    int a[2][2] = {1, 2, 3, 4};
    printf("a: = %p, &a: = %p, *a: = %p \n\n", a, &a, *a);
    printf("a[0]: = %p, &a[0]: = %p \n\n", a[0], &a[0]);
    printf("&a[0][0]: = %p \n\n", &a[0][0]);
    return 0;
}