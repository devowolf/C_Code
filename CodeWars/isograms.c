/* 
** Program to check if a passed string is valid isogram
** 
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isograms( char* str );

int main( void ) {
    int check = isograms("Sahil"); // Valid, no repeated characters.

    if( !check ) {
        printf("Invalid isogram.");
    } else {
        printf("Valid isogram.");
    }
    return 0;
}

bool isograms( char* str ) {
    /* Required counter variable */
    int count = 0;

    /* if string is null or empty, its considered as isogram */
    if(str == NULL) {
        return true;
    }
  
    /* Iterate through every character in the char array */
    for( int i = 0; str[i] != '\0'; i++ ) {
    
        /* for every char in the array, try matching it with others */
        for( int j = i; j <= strlen(str); j++ ) {
            if( tolower( str[i] ) == tolower( str[j] ) ) {
                count++;
            }
        
            if( count > 1 ) {
                return false;
            } 
        }
        count = 0; /* Set counter to 0 */
    }
  
    /* Return true if all tests are passed, its an isogram */
    return true;
}