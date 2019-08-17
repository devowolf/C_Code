/*
* Checks if an ip is valid
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int is_valid_ip(const char * addr);
int main(void) {

    /* Trying with valid cases */
    printf("is_valid_ip(\"123.45.67.89\"): %d\n", is_valid_ip("123.45.67.89"));
    printf("is_valid_ip(\"1.2.3.4\"): %d\n", is_valid_ip("1.2.3.4"));
    printf("is_valid_ip(\"123.45.67.89\"):%d\n", is_valid_ip("123.45.67.89"));

    /* Let's try with some invalid cases */
    printf("is_valid_ip(\"123.045.067.089\"): %d\n", is_valid_ip("123.045.067.089"));
    printf("is_valid_ip(\"123.456.78.90\"): %d\n", is_valid_ip("123.456.78.90"));
    printf("is_valid_ip(\"1.2.3.4.5\"): %d\n", is_valid_ip("1.2.3.4.5"));
    printf("is_valid_ip(\"\"): %d\n", is_valid_ip(""));
    printf("is_valid_ip(\"12.34.56.-1\"): %d\n", is_valid_ip("12.34.56.-1"));
    printf("is_valid_ip(\"1.2.3.4\"): %d\n", is_valid_ip("1.2.3.4 "));
    return 0;
}

int is_valid_ip(const char * addr) {

    /* If passed address argument is empty */
    if(addr == NULL) {
        return 0;
    }

    /* Declare & initialize required variables */
    int array[15] = {0}, dotCount = 0, indexCount = 0, zCheck = 0;


    /* Use a for loop to iterate through every character in the passed address */
    for( int i = 0; i < strlen(addr); i++) {

        /* Additional check. */
        if( indexCount > 0 ) {
            /* Check if previously added value to the number array is greater than 255 or less than 0 */
            if( array[indexCount] > 255 || array[indexCount] < 0 ) {
                return 0;
            }
        }

        /* Check if the first character of current value (number) is zero */
        if(zCheck == 0 && addr[i] == '0') {
            return 0;
        }


        /* If any character in the string is a alphabet, return 0 */
        if( isalpha(addr[i]) ) {
            return 0;
        }

        /* If character passes test case above, check if the current chactacter is a dot */
        if( addr[i] == '.' ) {

            /* Increment required counter's values */
            dotCount++;
            indexCount++;
            zCheck = 0;

            /* Continue with the loop */
            continue;
        }
        /* If anything other than numbers or dot, return 9 */
        if( isalnum(addr[i]) == 0 && addr[i] != '.') {
            return 0;
        }

        /* Multiply array at indexCount by 10 & add the value from addr to array */
        array[indexCount] *= 10;
        array[indexCount] += (addr[i] - '0');
        zCheck++;

    }

    /* If number of dots in ip are greater or less than 3, return 0 (invalid) */
    if( dotCount < 3 || dotCount > 3 ) {
        return 0;
    }

    /* Return 1 if code passes all the tests & reaches upto this point */
    return 1;

}