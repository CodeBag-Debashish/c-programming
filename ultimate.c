#include <stdio.h>

char *s[] = { "ball", "football" };

int main( void ) {
    int i;

    for( i=0; i<2; i++ ) {
        printf( "%lu\n", (unsigned long)s[i] );
    }
}