#ifndef _ALGORITHMS_QUEUE_H_INCLUDED__
#define _ALGORITHMS_QUEUE_H_INCLUDED__

// for more ,see linux kernal list.h

#include <stddef.h> /* offsetof()*/

typedef struct QUEUE queue;

struct QUEUE{
 	queue *prev;
	queue *next;
};


void queue_init(queue *new);

int queue_empty(queue *new);

void queue_insert_head(queue *head, queue *new);

void queue_insert_tail(queue *head, queue *new);

void queue_remove(queue *node);

void queue_split(queue *head, queue *q, queue *new);

void queue_add(queue *head, queue *new);

#define container_of(head, type, member) 			\
		(type*)((u_char *)head - offsetof(type, member))

#endif
