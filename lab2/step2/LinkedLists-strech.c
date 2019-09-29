// LinkedLists.c
// Code provided for ELEC278 Lab 2
// This version uses a linked list to store the data in the set

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// Node (or element) in list holds value and pointer to next element
typedef struct Node {
	int			value;
	struct Node	*next;
} Node;


Node *createNode (int x, Node *nxt)
// Create new Node and initialize its value and next pointer
{
	Node *pNode = (Node *)malloc (sizeof(Node));
	if (pNode != NULL)	{
		pNode->value = x;
		pNode->next = nxt;
		}
	return pNode;
}


// LinkedList structure has pointer to first element, and count of
// elements in list.
typedef struct LinkedList {
	Node	*head;
	Node    *tail;
	int		size;
} LinkedList;


int isEmpty(LinkedList *l)
// Check if LinkedList is empty. It is empty if head pointer is NULL
{
	return (l->head == NULL);
}


void init(LinkedList *l)
// Initialize LinkedList structure
{
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}


void addFront(LinkedList* l,int x)
// Add new Node to front of linked list. Create and initialize new Node
// structure with value and current head-of-list pointer.  Make head-of-list
// point to new node
{
    Node* newNode = createNode (x, l->head);
	printf ("Adding %d to front of list\n", x);
    l->head = newNode;
    l->size++;

    if ((l->tail == NULL) && (l->head->next != NULL)) {
        l->tail = l->head;
    }
}


void addEnd(LinkedList* l,int x)
// Add new Node to end of linked list
{
    Node* newNode = createNode (x, NULL);
	printf ("Adding %d to end of list\n", x);
	// start by increasing size of linked list
    l->size++;
	// Now comes the fun part - have to find current last Node, so it
	// can be made to point to the new node
	if (isEmpty (l))	{
		// LinkedList currently empty - new node becomes first in list
		l->head = newNode;
	} else	{
	    l->tail = l->tail->next;
	    l->tail->next =newNode;

		// Not empty - have to find last Node in current list and make
		// it point to new node.
//		Node* ptr = l->head;
//		// Traverse list until node found that doesn't point to a next one
//		while(ptr->next!=NULL)	{
//			ptr = ptr->next;
//			}
//		// ptr points to a Node with no next Node; make this Node point to
//		// new one
//		ptr->next = newNode;
		}
	// Our work is done.
}


void removeFront(LinkedList* l)
// Remove first Node from list
{
	printf ("Remove item at front of list\n");
	if (!isEmpty (l))	{
		// List is not empty, so there is a first Node to delete.
		Node *ptr = l->head;		// point to first node
		// Note that list will be one shorter
		l->size--;

		if (l->head == l->tail) {
		    l->tail = NULL;
		}

		// head of list is now element after first
		l->head = l->head->next;
		// discard node we no longer need
		free(ptr);
    }
}


void removeEnd(LinkedList* l)
// Remove last Node from list
{
	printf ("Remove item at end of list\n");
	// First determine if any work to do
	if (!isEmpty (l))	{
		// Special case - if there is only one Node
		if (l->size==1)	{
			removeFront(l);
		} else	{
		    l->tail->next = NULL;


//			// More than 1. Note how this code requires that a Node
//			// be found that points to a last Node (one with a NULL
//			// next pointer, and that doesn't work for the list with
//			// only 1 Node.  Fun exercise for the student - think about
//			// how to redesign data and code so that all cases can
//			// be handled with one piece of code.
//			Node* ptr = l->head;
//
//			// As long as the Node we're pointing to isn't the end of
//			// the list, move to next Node
//			while(ptr->next->next)	{
//				ptr = ptr->next;
//				}
//			Node* delPtr = ptr->next;
//			ptr->next = NULL;
//			free(delPtr);
			l->size--;
			}
		}
}


void destroy(LinkedList* l)
// Delete entire linked list - basically by repeatedly deleting first Node
{
	while(!isEmpty(l))	{
		removeFront(l);
		}
}


void removeValue(LinkedList* l, int x)
{
    int found = 0;

	printf ("Find first %d in list and remove it\n", x);

	if (isEmpty(l)) {
        return;
	}

	if (l->head->value == x) {
	    removeFront(l);
        return;
	}

	Node *temp = l->head;
	Node *prev = NULL;
	while(temp->next != NULL) {
	    if (temp->value == x) {
            prev->next = temp->next;
            free(temp);
            found = 1;
            break;
	    }
	    prev = temp;
	    temp = temp->next;
	    l->size--;
	}


	if ((found == 0) && (temp->value == x)) {
	    removeEnd(l);
	}
}


void print(LinkedList *l)
{
    Node* ptr = l->head;
	printf("(");
    if(!ptr)	{
        printf("<EMPTY>");
    } else	{
    	while(ptr->next){
        	printf("%d -> ",ptr->value);
        	ptr = ptr->next;
			}
    	printf("%d",ptr->value);
		}
	printf(") [%d]\n",l->size);
}


void update(LinkedList* l)
// Find smallest value in linked list and subtract that value from each value
{
	printf ("Subtract smallest value from all values in list\n");
    if (isEmpty(l)) {
        return;
    }

	Node *ptr = l->head;
	int smallest = INT_MAX;

	while(ptr != NULL) {
	    if (ptr->value < smallest) {
	        smallest = ptr->value;
	    }

	    if (ptr->next == NULL) {
            break;
	    }
	    ptr = ptr->next;
	}

	ptr = l->head;
    while(ptr != NULL) {
        ptr->value -= smallest;

        if (ptr->next == NULL) {
            break;
        }
        ptr = ptr->next;
    }

}


int main ()
{
    LinkedList ll;
	printf ("ELEC278 Lab 2 Part 2 - LinkedLists\n");
    init(&ll);
    
    addFront(&ll,5);
    addFront(&ll,2);
    addEnd(&ll,4);
    addEnd(&ll,3);
    
    print(&ll);
    
    update(&ll);
    print(&ll);
    
    removeValue(&ll,0);
        print(&ll);

    removeValue(&ll,2);
    //removeFront(&ll);
    //removeEnd(&ll);
    print(&ll);

    //removeFront(&ll);
    removeValue(&ll,3);
    print(&ll);

    removeValue(&ll,1);
    print(&ll);

    return 0;
}
