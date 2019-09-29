// MAIN.C [140911]
// Code provided for ELEC278 Lab 1 Step 5

#include <stdio.h>
#include "llist1.h"

int main()
{
    LList1 *list = initList(); // malloc new list and set head to NULL
	/* insert 4 elements into the list */
    insertFront(5, list);
    insertFront(3, list);
    insertFront(2, list);
    insertFront(0, list);
	printf("Original List: ");
    printList(list);
	
	printf("Extract link with value 3 from list\n");
    Link * link = extract(3, list);
	printf("Value of extracted link: %d\n",link->value);
	printf("Updated List: "); 
	printList(list);
	printf("\n");
	
	printf("Extract link with value 1 from list\n");
    link = extract(1, list);
	if (link == NULL)
		printf("No Link with value 1 in the list\n");
	else
		printf("Something is wrong.  Check your code\n");
	printf("Updated List: ");	
    printList(list);
	printf("\n");

	
	printf("Extracting all other elements from list\n");
	link = extract(5, list);
	printf("Value of extracted link: %d\n",link->value);
	link = extract(2, list);
	printf("Value of extracted link: %d\n",link->value);
	link = extract(0, list);
	printf("Value of extracted link: %d\n",link->value);

	printf("Updated List (should be empty): ");
	printList(list);
    return 0;
}//main()
