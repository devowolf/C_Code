#include <stdio.h>
#include <stdbool.h>
#include <string.h>
char* c = "cbcbddecbcccebbecddaebaeccacdabbbdebeddaacebbdadddbccbcededeaeadaeabaadcacebcbbbccdbaccbcaaecacebcadaddacedcabaebaabdcccdcbceabdaddabbcacaeadeeeaabdeaceadbbaceacdadbebbbabaaaeaccacdcbacabcebacbccecdadbdddbaddcaccebcbbbaceaeadebaeeaaebdabdeadddcecacddccddedcdaccbcdcdeabaacdabaaeedcbdcacbecbbbebadeedcebbedaedebcbecabbbbeacaeaaaebdeabaaaabdbeceeeacbbdabdcddadabdecabecccaacaadeaacdbececaecaedddcacdcbbdbadbaedcceddbeabeedaabbccdbbeebceebbbedadedbabebacccbaadddeecbbdcebabeaeabdbccceabcbbebbcccbabbaacabdddebbcaabbaadddeeadeebeccbdecbacbededaaebceabdbcaabbbdebeccdacccdcdbcddebebeecbbeaddacebbdcdbecbcbaeeadceebbeacdcabeecacbcbeedabbcabcbaeaeaebcadadebbbeeecaacabeadccecbcbddcddcdcbbadceeeeecbaddaabaceebacddbddaeececddbeeaabdbcdcedddedaeddcbaebcdaaebedeccedeacddcdebddbebdececaeebcecdbedbdddddadcdbcacaaccebaaabebdaccdacddcdbaceeebbabdecbeecbbdbbdebddbebeadbbccdeceecebddaeeabadcdeaeddddcbebeeadbccaabaacaaacbcdaacaaddeeebaedbaadcabcceeaeedecdbedbedbbcebdceadacabcacdaccddbdeddccbadaececbbcbecadecbebbeeceaacdaaddbdccabaccbbeebcbcdceabdaedaedeebecabdbdccbccebaceebbabcbecaddabcecdcddbccabbbbddcbeaadbedcededbdabcacacebeaecbeaceaeedbeaadbdbeacdceeadcbbbdcbabccbbbcdbebaacecbaadeabbdeebbaeacbbbcabbecbbbcecceadbebeabccdbcddabcacdbbbdceebddeeeaadadceee";
#undef DEBUG

int search_substring( const char* fullText, const char* searchText, bool allowOverlap );

int main( void ) {

    /* Test function with few test cases */
    printf("search_substring(\"sahilsah\", \"sah\", true): %d\n", search_substring("sahilsah", "sah", true));
    printf("search_substring(\"abcabcabc\", \"abc\", false): %d\n", search_substring("abcabcabc", "abc", false));
    printf("search_substring(\"abcabcabc\", \"abc\", true): %d\n", search_substring("abcabcabc", "abc", true));
    printf("search_substring(\"ababa_ababa_ababa\", \"aba\", false): %d\n", search_substring("ababa_ababa_ababa", "aba", false));
    printf("search_substring(\"ababa_ababa_ababa\", \"aba\", true): %d\n", search_substring("ababa_ababa_ababa", "aba", true));
    printf("search_substring(c, \"cedd\", false): %d\n", search_substring(c, "cedd", false) );
    printf("%d\n", search_substring("abecadeabeedabcdeecdecdadceacadebebbdadbceeeadeceeadbddeaaeeaeddebceeaadacccabbacbadbeadeecbbceaebeaebdbdadbdcbbdbbccbadddeecbbdecdddbbedcaeedaeedbe", "cca", false));

    return 0;
}

int search_substring( const char* fullText, const char* searchText, bool allowOverlap ) {
    int timesCount, subCheck, subIndex;

    /* Initialize both variables with 0 */
    timesCount = subCheck = subIndex = 0;

    #ifdef DEBUG
        printf("\nstrlen(fullText): %d\n", strlen(fullText));
    #endif
    /* If strings are null (empty), return 0 */
    if( searchText == NULL || fullText == NULL ) {
        return 0;
    }

    /* */
    for( int i = 0; i < strlen(fullText); i++ ) {

        /*
        * If first character of sub-string is matched in string, iterate over next characters in sting
        * & check if full string is matched
        */
        if( fullText[i] == searchText[0] ) {
            subIndex = i; /* set subIndex to i, so we can iterate over characters from current location, without touching the i */

            /* Iterate over every character from current one until end of search string is encountered */
            for( int j = 0; j < strlen(searchText); j++ ) {
                
                if( fullText[subIndex] == searchText[j] ) {
                    subCheck++;
                } else if( fullText[subIndex] != searchText[j] ) {
                    break; /* Break if any character of string is not matched */
                }
                subIndex++; /* Increment subIndex counter, to use it with string */
            }

            /* If subCheck counter is equal to length of search text, its a match */
            if( subCheck == strlen(searchText) ) {
                timesCount++; /* Increment total times counter */

                if( allowOverlap == false ) {
                    i = subIndex - 1;
                }
            }
            subCheck = 0; /* set substring check counter back to 0 */

        } else {
            continue; /* continue with the loop if char wasn't matched (preventing infinite loop) */
        }

    }

    return timesCount;
}