#ifndef _ALGORITHMS_HEAP_MAXHEAP_H_INCLUDED_
#define _ALGORITHMS_HEAP_MAXHEAP_H_INCLUDED_

#define HEAPINCREASE 256
#define HEAPMAX 1024
#if 0
struct node{
	void *data;
	int index;
};


struct Max_heap{
	int current;
	int max;
	int (*compare)(struct node *, struct node *);
	struct node *node;
};
#endif

struct heap{
	int max;
	int current;
	int *data;
};


struct heap* create();
int MaxHeapInsert(struct heap *heap, int num);
int pop(struct heap *heap);



#endif
