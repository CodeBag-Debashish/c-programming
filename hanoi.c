/*
 * C program for Tower of Hanoi using Recursion
 */
#include <stdio.h>
 
void towers(int, char, char, char);
 int move = 0;
int main() {
    int num;
    printf("Enter the number of disks : ");
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(num, 'X', 'Y', 'Z');
    return 0;
}
void towers(int num, char frompeg, char topeg, char auxpeg) {
    if (num == 1) {
        printf("\n %d Move disk 1 from peg %c to peg %c", ++move,frompeg, topeg);
        return;
    }
    towers(num - 1, frompeg, auxpeg, topeg);
    printf("\n %d Move disk %d from peg %c to peg %c", ++move,num, frompeg, topeg);
    towers(num - 1, auxpeg, topeg, frompeg);
}