#ifndef _ALGORITHMS_HEAP_MAXHEAP_H_INCLUDED_
#define _ALGORITHMS_HEAP_MAXHEAP_H_INCLUDED_

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


int MaxHeapInsert(int *a, int num);
int MaxHeapDelete(int *a, int num);
#endif
