#include <stdio.h>

int find_outlier(const int *values, size_t count);

int main( void ) {

    int sample[] = {2,6,8,200,700,1,84,10,4};
    printf("sizeof(sample) is: %d\n", ( sizeof(sample) / sizeof(int)) );
    int parity = find_outlier( sample, ( sizeof(sample) / sizeof(int)) );

    printf("Parity number is: %d\n", parity);
    return 0;
}

int find_outlier(const int *values, size_t count) {

    /* Declare required variables */
    int oddCount, evenCount, lastOdd, lastEven;

    /* Assign initial value 0 to all the declared variables */
    oddCount = evenCount = lastEven = lastOdd = 0;

    /*
    * o(n) case algorithm, looks at each number in the array & checks if its even or odd,
    * increases respective counter everytime
    */
    for( int i = 0; i < count; i++ ) {

        
        if( values[i] % 2 == 0 ) {

            /* If current value is even */
            evenCount++; /* increment even counter by 1 */

            lastEven = values[i]; /* assign to lastEven (to keep track of the number) */

        } else {

            /* If current value is not even */
            oddCount++; /* increase odd counter by 1 */

            lastOdd = values[i]; /* assign to lastOdd (to keep track of the number) */
        }
    }

    /* Check if odd values or even value is greater than 1, return number accordingly */
    if( oddCount == 1 ) {
        return lastOdd;
    } else if( evenCount == 1 ) {
        return lastEven;
    }

    return 0;
}