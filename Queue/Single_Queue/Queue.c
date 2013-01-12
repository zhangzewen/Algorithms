#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"
void queue_init(queue *myroot)
{
	myroot->base = NULL;
	myroot->tail = NULL:
}
void queue_put(queue *myroot,node *mynode)
{
	mynode->next = NULL;
	if(myroot->tail != NULL)
	{
		myroot->tail->next = mynode;
		myroot->tail = mynode;
	}
	if(myroot->base == NULL )
	{
		myroot->head = mynode;
	}
}

node *queue_get(queue * myroot)
{
	node *mynode;
	mynode = myroot->base;
	if(myroot->base != NULL)
			myroot->base = myroot->head->next;
	return mynode;
	
}
