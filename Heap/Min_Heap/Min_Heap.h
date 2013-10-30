#ifndef __ALGORITHMS_HEAP_MIN_H_INCLUDED__
#define __ALGORITHMS_HEAP_MIN_H_INCLUDED__

#if 0
void MinHeapAddNumber(int *a, int n ,int num);
void MinHeapDeleteNumber(int *a, int n);
#endif
#define HEAPMAX 1024
#define HEAPINCREASE 256

struct heap{
	int current;
	int max;
	int *data;
};

struct heap* create();

int MinHeapInsert(struct heap* heap, int num);
int pop(struct heap* heap);

#endif
