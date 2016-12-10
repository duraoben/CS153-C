// CS 153 PROGRAM ASSIGNMENT #10
//
// Linked List Functions
//
// Ben Durao
//
// December 6, 2016

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct NODE
{
 struct NODE *link;
 int value;
};
typedef struct NODE Node;

/* inserts a new node at the first position in the LL */
Node *insertFirst( Node **ptrToHeadPtr, int val )
{
 Node *node = (Node *)malloc( sizeof( Node ) );
 node->value = val;
 node->link = *ptrToHeadPtr;
 *ptrToHeadPtr = node;
 return node;
}

/* visits each node in the LL in prints its value */
void traverse( Node *p )
{
 while ( p != NULL )
 {
 printf("%d ", p->value );
 p = p->link;
 }
 printf("\n");
}

/* frees the memory contained by the LL */
void freeList( Node *p )
{
 Node *temp;
 while ( p != NULL )
 {
 temp = p;
 p = p->link;
 free( temp );
 }
}

/* searchs for a specific target value in the LL */
Node *search( Node *p, int target)
{
 while ( p && target != p->value )
 {
 p = p->link;
 }
 return p;
}

/* Count the number of nodes in the LL */
int countNodes( Node *p )
{
 int count = 0;
 while ( p )
 {
 count++ ;
 p = p->link;
 }
 return count;
}

/* Count the number of times target value is in the LL */
int countTarget(Node *start, int target)
{
	int count = 0;
	while(start)
	{
		if(start->value == target)
			count++;
		start = start->link;
	}
	printf("Number of Targets: %d\n", count);
	return count;
}

/* Deletes the first node in the LL, if there is a single node make the LL empty*/
Node *deleteFirst(Node **ptrToHeadPtr)
{
	Node *temp = NULL;
	if(countNodes(*ptrToHeadPtr) == 1)
	{
		*ptrToHeadPtr = NULL;
	}
	if(*ptrToHeadPtr != NULL)
	{
		temp = *ptrToHeadPtr;
		*ptrToHeadPtr = temp->link;
		free( temp );
	}
	return *ptrToHeadPtr;
}

/* inserts a new node in the last postition of the LL */
Node *insertLast( Node **ptrToHeadPtr, int val )
{
	Node *node = (Node *)malloc( sizeof( Node ) );
	node->value = val;
	node->link = NULL;
	
	Node *temp = *ptrToHeadPtr;
	while ( temp && temp->link != NULL )
	{
		temp = temp->link;
	}
	if(!temp)
		*ptrToHeadPtr = node;
	else
		temp->link = node;
		
	return node;
}

/* Deletes the last node in the linked list, if LL is empty just return nothing*/
Node *deleteLast( Node **ptrToHeadPtr )
{
	Node *temp = NULL;
	if(countNodes(*ptrToHeadPtr) == 0)
		return temp;
	if(countNodes(*ptrToHeadPtr) == 1)
	{
		*ptrToHeadPtr = NULL;
	}
	else
	{
		temp = *ptrToHeadPtr;
		Node *last = temp;
		
		while (temp != NULL  && temp->link != NULL)
		{
			last = temp;
			temp = temp->link;
		}

			last->link = NULL;
			free(last->link);
			
	}
	return *ptrToHeadPtr;
}

int main()
{
 Node *HeadPtr = NULL;
 int j;
 for ( j=0; j<5; j++ )
	insertFirst( &HeadPtr, j );
 insertFirst( &HeadPtr, 4 );
 
 traverse( HeadPtr );
 
 countTarget(HeadPtr, 1);
 countTarget(HeadPtr, 4);
 countTarget(HeadPtr, 100);
 
 deleteFirst( &HeadPtr);
 traverse( HeadPtr );
 deleteFirst( &HeadPtr);
 traverse( HeadPtr );
 deleteFirst( &HeadPtr);
 traverse( HeadPtr );
 deleteFirst( &HeadPtr);
 traverse( HeadPtr );
 deleteFirst( &HeadPtr);
 traverse( HeadPtr );
 deleteFirst( &HeadPtr);
 traverse( HeadPtr );
 
 for ( j=0; j<5; j++ )
	insertFirst( &HeadPtr, j );
 traverse( HeadPtr);
 
 insertLast( &HeadPtr, 10);
 traverse( HeadPtr);
 
 deleteLast( &HeadPtr);
 traverse( HeadPtr);
 deleteLast( &HeadPtr);
 traverse( HeadPtr);
 deleteLast( &HeadPtr);
 traverse( HeadPtr);
 deleteLast( &HeadPtr);
 traverse( HeadPtr);
 deleteLast( &HeadPtr);
 traverse( HeadPtr);
 deleteLast( &HeadPtr);
 traverse( HeadPtr);
 deleteLast( &HeadPtr);
 traverse( HeadPtr);
 
 freeList( HeadPtr );

 getchar();
 return 1;
}