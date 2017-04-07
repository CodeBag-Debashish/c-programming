#include<stdio.h>
int main() {
    int i, j, k;
    i = 5;
    j = ++i;
    i = j--;
    k = (i+j)++;
    printf("%d",k);
}