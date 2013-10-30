#include "Min_Heap.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	struct heap* heap;
	heap = create();

	MinHeapInsert(heap, 6);
	MinHeapInsert(heap, 8);
	MinHeapInsert(heap, 10);
	MinHeapInsert(heap, 4);
	MinHeapInsert(heap, 7);
	MinHeapInsert(heap, 2);

	pop(heap);
	pop(heap);
	return 0;
}
