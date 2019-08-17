#include <stdio.h>

int get_sum(int a, int b) {
    /* Variable to store the result */
    int result = 0;

    if(a >= b) {
        /* iterate through every number between & add to result */
        for( int i = a; i >= b; i-- ) {
            result += i;
        }
    } else if( a < b ) {
        /* iterate through every number between & subtract from result */
        for( int i = a; i <= b; i++ ) {
            result += i;
        }
    }
    
    /* Return the calculated result */
    return result;
}

int main( void ) {
    printf("sum(1, 5) is: %d", get_sum(50, 0));

    return 0;
}