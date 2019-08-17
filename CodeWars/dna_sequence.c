/* Note:
    Allocate memory yourself!
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *dna_strand(const char *dna)
{
  char *data;
  data = malloc(strlen(dna) * sizeof(char) + 1);
  strcpy(data, dna);

  /* Iterate through every character in the char array & swap the values */
  for( int i = 0; i < strlen(dna); i++) {

    /* Check for conditions for swapping the value with each other */
    if(data [i] == 'A') {
      data[i] = 'T';
    } else if( data[i] == 'T') {
      data[i] = 'A';
    } else if( data[i] == 'C' ) {
      data[i] = 'G';
    } else if( data[i] == 'G' ) {
      data[i] = 'C';
    }

  }

  return data;
}

int main( void ) {
  //char *dna = dna_strand("ATTGC");
  printf("DNA Sequence for ATTGC is: %s\n", dna_strand("ATTGC"));

  //dna = dna_strand("GTAT");
  printf("DNA sequence returned for GTAT is: %s\n", dna_strand("GTAT"));

  return 0;
}
