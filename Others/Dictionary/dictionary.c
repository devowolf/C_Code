/****
** Dictionary.c - Program to find words from the given dictionary.txt file
** Provided word can be a scrambled or a normal word, as long as all characters are present, word can be found from dictionary.
** Program uses character by character comparision technique to find relevant word from dictionary file.
**
** Written by Sahil Saini for Sir. Matthew Campbell.
** Dated: 24-OCT-2018 - 05:40 PM (GST+5:30), Last-Modified: 28-JAN-2019 - 06:52 AM (GST+5:30)
****/

/* Include required header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Defined macros */
#define LEN 200
#define WORD 50
#define FILE_TO_WRITE "found.txt"
#undef DEBUG

/****
** Function prototyping, to avoid any implicit declaration errors
****/

int compareStrings( char str[], char str2[] );
void removeFromString( char *str, int index );
char *toLowercase( char str[] );


/****
** Main function defination. Drives the whole program.
** Takes no parameters. Returns 0 on successful termination, returns 1 on error.
****/

int main( void ) {

	/* Declaring required variables */
	char inputWord[WORD], buffer[LEN], currentWord[WORD];
	int wordLength, counter, compareLength, dataFound;

	/* declare two file pointers, one to read the dictionary file & other to write matched words to an external file */
	FILE *ftoWrite, *ftoRead;

	/* Prompt user for input */
	printf( "Enter a word: " );
	fflush( stdout );

	/* Incase fgets() fails, exit. */
	if( fgets( buffer, LEN, stdin ) == NULL ) {
		printf( "Error while reading." );
		exit( EXIT_FAILURE );
	}
	sscanf( buffer, "%s", inputWord );

	/* Assign initial value 0 to all the integer type variables */
	wordLength = counter = compareLength = dataFound = 0;

	/* Check the length of entered word & assign it to wordLength */
	wordLength = strlen( inputWord );

	#ifdef DEBUG
		/* Debug information, useful when debugging program */
		printf( "\n------\nDEBUG: " );
		printf( "Length of entered word: %d", wordLength );
		printf( "\n------\n" );
	#endif

	/* Open Dictionary file for reading (in read mode) */
	ftoRead = fopen( "dictionary.txt", "r" );

	/* Open found.txt in write(+read) mode in order to write all the found values */
	/* A file is created if not already present */

	/* CAUTION: if the file is already present, it will be overwritten */

	ftoWrite = fopen( FILE_TO_WRITE, "w+" );

	/* Call exit if file pointers are null */

	if( ftoRead == NULL || ftoWrite == NULL ) {

		printf( "Error while opening file for reading or writing.\n" );
		exit( EXIT_FAILURE );

	}
	/* Use while loop to iterate through every line in the file */
	while( feof( ftoRead ) == 0 && ferror( ftoRead ) == 0 && fgets( buffer, LEN, ftoRead ) != NULL ) {

		/* Use sscanf to copy word from buffer to currentWord */
		sscanf( buffer, "%s", currentWord );

		#ifdef DEBUG
			printf( "\n------\nDEBUG: " );
			printf( "Current copied word using sscanf: %s", currentWord );
			printf( "\n------\n" );
		#endif

		if( wordLength == strlen( currentWord ) && compareStrings( inputWord, currentWord ) == wordLength ) {

			/* Use fprintf to write matched word to the file */

			if( fprintf( ftoWrite, "%s", buffer ) <= 0 ) {

				printf( "Error writing data to the output file." );
				exit( EXIT_FAILURE );

			}

			/* Increase dataFound counter by one */
			dataFound++;

		}

	} /* While Loop Ends */

	/* Add a newline to the end of created output file */

	if( fprintf( ftoWrite, "\n" ) <= 0 ) {

		printf( "Error writing newline character to the end of file." );
		exit( EXIT_FAILURE );

	}

	/* use fseek to set file pointer to the beginning of the output file */
	fseek( ftoWrite, 0, SEEK_SET );

	/* Check if no match is found */
	if ( dataFound <= 0 ) {

			/* Print message & exit program */
			printf("No match found.\n");
			exit( EXIT_FAILURE );

		}

		printf( "\nTotal %d strings matched & are successfully written to output file.\n", dataFound );
		printf( "\n--------------\nFound strings:\n--------------\n" );

		/* print all the words from found.txt file, until EOF is reached or until fgets returns NULL */
		while( ferror( ftoWrite ) == 0 && feof( ftoWrite ) == 0 && fgets(buffer, LEN, ftoWrite) != NULL ) {

		/* Write current word from found.txt file to the stdout (command line in this case) */
		printf("%s", buffer);

		}


	/* Close file pointers */
	fclose( ftoRead );
	fclose( ftoWrite );

	/* Assign NULL to the file pointers */
	ftoRead = ftoWrite = NULL;

	printf( "\n" );

	return 0;
}


