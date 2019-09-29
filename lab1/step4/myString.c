// MYSTRING.C
// Code provided for ELEC278 Lab 1 Step 4
// See the instructions in the lab sheet for details about
// the code you are to add to the functions shown below.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myString.h"


char *copyString(char *s)
// Parameter s points to an existing string.
// Function fetches memory sufficient to hold a copy of the existing string,
// and copies the string to the memory fetched.  Return value is the pointer
// to the memory containing the copy of the string.
{
    char *temp = s;

    int length = 0;
    while (*temp != '\0') {
        length++;
        temp++;
    }

	char *copy = (char *) malloc(sizeof(char) * (length + 1));
    if (copy == NULL)
        return NULL;

    strcpy(copy, s);
    return copy;
}//copyString()


void printString(char *s)
// Read the specification carefully.  This printString() function does more
// than just print a string, it treats some of the characters in the string
// a bit differently than you might expect.
{
	while (*s != '\0') {
	    if (*s == ' ') {
            putchar('\n');
	    } else {
            putchar(*s);
        }
	    s++;
	}
}//printString()
