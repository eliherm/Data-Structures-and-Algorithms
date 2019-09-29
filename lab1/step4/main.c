// MAIN.C
// Code provided for ELEC278 Lab 1 Step 4

#include <stdlib.h>
#include "myString.h"

int main(void)
{
	char *s;
	
	s = (char *) copyString("This is a string.");
	printString(s);
	free(s);
	return 0;
}//main()
