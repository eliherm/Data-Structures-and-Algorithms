// ArrayLists.c
// This code is supplied for use with ELEC278.  It requires that the student
// add some missing pieces.

#include <stdio.h>
#include <stdlib.h>

// An ArrayList implements a "variable length" array.  In reality, there
// is a fixed quantity of memory - M integers (with indices 0..M-1) used
// to hold a quantity of data up to M items.  

typedef struct ArrayList {
	// Structure describes collection of data to describe and contain
	// a set of numbers.  The set is described by end and size, and
	// the actual data is in an array pointed to by a.
	int		size;		// record size to detect if full
    int		end;		// records index of last location used
    int		*a;			// pointer to allocated array memory
} ArrayList;

#define EMPTY	(-1)	// invalid array index used as end when empty

void init (ArrayList *l,int size)
// Initialize an ArrayList to hold an array of specified size.
{
	l->a = malloc(sizeof(int)*size);
	l->size = size;
	l->end = EMPTY;
}//init()


void addFront(ArrayList* l, int x)
// Add value in parameter x to front of list.  If list already full,
// don't do anything
{
    if (l->end == EMPTY) {
        l->a[++l->end] = x;
    } else if (l->size > (l->end+1)) {
        for (int i = l->end; i >= 0; i--) {
            l->a[i+1] = l->a[i];
        }
        l->a[0] = x;
        l->end++;
    }
}//addfront()


void addEnd(ArrayList* l,int x)
// Add value in parameter x to rear of list
{
	// end holds index of current last value in list.
	// Add 1 to list and store value in new end location.
	// Note this works even if list initially empty. Note also
	// that we check if array already full.  (Remember, size is
	// 1 greater than last valid index, so size needs to be greater
	// than what end index will become
	if (l->size > (l->end+1))	{
    	l->end++;
    	l->a[l->end] = x;
		}
}//addEnd()


void removeEnd(ArrayList* l)
// Remove last value from list. In a more elaborate implementation,
// end value may be provided to the calling code. At the very least,
// code should indicate whether it actually did what was asked.
{
	printf ("Remove last value from list\n");
	if(l->end != EMPTY)	{
		// list not empty, so it is possible to remove last value
		l->a[l->end] = 0;	// not really necessary
		l->end--;			// may empty list
		}
}//removeEnd()


void removeFront(ArrayList* l)
// Remove front value from list. Note that you will have to move all values
{
    if (l->end != EMPTY) {
        for (int i = 0; i < l->end; i++) {
            l->a[i] = l->a[i+1];
        }
        l->end--;
    }

}//removeFront()


void print(ArrayList *l)
// Print contents of list
{
	// Print brackets around whole list
	printf ("(");
	// Check first to see if anything to print
	if (l->end == EMPTY)	{
        printf("EMPTY LIST");
	} else	{
		int		i;
		for( i=0; i<=l->end-1; i++)	{
			printf("%d - ",l->a[i]);
			}
		// No trailing dash after last one
		printf("%d",l->a[l->end]);
		}
	//finish with closing bracket and NL
	printf (")\n");
}//print()


int main ()
{
    ArrayList ll;

	printf ("ELEC278 - Lab2 Part1 arrayslist program\n");
    init(&ll,10);
    
    addFront(&ll,5);
    addFront(&ll,2);
    addEnd(&ll,4);
    addEnd(&ll,3);
    
    print(&ll);
    
    removeFront(&ll);
    removeEnd(&ll);
    print(&ll);

    removeFront(&ll);
    print(&ll);

    removeFront(&ll);
    print(&ll);

    removeFront(&ll);
    
    addFront(&ll,10);
    
    print(&ll);
    
    return 0;
}//main()
