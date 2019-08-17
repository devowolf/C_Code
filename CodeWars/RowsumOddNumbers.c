#include <stdio.h>
#include <stdint.h>
uint64_t rowSumOddNumbers(uint32_t n);
uint64_t rowSumOddNumbers_o(uint32_t n);
int main( void ) {

    printf( "Result of the value 5 is: %d\n", rowSumOddNumbers_o( 5 ) );
    printf( "Result of the value 13 is: %d\n", rowSumOddNumbers_o( 13 ) );
    printf( "Result of the value 15 is: %d\n", rowSumOddNumbers_o( 15 ) );
    printf( "Result of the value 17 is: %d\n", rowSumOddNumbers_o( 17 ) );
    printf( "Result of the value 18 is: %d\n", rowSumOddNumbers_o( 18 ) );
    printf( "Result of the value 9 is: %d\n", rowSumOddNumbers_o( 9 ) );
    printf( "Result of the value 80 is: %d\n", rowSumOddNumbers_o( 80 ) );
    
    return 0;
}

/* Optimized version of the same function below, oh shit, i figured it out! ;) */
uint64_t rowSumOddNumbers_o(uint32_t n)
{
    /* Return the calculated result */
    return (n*n*n);
}

/* Old function, not optimized enough! */
uint64_t rowSumOddNumbers(uint32_t n) 
{
    /* Declare required variables, exactly 64bit wide */
    uint64_t result, l_no;

    /* Assign initial value 1 to the variable storing last calculated number */
    l_no = 1;

    /**
     *  Use iterations to calculate the number of elements in a row & use second loop to
     * calculate the result of the addition of elements in row
    **/
    for( int i = 1; i <= n; i++) {
        result = 0; /* Set result to 0 everytime its outside the inner loop */
        int j = 1;
        while( j <= i ) {
            result += l_no;
            l_no += 2;
            j++;
        }
    }

    /* Return the calculated result */
    return result;
}