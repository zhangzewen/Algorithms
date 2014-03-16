// for more ,see linux kernal list.h

#include "Queue.h"

void queue_init(queue *new)
{
	new->prev = new;
	new->next = new;
}

int queue_empty(queue *new)
{
	return (new->prev == new->next);
}

void queue_insert_head(queue *head, queue *new)
{
	new->next = head->next;
	new->next->prev = new;
	new->prev = head;
	head->next = new;
}

void queue_insert_tail(queue *head, queue *new)
{
	new->prev = head->prev;
	new->prev->next = new;
	new->next = head;
	head->prev = new;
}

void queue_remove(queue *node)
{
	node->next->prev = node->prev;
	node->prev->next = node->next;
	node->prev = NULL;
	node->next = NULL;
}

void queue_split(queue *head, queue *node, queue *new)
{
	new->prev = head->prev;
	new->prev->next = new;
	new->next = node;

	head->prev = node->prev;
	head->prev->next = head;
	node->prev = new;
}

void queue_add(queue *head, queue *new)
{
	head->prev->next = new->next;
	new->next->prev = head->prev;
	head->prev = new->prev;
	head->prev->next = head;
}

