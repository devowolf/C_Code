#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/* Function prototype */
char* alphabet_to_numeric( const char* str );


/* Main function, execution begins here */
int main( void ) {
    char *numbers = alphabet_to_numeric("Guri");

    /* Print the char array with numbers */
    printf("numeic array is: ");
    for( int i = 0; numbers[i] != '\0'; i++ ) {
        if( numbers[i] > 26 ) {
            printf("%c", numbers[i]);
            continue;
        }
        printf("%d ", numbers[i]);
    }
    printf("\n"); /* Add a newline to the end of output string */

    return 0;
}

char* alphabet_to_numeric( const char* str ) {

    /* Declare a string literal & allocate sufficient memory for it */
    char *numericStr = malloc( strlen( str ) * sizeof( char ) + 1 );
    strcpy(numericStr, str); /* Copy whole string from str to numericStr for modification */

    /* Iterate through every character & modify the string literal */
    for( int i = 0; i < strlen(numericStr); i++ ) {
        if( isalpha( numericStr[i] ) ) {

            /* If character is uppercase */
            if( isupper( numericStr[i] ) ) {

                numericStr[i] = (numericStr[i] - 'A' + 1);

            } else if( islower(numericStr[i] )) {

                numericStr[i] = (numericStr[i] - 'a' + 1);

            }

        } else {
            /* If its not a alphabetical character, leave it as is & continue with loop */
            continue;
        }


    }
    
    return numericStr;
}