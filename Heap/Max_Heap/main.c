#include "Max_heap.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	struct heap *heap;
	heap = create();
	
	MaxHeapInsert(heap, 20);
	MaxHeapInsert(heap, 12);
	MaxHeapInsert(heap, 35);
	MaxHeapInsert(heap, 15);
	MaxHeapInsert(heap, 10);
	MaxHeapInsert(heap, 80);
	MaxHeapInsert(heap, 30);
	MaxHeapInsert(heap, 17);
	MaxHeapInsert(heap, 2);
	MaxHeapInsert(heap, 1);

	pop(heap);
	pop(heap);
}
