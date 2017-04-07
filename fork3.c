#include <stdio.h>																	
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int i=0;
int main(void)
{

    if(fork() && fork()) {
        fork();
    }
    if(fork() || fork()) {
        fork();
        fork();
    }

        printf("\nGate 2017\n");



}
