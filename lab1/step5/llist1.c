// LLIST1.C [140911]
// Code provided for ELEC278 Lab 1 Step 5

#include "llist1.h"

void insertFront(int v, LList1 *l)
{
    if (l != NULL)	{
        /* create new link */
        Link* link = initLink(v);

        /* has at least one element */
        if (!isEmpty(l))
        {
            link->next = l->head;
            l->head = link;
        } else {
            l->head = link;
        }
    }
}


Link* extract(int v, LList1 *list)
// Extract Element from list with value v and return it
// return NULL if no link exists with value v
{
    Link	*link1=NULL,
			*link2=NULL,
			*resLink=NULL;

	// check if list is NULL
    if (list != NULL)	{
        if (list->head != NULL) /* something in list */
        {
			/* head contains value v */
            if (list->head->value == v)
            {
                resLink = list->head;
                list->head = list->head->next;
                list->size--;
            }
			/* head doesn't contain value v. Must traverse list to find it */
            else
            {
                link1 = list->head ;
                link2 = link1->next ;
				/* Move link1 and link2 until you find link with value v or reach end of list */

				while (link2 != NULL) {
				    if (link2->value == v) {
				        resLink = link2;
				        link1->next = link2->next;
				        list->size--;
                        break;
				    }
				    link1 = link2;
				    link2 = link2->next;
				}
            }
        }
    }
    return( resLink ) ;
}//extract()


int isEmpty (LList1 *l)
{
	if (l == NULL)	return 1;	// no list provided
    if (l->head == NULL)	return 1;	// list has no elements
    return 0;					// exiting list with elements - not empty
}//isEmpty()


Link* initLink (int v)
// Create a new linked list element and initialize the value field; set
// the next pointer to NULL
{
    Link* link = malloc(sizeof(Link));
    link->value = v;
    link->next = NULL;
    return link;
}//initLink()


LList1* initList ()
// Create a new linked list descriptor. The descriptor contains a description
// of the list - number of elements and a pointer to the first element.
{
    LList1 *list = malloc(sizeof(LList1));
    list->size = 0;
    list->head = NULL;
    return list;
}


void printList (LList1 *l)
{
    if (l != NULL) {
        if (!isEmpty(l)) {
            Link *link = l->head;
            while (link != NULL) {
                printf("%d-->",link->value);
                link = link->next;
            	}//endwhile
            printf("NULL\n");
		} else	{
			//list descriptor exists, but seems to have no elements
			printf (" <EMPTY>\n");
        	}//endif
    	}//endif valid list descriptor
}//printlist()
