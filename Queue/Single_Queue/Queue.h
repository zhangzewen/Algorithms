#ifndef QUEUE_H__
#define QUEUE_H__

typedef struct node{
	struct node * next;
	int data;
}node;

typedef struct queue{
	node *base;
	node *tail;
}queue;

void queue_init(queue *myroot);
void queue_put(queue *myroot,node *mynode);

node *queue_get(queue * myroot);

#endif
