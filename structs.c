#include <stdio.h>

int main() {
    struct emp
    {
        char name[20];
        float sal;
    };
    struct emp e[2];
    int i;
    for(i=0; i<=1; i++)
        scanf("%s %f", e[i].name, &e[i].sal);
    return 0;
}