/****
** Function to remove a character from string at the given index.
** it takes two arguments, str (string you want to remove character from) & index (integer index where you want to remove value from)
** WARNING: this function modifies the actual string passed to it.
****/

void removeFromString( char *str, int index ) {

	/* Exit if an empty string is passed */
	if( str == NULL ) {

		printf("Passed string can't be empty!");
		exit( EXIT_FAILURE );

	}

	int n = strlen( str );

	/* If an invalid index is passed, print error and exit. */
	if( index >= n || index < 0 ) {

		printf( "\nError. Index cannot be greater than array length or less than 0.\n" );
		exit( EXIT_FAILURE );

	}

	for( int i = index; str[i] != '\0'; i++ ) {

		str[i] = str[i + 1];

	}

	str[n - 1] = '\0';

	return;
}


/****
** Function to compare two strings with each other, character by character, to check if all characters match in both string.
** total number of matched characters is returned by this function.
** Takes two arguments, where str is the string from user & str2 is the word from the dictionary.
** usage example: int compare = compareStrings("hasil", "sahil"); - where hasil & sahil can be replaced with variable names.
****/

int compareStrings( char str[], char str2[] ) {
	/* Declare required variables */
	int counter = 0, strLength, str2Length;

	if( str == NULL || str2 == NULL ) {
		printf( "Passed string argument(s) can't be empty.\n" );
		exit( EXIT_FAILURE );
	}

	strLength = strlen( str );
	str2Length = strlen( str );

	/* Convert both strings to lowercase, to avoid any comparision errors */
	toLowercase( str );
	toLowercase( str2 );

	/* Two 'for' loops to iterate through every character & compare
	* if found word's length matches length of str, then its a match */
	for (int i = 0; i < strLength; i++) {

		for ( int j = 0; str2[j] != '\0'; j++ ) {

			if( str2[j] == str[i] ) {

				/* Increase counter by one, then remove character from the str, using its index */
				counter++;
				removeFromString( str2, j );

				/* Break out of current loop, to continue with other characters from user entered string */
				break;

			}

		}
	} /* for loop ends */


	return counter;
}

/****
** Function to convert strings (char array) to lowercase.
** Any numbers of special symbols passed are skipped
** Usage Example: char name[] = toLowercase("SAHIL"); // Where "SAHIL" can be replaced with a string (char array).
****/

char *toLowercase( char str[] ) {

	/* Check if the passed string is empty */
	if( str == NULL ) {
		printf( "Passed arguments can't be empty.\n" );
		exit( EXIT_FAILURE );
	}

	/* Loop through each element of the uppercase letters & convert them to lowercase by adding 32 to each letter */
	for( int i = 0; str[i] != '\0'; i++ ) {

		if( str[i] >= 'A' && str[i] <= 'Z' ) {
			str[i] = str[i] + 32;
		}

	}

	return str;
}

/* EOF dictionary.c */
